#include "lib9.h"
#include "dat.h"
#include "fns.h"
#include "error.h"
#include "interp.h"
#include "isa.h"
#include "runt.h"
#include "kernel.h"

/* just what is needed for exception.c */
WORD
modstatus(REG *r, char *ptr, int len)
{
	Inst *PC;
	Frame *f;

	if(r->M->m->name[0] == '$') {
		f = (Frame*)r->FP;
		snprint(ptr, len, "%s[%s]", f->mr->m->name, r->M->m->name);
		if(f->mr->compiled)
			return (WORD)f->lr;
		return f->lr - f->mr->prog;
	}
	memmove(ptr, r->M->m->name, len);
	if(r->M->compiled)
		return (WORD)r->PC;
	PC = r->PC;
	/* should really check for blocked states */
	if(PC > r->M->prog)
		PC--;
	return PC - r->M->prog;
}

