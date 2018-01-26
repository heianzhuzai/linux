
void delay(volatile int d)
{
	while (d--);
}

int led(int p)
{
	unsigned int *pGPFCON = (unsigned int *)0x56000050;
	unsigned int *pGPFDAT = (unsigned int *)0x56000054;

	if (p == 4)
	{
		*pGPFCON = 0x100;
	}
	else if (p == 5)
	{
		*pGPFCON = 0x400;
	}

	*pGPFDAT = 0x0;
	return 0;
}



