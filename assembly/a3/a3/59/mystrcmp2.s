.text
	.align 2
	.globl mystrcmp2
mystrcmp2:
	stdu %r1, -128(%r1)
	mflr %r0
	std %r0, 144(%r1) //144=128+16
	bl mystrlen
	addi %r10, %r3, 0 //%r10 is the length of arg0
	addi %r3, %r4, 0
	bl mystrlen //%r3 is the length of arg1
	cmpwi %cr0, %r10, %r3
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