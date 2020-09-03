#include <u.h>
#include <dynload.h>

extern void *acquire;
extern void *release;
extern void *malloc;
extern void *mallocz;
extern void *msize;
extern void *realloc;
extern void *dtype;
extern void *runtime;
extern void *print;
extern void *freeheap;
extern void *strcpy;

Dynsym dynsyms[] =
{
	{"acquire",		acquire},
	{"release",		release},
	{"malloc",		malloc},
	{"mallocz",		mallocz},
	{"msize",		msize},
	{"realloc",		realloc},
	{"dtype",		dtype},
	{"runtime",		runtime},
	{"print",		print},
	{"freeheap",		freeheap},
	{"strcpy",		strcpy},
	{0,		0},
};
