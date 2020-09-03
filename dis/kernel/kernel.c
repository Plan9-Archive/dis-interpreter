#include "lib9.h"
#include "dat.h"
#include "fns.h"
#include "interp.h"
#include "kernel.h"

void
error(char *s)
{
	kwerrstr(s);
	nexterror();
}

void
kgerrstr(char *s)
{
	strecpy(s, s+ERRMAX, up->env->error);
}

void
kwerrstr(char *fmt, ...)
{
	va_list arg;

	va_start(arg, fmt);
	vsnprint(up->env->error, ERRMAX, fmt, arg);
	va_end(arg);
}

void
kerrstr(char *s)
{
	char t[ERRMAX];

	memmove(t, s, ERRMAX);
	memmove(s, up->env->error, ERRMAX);
	memmove(up->env->error, t, ERRMAX);
}

Proc*
newproc(void)
{
	Proc *p;

	p = malloc(sizeof(Proc));
	if(p == nil)
		return nil;

	p->type = Unknown;
	p->env = &p->defenv;
	addprog(p);

	return p;
}

void
nexterror(void)
{
	if(up->nerr-- <= 0)
		panic("error stack underflow");
	oslongjmp(nil, &up->estack[up->nerr], 1);
}

void
panic(char *fmt, ...)
{
	char buf[1024];
	va_list arg;

	va_start(arg, fmt);
	vsnprint(buf, sizeof buf, fmt, arg);
	va_end(arg);

notify(0);
	fprint(2, "panic: %s\n", buf);
	abort();
}

void
poperror(void)
{
	if(up->nerr-- <= 0)
		panic("error stack underflow");
}

char*
syserr(char *s, char *es, Prog *p)
{
	Osenv *o;

	o = p->osenv;
	strncpy(s, o->error, es - s);
	return s + strlen(o->error);
}

Jmp*
_waserror(void)
{
	if(up->nerr++ > nelem(up->estack))
		panic("error stack overflow");
	return &up->estack[up->nerr-1];
}
