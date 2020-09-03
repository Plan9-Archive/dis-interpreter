#include "lib9.h"
#include "dat.h"
#include "fns.h"
#include "isa.h"
#include "interp.h"
#include "kernel.h"
#include "mathi.h"
#include <dynload.h>

Module*
parsenativemod(char *path)
{
	Dynimage *im;
	Module *m;

	im = dynload(path);
	if(im == nil){
		rerrstr(up->env->error, sizeof up->env->error);
		return nil;
	}

	path = strdup(path);
	if(path == nil){
		dynunload(im);
		return nil;
	}

	m = (*(Module*(*)(void))im->entry)();
	if(m == nil){
		dynunload(im);
		free(path);
		return nil;
	}
	m->native = im;
	return m;
}
