#include "s3c2440_soc.h"
#include "init.h"

void sdram_init(void)
{
	BWSCON   = 0x22000000;
	BANKCON6 = 0x18001;
	BANKCON7 = 0x18001;
	REFRESH  = 0x8404F5;
	BANKSIZE = 0xb1;
	MRSRB6 = 0x20;
	MRSRB7 = 0x20;	
}

void sdram_init2(void)
{
	unsigned int i = 0;
	unsigned int arr[] = {
		0x22000000,
		0x00000700,
		0x00000700,
		0x00000700,
		0x00000700,
		0x00000700,
		0x00000700,
		0x18001,
		0x18001,
		0x8404f5,
		0xb1,
		0x20,		
		0x20,		
	};
	volatile unsigned int *p = (volatile unsigned int *)0x48000000;

	for (i=0; i<13; i++)
	{
		*p = arr[i];
		p++;
	}
}

int sdram_test(void)
{
	volatile unsigned char *p = (volatile unsigned char *)0x30000000;
	int i;

	for(i=0; i<1000; i++)
		p[i] = 0x55;
	for(i=0; i<1000; i++)
		if(p[i] != 0x55)
			return -1;
	return 0;
}

void copy2sdram(void)
{	

	extern int __code_start, __bss_start;

	volatile unsigned int *dest = (volatile unsigned int *)&__code_start;
	volatile unsigned int *end = (volatile unsigned int *)&__bss_start;
	volatile unsigned int *src = (volatile unsigned int *)0;
	
	unsigned int i = 0;

	while(dest<end)
	{
		*dest++ = *src++;
	}
}

void clean_bss(void)
{
	extern int _end, __bss_start;

	volatile unsigned int *start = (volatile unsigned int *)&__bss_start;
	volatile unsigned int *end = (volatile unsigned int *)&_end;
	
	while(start <= end)
	{
		*start++ = 0;
	}
}






