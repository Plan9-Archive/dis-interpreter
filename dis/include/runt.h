#pragma hjdicks x4
typedef struct Sys_Exception Sys_Exception;
typedef struct Sys_Qid Sys_Qid;
typedef struct Sys_Dir Sys_Dir;
typedef struct Sys_FD Sys_FD;
typedef struct Sys_Connection Sys_Connection;
typedef struct Sys_FileIO Sys_FileIO;
struct Sys_Exception
{
	String*	name;
	String*	mod;
	WORD	pc;
};
#define Sys_Exception_size 12
#define Sys_Exception_map {0xc0,}
struct Sys_Qid
{
	WORD	path;
	WORD	vers;
};
#define Sys_Qid_size 8
#define Sys_Qid_map {0}
struct Sys_Dir
{
	String*	name;
	String*	uid;
	String*	gid;
	Sys_Qid	qid;
	WORD	mode;
	WORD	atime;
	WORD	mtime;
	WORD	length;
	WORD	dtype;
	WORD	dev;
};
#define Sys_Dir_size 44
#define Sys_Dir_map {0xe0,}
struct Sys_FD
{
	WORD	fd;
};
#define Sys_FD_size 4
#define Sys_FD_map {0}
struct Sys_Connection
{
	Sys_FD*	dfd;
	Sys_FD*	cfd;
	String*	dir;
};
#define Sys_Connection_size 12
#define Sys_Connection_map {0xe0,}
typedef struct{ Array* t0; String* t1; } Sys_Rread;
#define Sys_Rread_size 8
#define Sys_Rread_map {0xc0,}
typedef struct{ WORD t0; String* t1; } Sys_Rwrite;
#define Sys_Rwrite_size 8
#define Sys_Rwrite_map {0x40,}
struct Sys_FileIO
{
	Channel*	read;
	Channel*	write;
};
typedef struct{ WORD t0; WORD t1; WORD t2; Channel* t3; } Sys_FileIO_read;
#define Sys_FileIO_read_size 16
#define Sys_FileIO_read_map {0x10,}
typedef struct{ WORD t0; Array* t1; WORD t2; Channel* t3; } Sys_FileIO_write;
#define Sys_FileIO_write_size 16
#define Sys_FileIO_write_map {0x50,}
#define Sys_FileIO_size 8
#define Sys_FileIO_map {0xc0,}
void Sys_announce(void*);
typedef struct F_Sys_announce F_Sys_announce;
struct F_Sys_announce
{
	WORD	regs[NREG-1];
	struct{ WORD t0; Sys_Connection t1; }*	ret;
	uchar	temps[12];
	String*	addr;
};
void Sys_aprint(void*);
typedef struct F_Sys_aprint F_Sys_aprint;
struct F_Sys_aprint
{
	WORD	regs[NREG-1];
	Array**	ret;
	uchar	temps[12];
	String*	s;
	WORD	vargs;
};
void Sys_bind(void*);
typedef struct F_Sys_bind F_Sys_bind;
struct F_Sys_bind
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	String*	s;
	String*	on;
	WORD	flags;
};
void Sys_byte2char(void*);
typedef struct F_Sys_byte2char F_Sys_byte2char;
struct F_Sys_byte2char
{
	WORD	regs[NREG-1];
	struct{ WORD t0; WORD t1; WORD t2; }*	ret;
	uchar	temps[12];
	Array*	buf;
	WORD	n;
};
void Sys_char2byte(void*);
typedef struct F_Sys_char2byte F_Sys_char2byte;
struct F_Sys_char2byte
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	WORD	c;
	Array*	buf;
	WORD	n;
};
void Sys_chdir(void*);
typedef struct F_Sys_chdir F_Sys_chdir;
struct F_Sys_chdir
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	String*	path;
};
void Sys_create(void*);
typedef struct F_Sys_create F_Sys_create;
struct F_Sys_create
{
	WORD	regs[NREG-1];
	Sys_FD**	ret;
	uchar	temps[12];
	String*	s;
	WORD	mode;
	WORD	perm;
};
void Sys_dial(void*);
typedef struct F_Sys_dial F_Sys_dial;
struct F_Sys_dial
{
	WORD	regs[NREG-1];
	struct{ WORD t0; Sys_Connection t1; }*	ret;
	uchar	temps[12];
	String*	addr;
	String*	local;
};
void Sys_dirread(void*);
typedef struct F_Sys_dirread F_Sys_dirread;
struct F_Sys_dirread
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	Sys_FD*	fd;
	Array*	dir;
};
void Sys_dup(void*);
typedef struct F_Sys_dup F_Sys_dup;
struct F_Sys_dup
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	WORD	old;
	WORD	new;
};
void Sys_export(void*);
typedef struct F_Sys_export F_Sys_export;
struct F_Sys_export
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	Sys_FD*	c;
	WORD	flag;
};
void Sys_exportdir(void*);
typedef struct F_Sys_exportdir F_Sys_exportdir;
struct F_Sys_exportdir
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	Sys_FD*	c;
	String*	dir;
	WORD	flag;
};
void Sys_fildes(void*);
typedef struct F_Sys_fildes F_Sys_fildes;
struct F_Sys_fildes
{
	WORD	regs[NREG-1];
	Sys_FD**	ret;
	uchar	temps[12];
	WORD	fd;
};
void Sys_file2chan(void*);
typedef struct F_Sys_file2chan F_Sys_file2chan;
struct F_Sys_file2chan
{
	WORD	regs[NREG-1];
	Sys_FileIO**	ret;
	uchar	temps[12];
	String*	dir;
	String*	file;
};
void Sys_fprint(void*);
typedef struct F_Sys_fprint F_Sys_fprint;
struct F_Sys_fprint
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	Sys_FD*	fd;
	String*	s;
	WORD	vargs;
};
void Sys_fstat(void*);
typedef struct F_Sys_fstat F_Sys_fstat;
struct F_Sys_fstat
{
	WORD	regs[NREG-1];
	struct{ WORD t0; Sys_Dir t1; }*	ret;
	uchar	temps[12];
	Sys_FD*	fd;
};
void Sys_fwstat(void*);
typedef struct F_Sys_fwstat F_Sys_fwstat;
struct F_Sys_fwstat
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	Sys_FD*	fd;
	Sys_Dir	d;
};
void Sys_listen(void*);
typedef struct F_Sys_listen F_Sys_listen;
struct F_Sys_listen
{
	WORD	regs[NREG-1];
	struct{ WORD t0; Sys_Connection t1; }*	ret;
	uchar	temps[12];
	Sys_Connection	c;
};
void Sys_millisec(void*);
typedef struct F_Sys_millisec F_Sys_millisec;
struct F_Sys_millisec
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
};
void Sys_mount(void*);
typedef struct F_Sys_mount F_Sys_mount;
struct F_Sys_mount
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	Sys_FD*	fd;
	String*	on;
	WORD	flags;
	String*	spec;
};
void Sys_open(void*);
typedef struct F_Sys_open F_Sys_open;
struct F_Sys_open
{
	WORD	regs[NREG-1];
	Sys_FD**	ret;
	uchar	temps[12];
	String*	s;
	WORD	mode;
};
void Sys_pctl(void*);
typedef struct F_Sys_pctl F_Sys_pctl;
struct F_Sys_pctl
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	WORD	flags;
	List*	movefd;
};
void Sys_pipe(void*);
typedef struct F_Sys_pipe F_Sys_pipe;
struct F_Sys_pipe
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	Array*	fds;
};
void Sys_print(void*);
typedef struct F_Sys_print F_Sys_print;
struct F_Sys_print
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	String*	s;
	WORD	vargs;
};
void Sys_raise(void*);
typedef struct F_Sys_raise F_Sys_raise;
struct F_Sys_raise
{
	WORD	regs[NREG-1];
	WORD	noret;
	uchar	temps[12];
	String*	s;
};
void Sys_read(void*);
typedef struct F_Sys_read F_Sys_read;
struct F_Sys_read
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	Sys_FD*	fd;
	Array*	buf;
	WORD	n;
};
void Sys_remove(void*);
typedef struct F_Sys_remove F_Sys_remove;
struct F_Sys_remove
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	String*	s;
};
void Sys_rescue(void*);
typedef struct F_Sys_rescue F_Sys_rescue;
struct F_Sys_rescue
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	String*	s;
	Sys_Exception*	e;
};
void Sys_rescued(void*);
typedef struct F_Sys_rescued F_Sys_rescued;
struct F_Sys_rescued
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	WORD	flag;
	String*	s;
};
void Sys_seek(void*);
typedef struct F_Sys_seek F_Sys_seek;
struct F_Sys_seek
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	Sys_FD*	fd;
	WORD	off;
	WORD	start;
};
void Sys_sleep(void*);
typedef struct F_Sys_sleep F_Sys_sleep;
struct F_Sys_sleep
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	WORD	period;
};
void Sys_sprint(void*);
typedef struct F_Sys_sprint F_Sys_sprint;
struct F_Sys_sprint
{
	WORD	regs[NREG-1];
	String**	ret;
	uchar	temps[12];
	String*	s;
	WORD	vargs;
};
void Sys_stat(void*);
typedef struct F_Sys_stat F_Sys_stat;
struct F_Sys_stat
{
	WORD	regs[NREG-1];
	struct{ WORD t0; Sys_Dir t1; }*	ret;
	uchar	temps[12];
	String*	s;
};
void Sys_stream(void*);
typedef struct F_Sys_stream F_Sys_stream;
struct F_Sys_stream
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	Sys_FD*	src;
	Sys_FD*	dst;
	WORD	bufsiz;
};
void Sys_tokenize(void*);
typedef struct F_Sys_tokenize F_Sys_tokenize;
struct F_Sys_tokenize
{
	WORD	regs[NREG-1];
	struct{ WORD t0; List* t1; }*	ret;
	uchar	temps[12];
	String*	s;
	String*	delim;
};
void Sys_unmount(void*);
typedef struct F_Sys_unmount F_Sys_unmount;
struct F_Sys_unmount
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	String*	s1;
	String*	s2;
};
void Sys_unrescue(void*);
typedef struct F_Sys_unrescue F_Sys_unrescue;
struct F_Sys_unrescue
{
	WORD	regs[NREG-1];
	WORD	noret;
	uchar	temps[12];
};
void Sys_utfbytes(void*);
typedef struct F_Sys_utfbytes F_Sys_utfbytes;
struct F_Sys_utfbytes
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	Array*	buf;
	WORD	n;
};
void Sys_write(void*);
typedef struct F_Sys_write F_Sys_write;
struct F_Sys_write
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	Sys_FD*	fd;
	Array*	buf;
	WORD	n;
};
void Sys_wstat(void*);
typedef struct F_Sys_wstat F_Sys_wstat;
struct F_Sys_wstat
{
	WORD	regs[NREG-1];
	WORD*	ret;
	uchar	temps[12];
	String*	s;
	Sys_Dir	d;
};
#define Sys_PATH "$Sys"
#define Sys_HANDLER 0
#define Sys_EXCEPTION 1
#define Sys_ACTIVE 2
#define Sys_RAISE 3
#define Sys_EXIT 4
#define Sys_ONCE 5
#define Sys_ATOMICIO 8192
#define Sys_NAMELEN 28
#define Sys_SEEKSTART 0
#define Sys_SEEKRELA 1
#define Sys_SEEKEND 2
#define Sys_ERRLEN 64
#define Sys_WAITLEN 64
#define Sys_OREAD 0
#define Sys_OWRITE 1
#define Sys_ORDWR 2
#define Sys_OTRUNC 16
#define Sys_ORCLOSE 64
#define Sys_CHDIR -2147483648
#define Sys_DMDIR -2147483648
#define Sys_DMAPPEND 1073741824
#define Sys_DMEXCL 536870912
#define Sys_DMAUTH 134217728
#define Sys_MREPL 0
#define Sys_MBEFORE 1
#define Sys_MAFTER 2
#define Sys_MCREATE 4
#define Sys_NEWFD 1
#define Sys_FORKFD 2
#define Sys_NEWNS 4
#define Sys_FORKNS 8
#define Sys_NEWPGRP 16
#define Sys_NODEVS 32
#define Sys_NEWENV 64
#define Sys_FORKENV 128
#define Sys_EXPWAIT 0
#define Sys_EXPASYNC 1
#define Sys_UTFmax 3
#define Sys_UTFerror 128
#pragma hjdicks off
