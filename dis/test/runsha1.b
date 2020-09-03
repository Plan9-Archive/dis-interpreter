implement Cmd;

include "sys.m";
include "sha1.m";

Cmd: module
{
	init: fn();
};

init()
{
	sys := load Sys Sys->PATH;
	sha1 := load Sha1 Sha1->PATH;

	zero := array[1024*1024] of byte;
	for(i:=0; i<32; i++)
		sha1->sha1(zero);
}
