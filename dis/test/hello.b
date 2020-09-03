implement Hello;

include "sys.m";

Hello: module
{
	init: fn();
};

init()
{
	sys := load Sys Sys->PATH;
	sys->print("hello, world\n");
}
