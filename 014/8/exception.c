#include "uart.h"

void printException(unsigned int cpsr, char *str)
{
	puts("Exception! cpsr = ");
	printHex(cpsr);
	puts(" ");
	puts("\n\r");
}




