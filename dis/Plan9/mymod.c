#include "lib9.h"
#include "dat.h"
#include "fns.h"
#include "isa.h"
#include "interp.h"
#include "kernel.h"
#include "mathi.h"

#pragma hjdicks x4
void Hello_init(void*);
typedef struct F_Hello_init F_Hello_init;
struct F_Hello_init
{
	WORD	regs[NREG-1];
	WORD	noret;
	uchar	temps[12];
};
#pragma hjdicks off

void
Hello_init(void *fp)
{
	USED(fp);

	release();
	print("hello from a dynamically loaded module\n");
	acquire();
}

typedef struct{char *name; long sig; void (*fn)(void*); int size; int np; uchar map[16];} Runtab;
Runtab runtab[]={
	"init",0x9cd71c5e,Hello_init,32,0,{0},
	0
};

Module*
dismodinit(void)
{
	Module *m;
	Type *t;
	Runtab *r;

	m = mallocz(sizeof(Module), 1);
	if(m == nil)
		return nil;
	m->ref = 1;
	m->origmp = H;
	strcpy(m->name, "MyNativeMod");

	for(r=runtab; r->name; r++){
		t = dtype(freeheap, r->size, r->map, r->np);
		runtime(m, r->name, r->sig, r->fn, t);
	}
	return m;
}
