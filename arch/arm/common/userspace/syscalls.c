#include "stdlib.h"

size_t __syscall(size_t arg1, size_t arg2, size_t arg3, size_t arg4,
		size_t arg5, size_t arg6) {

	register long r0 asm ("r0") = arg1;
	register long r1 asm ("r1") = arg2;
	register long r2 asm ("r2") = arg3;
	register long r3 asm ("r3") = arg4;
	register long r4 asm ("r4") = arg5;
	register long r5 asm ("r5") = arg6;
	asm("svc 0\n" : "=r"(r0) : "r"(r0), "r"(r1), "r"(r2), "r"(r3), "r"(r4), "r"(r5));
	return arg1;
}


void abort()
{
  exit(-127);
}

void raise()
{
  exit(-127);
}

void __write()
{
  exit(-127);
}

void stderr()
{
  exit(-127);
}

void fflush()
{
  exit(-127);
}

void __fprintf_chk()
{
  exit(-127);
}

void __aeabi_unwind_cpp_pr0()
{
  exit(-127);
}
