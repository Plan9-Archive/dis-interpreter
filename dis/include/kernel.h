extern	void		kclose(int);
extern	int		kdirfstat(int, Dir*);
extern	void		kerrstr(char*);
extern	void		kgerrstr(char*);
extern	int		kopen(char*, int);
extern	long		kread(int, void*, long);
extern	void		kwerrstr(char*, ...);
extern	long		kwrite(int, void*, long);

extern	char*	syserr(char*, char*, Prog*);

#pragma	varargck	argpos kwerrstr 1
