.text
	.align 2
	.globl fib
fib:
	stdu %r1, -128(%r1)
	mflr %r0
	std %r0, 144(%r1)

	std %r3, 80(%r1)
	cmpwi %cr0, %r3, 0
	beq %cr0, zero
	cmpwi %cr0, %r3, 1
	beq %cr0, one
many:
	subi %r3, %r3, 1
	bl fib
	std %r3, 88(%r1)
	ld %r3, 80(%r1)
	subi %r3, %r3, 2
	bl fib
	ld %r4, 88(%r1)
	add %r3, %r3, %r4
	bl end
zero:
	li %r3, 0
	bl end
one:
	li %r3, 1
	bl end
end:	
	ld %r0, 144(%r1)
	mtlr %r0
	addi %r1, %r1, 128
	blr
	