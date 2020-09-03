implement Primes;

include "sys.m";
	sys: Sys;

Primes: module
{
	init: fn();
};

GOAL: con 1000;

n: int;

sieve(c: chan of int)
{
	p := <-c;
	if(p >= GOAL)
		exit;
	sys->print("%d ", p);
	if(n++%8 == 7)
		sys->print("\n");
	nc := chan of int;
	spawn sieve(nc);
	for(;;){
		i := <-c;
		if(i >= GOAL){
			nc <-= i;
			exit;
		}
		if(i%p)
			nc <-= i;
	}
}

init()
{
	sys = load Sys Sys->PATH;

	n = 0;
	c := chan of int;
	spawn sieve(c);
	for(i:=2; i<=GOAL; i++)
		c <-= i;
}
