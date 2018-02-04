#include "s3c2440_soc.h"
#include "uart.h"

char g_Char = 'A';

int main(void)
{
	uart0_init();
	
	while(1)
	{
		putchar(g_Char);
		delay(1000000);
		g_Char++;
		
	}

	return 0;
}



