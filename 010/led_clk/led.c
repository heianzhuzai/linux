#include "s3c2440_soc.h"


void delay(volatile int d)
{
	while(d--);
}

int main(void)
{
	

	GPFCON &= ~((3<<8)|(3<<10)|(3<<12));
	GPFCON |= (1<<8)|(1<<10)|(1<<12);

	while(1)
	{
		GPFDAT &= ~(7<<4);
		delay(1000000);
		GPFDAT |= (7<<4);
		delay(1000000);
	}
	
	return 0;
}




