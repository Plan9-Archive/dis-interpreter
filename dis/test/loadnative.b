implement LoadNative;
include "sys.m";
include "hello.m";

sys: Sys;

LoadNative: module
{
	init: fn();
};

init()
{
	hello := load Hello "hello.out";
	hello->init();
	exit;
}
