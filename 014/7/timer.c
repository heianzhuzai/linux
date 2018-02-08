#include "s3c2440_soc.h"


void timer_init(void)
{
	TCFG0 = 99;
	TCFG1 &= ~0xF;
	TCFG1 |= 3;

	TCNTB0 = 15625;
	TCON |= (1<<1);

	TCON &= ~(1<<1);
	TCON |= ((1<<0) | (1<<3));
}

void timer_irq(void)
{
	static int cnt = 0;
	int temp;

	cnt++;

	temp = ~cnt;
	temp &= 7;
	GPFDAT &= ~(7<<4);
	GPFDAT |= (temp<<4);
}


