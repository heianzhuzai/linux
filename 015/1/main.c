#include "s3c2440_soc.h"
#include "uart.h"
#include "init.h"
#include "led.h"
#include "interrupt.h"
#include "timer.h"
#include "nor_flash.h"

char g_char = 'A';
char g_char3 = 'a';
const char g_char2 = 'B';
int g_A = 0;
int g_B;


int main(void)
{	
	ledinit();
	//interrupt_init();
	key_eint_init();
	timer_init();
	
	puts("\n\rg_A = ");
	printHex(g_A);
	puts("\n\r");

	nor_flash_test();
	
	return 0;
}



