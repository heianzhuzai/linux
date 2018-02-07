#include "s3c2440_soc.h"


void interrupt_init(void)
{
	INTMSK &= ~((1<<0) | (1<<2) | (1<<5));
}

void key_eint_init(void)
{
	GPFCON &= ~((3<<0) | (3<<4));
	GPFCON |=  ((2<<0) | (2<<4));

	GPGCON &= ~((3<<6) | (3<<22));
	GPGCON |=  ((2<<6) | (2<<22));

	EXTINT0 |= ((7<<0) | (7<<8));
	EXTINT1 |= (7<<12);
	EXTINT2 |= (7<<12);

	EINTMASK &= ~((1<<11) | (1<<19));
}

void handle_irq_c(void)
{
	
}