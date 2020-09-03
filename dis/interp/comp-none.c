#include "lib9.h"
#include "isa.h"
#include "interp.h"
#include "raise.h"

	void	(*comvec)(void);

int
compile(Module *m, int size, Modlink *ml)
{
	USED(m);
	USED(size);
	USED(ml);
	return 0;	/* compiler not implemented */
}
