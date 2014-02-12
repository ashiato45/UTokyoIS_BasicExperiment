.text
	.align 2
	.globl maxof3
maxof3:
	stdu %r1, -128(%r1)
	mflr %r0
	std %r0, 144(%r1)
	std %r5, 112(%r1)
	bl maxof2
	ld %r5, 112(%r1)
	addi %r4, %r5, 0
	bl maxof2
	ld %r0, 144(%r1)
	mtlr %r0
	addi %r1, %r1, 128
	blr
	