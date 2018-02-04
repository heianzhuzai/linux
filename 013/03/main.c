#include "s3c2440_soc.h"
#include "uart.h"
#include "init.h"
#include "led.h"

char g_char = 'A';
const char g_char2 = 'B';
int g_A = 0;
int g_B;


int main(void)
{	
	uart0_init();

	while(1)
	{
		putchar(g_char);
		g_char++;
		delay(1000000);
	}
	
	return 0;
}



