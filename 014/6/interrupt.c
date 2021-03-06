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

void key_eint_irq(int irq)
{
	unsigned int val = EINTPEND;
	unsigned int val1 = GPFDAT;
	unsigned int val2 = GPGDAT;
	
	if(irq == 0)
	{
		if(val1 & (1<<0))
		{
			GPFDAT |= (1<<6);
		}
		else
		{
			GPFDAT &= ~(1<<6);
		}
	}
	else if(irq == 2)
	{
		if(val1 & (1<<2))
		{
			GPFDAT |= (1<<5);
		}
		else
		{
			GPFDAT &= ~(1<<5);
		}
	}
	else if(irq == 5)
	{
		if(val & (1<<11))
		{
			if(val2 & (1<<3))
			{
				GPFDAT |= (1<<4);
			}
			else
			{
				GPFDAT &= ~(1<<4);
			}
		}
		else if(val & (1<<19))
		{
			if(val2 & (1<<11))
			{
				GPFDAT |= ((1<<4) | (1<<5) | (1<<6));
			}
			else
			{
				GPFDAT &= ~((1<<4) | (1<<5) | (1<<6));			
			}
		}
	}

	EINTPEND = val;
}

void handle_irq_c(void)
{
	int bit = INTOFFSET;

	if(bit == 0 || bit == 2 || bit == 5)
	{
		key_eint_irq(bit);
	}
	SRCPND = (1<<bit);
	INTPND = (1<<bit);
}


