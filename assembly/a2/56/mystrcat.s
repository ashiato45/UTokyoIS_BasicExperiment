.text
	.align 2
	.globl mystrcat
mystrcat:
	addi %r12, %r3, 0 #%12 runs
.L1:
	lbzu %r11, 1(%r12) #%11 for char
	cmpwi %cr0, %r11, 0
	beq %cr0, .LBACK
	b .L1
.LBACK:
	subi %r12, %r12, 1
	subi %r4, %r4, 1
.LCONN:
	lbzu %r11, 1(%r4)
	stbu %r11, 1(%r12)
	cmpwi %cr0, %r11, 0
	bne %cr0, .LCONN
	blr
	
