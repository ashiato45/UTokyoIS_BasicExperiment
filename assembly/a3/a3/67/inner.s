.text
	.align 2
	.globl inner
inner:
	stdu %r1, -128(%r1)
	mflr %r0
	std %r0, 144(%r1)

	lfd %f13, 0(%r3) 	
	lfd %f12, 8(%r3)
	lfd %f11, 0(%r4)
	lfd %f10, 8(%r4)
	fmul %f13, %f13, %f11
	fmadd %f1, %f12, %f10, %f13
end:	
	ld %r0, 144(%r1)
	mtlr %r0
	addi %r1, %r1, 128
	blr
	