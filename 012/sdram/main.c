#include "s3c2440_soc.h"
#include "uart.h"
#include "init.h"
#include "led.h"

int main(void)
{	
	uart0_init();

	//sdram_init();
	if(sdram_test() == 0)
		ledtest();

	return 0;
}



