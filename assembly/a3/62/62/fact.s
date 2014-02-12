.text
	.align 2
	.globl fact
fact:
	stdu %r1, -128(%r1)
	mflr %r0
	std %r0, 144(%r1)

	std %r3, 80(%r1)
	cmpwi %cr0, %r3, 0
	ble %cr0, one
many:
	subi %r3, %r3, 1
	bl fact
	ld %r4, 80(%r1)
	mullw %r3, %r3, %r4
	bl end
one:
	li %r3, 1
	bl end
end:	
	ld %r0, 144(%r1)
	mtlr %r0
	addi %r1, %r1, 128
	blr