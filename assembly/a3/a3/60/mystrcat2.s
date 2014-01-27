.text
	.align 2
	.globl mystrcat2
mystrcat2:
	stdu %r1, -128(%r1)
	mflr %r0
	std %r0, 144(%r1)
	std %r3, 80(%r1)
	std %r4, 88(%r1)
	bl mystrcat
	ld %r4, 88(%r1)
	ld %r5, 80(%r1)
	add %r5, %r5, %r3
lconn:	
	lbzu %r11, 1(%r4)
	stbu %r11, 1(%r5)
	cmpwi %cr0, %r11, 0
	bne %cr0, lconn
end:	
	ld %r3, 80(%r1)
	ld %r0, 144(%r1)
	mtlr %r0
	addi %r1, %r1, 128
	blr