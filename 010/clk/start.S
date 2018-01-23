
.text
.global _start

_start:

	ldr r0, =0x53000000
	ldr r1, =0
	str r1, [r0]

	ldr r0, =0x4C000000
	ldr r1, =0xFFFFFFFF
	str r1, [r0]
	
	ldr r0, =0x4C000014
	ldr r1, =0x05
	str r1, [r0]
	
	mrc p15,0,r0,c1,c0,0
	orr r0,r0,#0xC0000000
	mrc p15,0,r0,c1,c0,0
	
	ldr r0, =0x4C000004
	ldr r1, =(92<<12)|(1<<4)|(1<<0)
	str r1, [r0]

	/* 设置内存: sp 栈 */
	ldr sp, =4096  /* nand启动 */
//	ldr sp, =0x40000000+4096  /* nor启动 */

	mov r0, #4
	bl led_on

	ldr r0, =1000000
	bl delay

	ldr r0, =1000000
	bl delay

	mov r0, #5
	bl led_on

halt:
	b halt
	
