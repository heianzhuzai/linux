
void delay (volatile int d)
{
	while (d--);
}


int main (void)
{
	unsigned int *pGPFCON = (unsigned int *)0x56000050;
	unsigned int *pGPFDAT = (unsigned int *)0x56000054;

	int val=0;
	int temp;

	*pGPFCON &= ~((3<<12) | (3<<10) | (3<<8));
	*pGPFCON |=  ((1<<12) | (1<<10) | (1<<8));
	

	while(1)
	{
		temp = ~val;
		temp &= 0x07;
		*pGPFDAT &= ~(7 << 4);
		*pGPFDAT |=  (temp << 4);
		delay(100000);
		val++;
		if (val == 8)
		{
			val = 0;
		}
	}

	return 0;
}



