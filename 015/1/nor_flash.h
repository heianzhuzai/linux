#ifndef _NOR_FLASH_H
#define _NOR_FLASH_H

void nor_flash_test(void);
void do_scan_nor_flash(void);
void do_erase_nor_flash(void);
void do_write_nor_flash(void);
void do_read_nor_flash(void);

void nor_write_word(unsigned int base, unsigned int offset, unsigned int val);
void nor_cmd(unsigned int offset, unsigned int cmd);
unsigned int nor_read_word(unsigned int base, unsigned int offset);
unsigned int nor_dat(unsigned int offset);


#endif



