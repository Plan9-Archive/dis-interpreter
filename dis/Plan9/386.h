/*
 * FPenv.status
 */
enum
{
	FPINIT,
	FPACTIVE,
	FPINACTIVE,
};

typedef struct FPenv		FPenv;
typedef struct FPU		FPU;

/*
 * This structure must agree with FPsave and FPrestore asm routines
 */
struct FPenv
{
	ushort	control;
	ushort	r1;
	ushort	status;
	ushort	r2;
	ushort	tag;
	ushort	r3;
	ulong	pc;
	ushort	selector;
	ushort	r4;
	ulong	operand;
	ushort	oselector;
	ushort	r5;
};

/*
 * This structure must agree with fpsave and fprestore asm routines
 */
struct	FPU
{
	FPenv	env;
	uchar	regs[80];	/* floating point registers */
};

