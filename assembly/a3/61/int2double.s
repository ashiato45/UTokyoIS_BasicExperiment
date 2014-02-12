.text
	.align 2
	.globl int2double
int2double:
	stdu %r1, -128(%r1)
	mflr %r0
	std %r0, 144(%r1)
	
	sldi %r11, %r3, 63
	sldi %r10, %r4, 52
	or %r9, %r11, %r10
	or %r8, %r9, %r5
	std %r8, 80(%r1)
	lfd %f1, 80(%r1)
	
	ld %r0, 144(%r1)
	mtlr %r0
	addi %r1, %r1, 128
	blr

