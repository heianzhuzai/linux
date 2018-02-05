.text
.global _start

_start:

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
	mov r0, #0
	ldr r1, =_start
	ldr r2, =__bss_start
	sub r2, r2, r1

	bl copy2sdram

/* clean bss */
	ldr r0, = __bss_start
	ldr r1, = _end

	bl clean_bss
	
	//bl main
	ldr pc, =main

halt:
	b halt

