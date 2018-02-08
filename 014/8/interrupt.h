#ifndef _INTERRUPT_H
#define _INTERRUPT_H

typedef void(*irq_func)(int irq);
irq_func irq_array[32];

void interrupt_init(void);
void key_eint_init(void);
void handle_irq_c(void);
void key_eint_irq(int irq);
void register_irq(int irq, irq_func fp);

#endif








