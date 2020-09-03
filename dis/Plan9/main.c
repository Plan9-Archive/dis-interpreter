#include	"lib9.h"
#include	"dat.h"
#include	"fns.h"
#include	"error.h"
#include	"interp.h"
#include	"kernel.h"

int cflag;
Procs procs;

void
modinit(void)
{
	sysmodinit();
}

void
emuinit(void *imod)
{
	kproc("main", disinit, imod, 0);

	for(;;)
		ospause(); 
}

void
usage(void)
{
	fprint(2, "usage: dis [-c] file.dis\n");
	exits("usage");
}

int
main(int argc, char **argv)
{
	ARGBEGIN{
	default:
		usage();
	case 'c':
		cflag = 1;
		break;
	}ARGEND

	if(argc < 1)
		usage();

	libinit(argv[0]);
	cleanexit(0);
	return 0;
}
