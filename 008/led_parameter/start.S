.text
.global _start

_start:

	ldr sp, =4096

	mov r0, #4
	bl led

	ldr r0, =100000
	bl delay

	mov r0, #5
	bl led

halt:
	b halt
	


