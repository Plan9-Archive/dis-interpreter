
typedef struct Proc		Proc;
typedef struct Procs		Procs;
typedef struct Prog		Prog;
typedef struct Osenv		Osenv;
typedef struct Rendez	Rendez;

struct Osenv
{
	char		error[ERRMAX];
	FPU		fpu;
	Rendez	*rend;
};

struct Procs
{
	Lock	l;
	Proc*	head;
	Proc*	tail;
};

struct Rendez
{
	Lock		l;
	Proc		*p;
};

enum
{	/* Proc.type */
	Unknown = 0xdeadbabe,
	IdleGC	= 0x16,
	Interp	= 0x17
};
struct Proc
{
	void		*arg;
	Osenv	defenv;
	Osenv	*env;
	Jmp		estack[32];
	void		(*func)(void*);
	int		intwait;
	Prog		*iprog;
	Proc		*kid;
	char		*kidsp;
	char		*kstack;
	int		nerr;
	Proc		*next;
	Proc		*prev;
	Jmp		privstack;
	Prog		*prog;
	Proc		*qnext;
	Rendez	*r;
	Jmp		sharestack;
	int		sigid;
	Rendez	sleep;
	int		swipend;
	int		syscall;
	Lock		sysio;
	char		text[NAMELEN];
	int		type;
};

extern Procs	procs;
