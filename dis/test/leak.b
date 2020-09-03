implement Leak;

include "sys.m";
	sys: Sys;

Leak: module
{
	init: fn();
};

f(a: array of byte)
{
}

init()
{
	for(;;){
		a := array[1000] of byte;
		f(a);
	}
}
