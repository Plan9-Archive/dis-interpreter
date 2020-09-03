#include "lib9.h"
#include "dat.h"
#include "fns.h"
#include "isa.h"
#include "interp.h"
#include "kernel.h"
#include "mathi.h"

Module*
parsenativemod(char *path)
{
	USED(path);
	kwerrstr("dynamic loading not supported");
	return nil;
}

