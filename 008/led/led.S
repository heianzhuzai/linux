.text

.global _start

_start:

	ldr r0, =0x56000050
	ldr r1, =0x500
	str r1, [r0]

	ldr r0, =0x56000054
	ldr r1, =0x0
	ldr r1, [r0]

halt:
	b halt


