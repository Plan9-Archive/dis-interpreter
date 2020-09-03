#include <u.h>
#include <libc.h>

enum
{
	NAMELEN = 32,
	ERRLEN = ERRMAX,
};

typedef ulong size_t;

typedef struct Jmp Jmp;
struct Jmp
{
	jmp_buf jb;
};

#define _ossetjmp(jmp)	setjmp((jmp)->jb)
extern void **Xup;
#define up (*(Proc**)Xup)

#include "386.h"
