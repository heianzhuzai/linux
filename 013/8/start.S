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
	mov r1, #0
	ldr r2, =_start
	ldr r3, =__bss_start

cpy:
	ldr r4, [r1]
	str r4, [r2]
	add r1, r1, #4
	add r2, r2, #4
	cmp r2, r3
	ble cpy

/* clean bss */
	ldr r1, = __bss_start
	ldr r2, = _end
	mov r3, #0
clean:
	str r3, [r1]
	add r1, r1, #4
	cmp r1, r2
	ble clean
	
	//bl main
	ldr pc, =main

halt:
	b halt

