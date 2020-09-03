#include "lib9.h"
#include "dat.h"
#include "fns.h"
#include "isa.h"
#include "interp.h"
#include "kernel.h"

void **Xup;

enum
{
	KSTACK = 32*1024,
};

extern void tramp(char*, void(*)(void*), void*);

void
cleanexit(int x)
{
	USED(x);
//	killrefresh();
	postnote(PNGROUP, getpid(), "interrupt");
	exits("interrupt");
}

void
kclose(int fd)
{
	close(fd);
}

int
kdirfstat(int fd, Dir *d)
{
	Dir *dd;

	if((dd = dirfstat(fd)) == nil){
		rerrstr(up->env->error, sizeof up->env->error);
		return -1;
	}

	dd->name = "dis";
	dd->uid = "dis";
	dd->gid = "dis";
	dd->muid = "dis";
	*d = *dd;
	free(dd);
	return 0;
}
	
int
kopen(char *path, int mode)
{
	int fd;

	fd = open(path, mode);
	if(fd < 0)
		rerrstr(up->env->error, sizeof up->env->error);
	return fd;
}

int
kproc(char *name, void (*func)(void*), void *arg, int flags)
{
	int pid;
	Proc *p;

	USED(flags);

// print("%d: kproc %s\n", ++kpn, name);
	p = newproc();
	p->kstack = mallocz(KSTACK, 0);
	if(p == nil || p->kstack == nil)
		panic("kproc: no memory");

/*
	p->env->uid = up->env->uid;
	p->env->gid = up->env->gid;
	memmove(p->env->user, up->env->user, NAMELEN);
*/

	strcpy(p->text, name);

	p->func = func;
	p->arg = arg;

	lock(&procs.l);
	if(procs.tail != nil) {
		p->prev = procs.tail;
		procs.tail->next = p;
	}
	else {
		procs.head = p;
		p->prev = nil;
	}
	procs.tail = p;
	unlock(&procs.l);

	/*
	 * switch back to the unshared stack to do the fork
	 * only the parent returns from kproc
	 */
	up->kid = p;
	up->kidsp = p->kstack;
	pid = setjmp(up->sharestack.jb);
	if(!pid)
		longjmp(up->privstack.jb, 1);
	return pid;
}

void
krendez(Proc *p, ulong val)
{
	rendezvous((ulong)p, val);
}

long
kread(int fd, void *data, long count)
{
	count = read(fd, data, count);
	if(count < 0)
		rerrstr(up->env->error, sizeof up->env->error);
	return count;
}

long
kwrite(int fd, void *data, long count)
{
	count = write(fd, data, count);
	if(count < 0)
		rerrstr(up->env->error, sizeof up->env->error);
	return count;
}

static void
traphandler(void *reg, char *msg)
{
	int intwait = up->intwait;
	up->intwait = 0;
	/* Ignore pipe writes from devcmd */
	if(strstr(msg, "write on closed pipe") != nil)
		noted(NCONT);

/*
	if (sflag) {
		if (intwait && strcmp(msg, Eintr) == 0)
			noted(NCONT);
		else
			noted(NDFLT);
	}
*/
	if(intwait == 0)
		disfault(reg, msg);
	noted(NCONT);
}

void
libinit(char *imod)
{
	char *sp;
	Proc *xup, *p;
	int pid;

	rfork(RFNAMEG|RFREND|RFNOTEG);

//	if(sflag == 0)
		notify(traphandler);

	Xup = &xup;

	/*
	 * dummy up a up and stack so the first proc
	 * calls emuinit after setting up his private jmp_buf
	 */
	p = newproc();
	p->kstack = mallocz(KSTACK, 0);
	if(p == nil || p->kstack == nil)
		panic("libinit: no memory");
	sp = p->kstack;
	p->func = emuinit;
	p->arg = imod;

	/*
	 * set up a stack for forking kids on separate stacks.
	 * longjmp back here from kproc.
	 */
	while(setjmp(p->privstack.jb)){
		p = up->kid;
		sp = up->kidsp;
		switch(pid = rfork(RFPROC|RFMEM)){
		case 0:
			/*
			 * send the kid around the loop to set up his private jmp_buf
			 */
			break;
		default:
			/*
			 * parent just returns to his shared stack in kproc
			 */
			longjmp(up->sharestack.jb, pid);
			panic("longjmp failed");
		}
	}

	/*
	 * you get here only once per Proc
	 * go to the shared memory stack
	 */
	up = p;
	up->sigid = getpid();
	tramp(sp+KSTACK, up->func, up->arg);
	panic("tramp returned");
}

void
oshostintr(Proc *p)
{
	postnote(PNPROC, p->sigid, "interrupt");
}

void
oslongjmp(void *ureg, Jmp *jmp, int val)
{
	if(ureg)
		notejmp(ureg, jmp->jb, val);
	else
		longjmp(jmp->jb, val);
}

void
ospause(void)
{
	for(;;)
		sleep(1000000);
}

void
osyield(void)
{
	sleep(0);
}

