#include "s3c2440_soc.h"
#include "uart.h"
#include "init.h"
#include "led.h"
#include "interrupt.h"
#include "timer.h"

char g_char = 'A';
char g_char3 = 'a';
const char g_char2 = 'B';
int g_A = 0;
int g_B;


int main(void)
{	
	ledinit();
	interrupt_init();
	key_eint_init();
	timer_init();
	
	puts("\n\rg_A = ");
	printHex(g_A);
	puts("\n\r");

	while(1)
	{
#if 0
		puts("\n\rg_A = ");
		printHex(g_char);
		puts("\n\rg_A = ");
		printHex(g_char3);
		puts("\n\r");
#endif	
		putchar(g_char);
		g_char++;
		
		putchar(g_char3);
		g_char3++;
		delay(1000000);
		//printHex(TCNTO0);
	}
	
	return 0;
}



