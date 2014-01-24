.text
	.align 2
	.globl maxof3
maxof3:
	mflr %r0
	bl maxof2
	mtlr %r0
	blr
	