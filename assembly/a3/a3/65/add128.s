.text
	.align 2
	.globl add128
add128:
	stdu %r1, -128(%r1)
	mflr %r0
	std %r0, 144(%r1)

	ld %r11, 0(%r3) 	
	ld %r10, 8(%r3)
	ld %r9, 0(%r4)
	ld %r8, 8(%r4)
	addc %r3, %r10, %r8
	adde %r4, %r11, %r9
	std %r4, 0(%r5)
	std %r3, 8(%r5)
end:	
	ld %r0, 144(%r1)
	mtlr %r0
	addi %r1, %r1, 128
	blr
	