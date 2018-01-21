#include "s3c2440_soc.h"

//#define GPFCON (*((volatile unsigned int *)0x56000050))
//#define GPFDAT (*((volatile unsigned int *)0x56000054))

void delay(volatile int d)
{
	while(d--);
}

int main(void)
{
//	int val = 0;
//	int temp;
	int val1, val2;

	GPFCON &= ~((3<<8) | (3<<10) | (3<<12));	
	GPFCON |=  ((1<<8) | (1<<10) | (1<<12));

	GPFCON &= ~((3<<0) | (3<<4));
	GPFCON |=  ((0<<0) | (0<<4));

	GPGCON &= ~(3<<6);
	GPGCON |=  (0<<6);

	while (1)
	{
		val1 = GPFDAT;
		val2 = GPGDAT;

		if (val1 & (1<<0))
		{
			GPFDAT |= (1<<6);
		}
		else
		{
			GPFDAT &= ~(1<<6);
		}
		if (val1 & (1<<2))
		{
			GPFDAT |= (1<<5);
		}
		else
		{
			GPFDAT &= ~(1<<5);
		}
		if (val2 & (1<<3))
		{
			GPFDAT |= (1<<4);
		}
		else
		{
			GPFDAT &= ~(1<<4);
		}
			
		/*temp = ~val;
		temp &= 7;
		GPFDAT &= ~(7<<4);
		GPFDAT |= (temp<<4);
		delay(100000);
		val++;
		if (val == 8)
		{
			val = 0;
		}*/
	}

	return 0;
}
	

	





