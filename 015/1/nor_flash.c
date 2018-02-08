#include "my_printf.h"
#include "string_utils.h"

#define NOR_FLASH_BASE 0

void nor_write_word(unsigned int base, unsigned int offset, unsigned int val)
{
	volatile unsigned short *p = (volatile unsigned short *)(base + (offset << 1));
	*p = val;
}
void nor_cmd(unsigned int offset, unsigned int cmd)
{
	nor_write_word(NOR_FLASH_BASE, offset, cmd);
}

unsigned int nor_read_word(unsigned int base, unsigned int offset)
{
	volatile unsigned short *p = (volatile unsigned short *)(base + (offset << 1));
	return *p;
}

unsigned int nor_dat(unsigned int offset)
{
	nor_read_word(NOR_FLASH_BASE, offset);
}

void do_scan_nor_flash(void)
{
	char str[4];

	nor_cmd(0x55, 0x98);  // enter the cfi mode

	str[0] = nor_dat(0x10);
	str[2] = nor_dat(0x11);
	str[3] = nor_dat(0x12);
	str[4] = '\0';
	
	printf("str = %s\n\r", str);
}

void do_erase_nor_flash(void)
{

}

void do_write_nor_flash(void)
{

}

void do_read_nor_flash(void)
{

}

void nor_flash_test(void)
{
	char c;

	while(1)
	{
		printf("[s] Scan nor flash\n\r");
		printf("[e] Erase nor flash\n\r");
		printf("[w] Write not flash\n\r");
		printf("[r] Read nor flash\n\r");
		printf("[q] Quit\n\r");
		printf("Enter selection: ");

		c = getchar();
		printf("%c\n\r", c);

		switch (c)
		{
			case 'q':
			case 'Q':
				return;
				break;

			case 's':
			case 'S':
				do_scan_nor_flash();
				break;

			case 'e':
			case 'E':
				do_erase_nor_flash();
				break;

			case 'w':
			case 'W':
				do_write_nor_flash();
				break;
				
			case 'r':
			case 'R':
				do_read_nor_flash();
				break;

			default:
				break;
		}
	}
}



