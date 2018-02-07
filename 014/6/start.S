.text
.global _start

_start:

	b reset					// vector 0 : reset
	ldr pc, und_addr		// vector 4 : und
	ldr pc, swi_addr		// vector 8 : swi
	b halt					// vector 0x0C : prefetch abort
	b halt					// vector 0x10 : data abort
	b halt					// vector 0x14 : reserved
	ldr pc, irq_addr		// vector 0x18 : IRQ
	b halt					// vector 0x1C : FIQ

und_addr:
	.word do_und

swi_addr:
	.word do_swi

irq_addr:
	.word do_irq

do_und:
	ldr sp, = 0x34000000

	stmdb sp!, {r0-r12, lr}

	mrs r0, cpsr
	ldr r1, =und_string
	bl printException
	ldmia sp!, {r0-r12, pc}^

und_string:
	.string "undefined instruction exception"

.align 4

do_swi:
	ldr sp, = 0x33E00000

	stmdb sp!, {r0-r12, lr}

	mov r4, lr

	mrs r0, cpsr
	ldr r1, =swi_string
	bl printException

	sub r0, r4, #4
	bl printSWIVal
	
	ldmia sp!, {r0-r12, pc}^

swi_string:
	.string "swi exception"

.align 4

do_irq:
	ldr sp, = 0x33d00000

	sub lr, lr, #4
	stmdb sp!, {r0-r12, lr}

	mrs r0, cpsr

	bl handle_irq_c
	
	ldmia sp!, {r0-r12, pc}^

und_string:
	.string "undefined instruction exception"

.align 4
		
reset:
	ldr r0, =0x53000000
	ldr r1, =0x0
	str r1, [r0]

	ldr r0, =0x4C000000
	ldr r1, =0xFFFFFFFF
	str r1, [r0]

	ldr r0, =0x4C000014
	ldr r1, =0x05
	str r1, [r0]

	mrc  p15,0,r0,c1,c0,0 
	orr  r0,r0,#0xC0000000 
	mcr  p15,0,r0,c1,c0,0 

	ldr r0, =0x4C000004
	ldr r1, =((92<<12) | (1<<4) | (1<<0))
	str r1, [r0]

	mov r1, #0
	ldr r0, [r1]
	str r1, [r1]
	ldr r2, [r1]
	cmp r1, r2
	ldr sp, =0x40000000+4096
	moveq sp, #4096
	streq r0, [r1]
	
	bl sdram_init
	//bl sdram_init2

	/* relocate */

	bl copy2sdram

	/* clean bss */
	bl clean_bss

	mrs r0, cpsr
	bic r0, r0, #0xF  		// 修改M4-M0为0b10000，进入usr模式
	bic r0, r0, #(1<<7)  	// 清除I位，使能中断
	msr cpsr, r0

	ldr sp, =0x33F00000

	ldr pc, =sdram
	
sdram:
	bl uart0_init

	bl print1
und_code:
	.word 0xdeadc0de
		
	bl print2

	swi 0x123
	
	//bl main
	ldr pc, =main

halt:
	b halt

