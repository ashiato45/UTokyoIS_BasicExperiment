.text
	.align 2
	.globl mystrcmp2
mystrcmp2:
	stdu %r1, -128(%r1)
	mflr %r0
	std %r0, 144(%r1)
	std %r3, 56(%r1)
	std %r4, 64(%r1)
	bl mystrlen
	std %r3, 72(%r1)
	ld %r3, 64(%r1)
	bl mystrlen
	ld %r10, 72(%r1)
	cmpw %cr0, %r10, %r3
	blt %cr0, LT
	bgt %cr0, GT
	beq %cr0, EQ
	b return
LT:
	li %r3, -1
	b return
GT:
	li %r3, 1
	b return
EQ:
	li %r3, 0
	b return
return:
	ld %r0, 144(%r1)
	mtlr %r0
	addi %r1, %r1, 128
	blr
	