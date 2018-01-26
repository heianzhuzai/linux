#define GPFCON (*((unsigned int *)0x56000050))
#define GPFDAT (*((unsigned int *)0x56000054))

void delay (volatile int d)
{
	while (d--);
}

int main(void)
{
	int val =0;
	int temp;

	GPFCON &= ~((3<<12) | (3<<10) | (3<<8));
	GPFCON |=  ((1<<12) | (1<<10) | (1<<8));

	while (1)
	{
		temp = ~val;
		temp &= 0x07;

		GPFDAT &= ~(7<<4);
		GPFDAT |= (temp<<4);
		delay(100000);
		val++;
		if (val == 8)
		{
			val = 0;
		}
	}
	
}





