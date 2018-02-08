#include "s3c2440_soc.h"

void delay(volatile int d)
{
	while(d--);
}

void ledinit(void)
{
	GPFCON &= ~((3<<12) | (3<<10) | (3<<8));
	GPFCON |=  ((1<<12) | (1<<10) | (1<<8));
}


