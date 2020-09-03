extern	void		addprog(Proc*);
extern	void		cleanexit(int);
extern	void		disfault(void*, char*);
extern	void		disinit(void*);
extern	void		emuinit(void*);
extern	void		error(char*);
extern	void		FPinit(void);
extern	void		FPrestore(FPU*);
extern	void		FPsave(FPU*);
extern	int		kproc(char*, void(*)(void*), void*, int);
extern	void		krendez(Proc*, ulong);
extern	void		ksleep(Rendez*, int(*)(void*), void*);
extern	void		kwakeup(Rendez*);
extern	void		libinit(char*);
extern	int		memlow(void);
extern	Proc*	newproc(void);
extern	void		nexterror(void);
extern	void		osenter(void);
extern	void		oshostintr(Proc*);
extern	void		osleave(void);
extern	void		oslongjmp(void*, Jmp*, int);
extern	void		ospause(void);
extern	void		osyield(void);
extern	void		panic(char*, ...);
extern	void		poperror(void);
extern	void		swiproc(Proc*);
extern	Jmp*		_waserror(void);

#define	waserror()	_ossetjmp(_waserror())

#pragma	varargck	argpos panic 1
