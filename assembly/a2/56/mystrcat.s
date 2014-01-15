.text
	.align 2
	.globl mystrcat
mystrcat:
	addi %12, %3, 0 //%12 runs
.L1:
	lbzu %r11, 1(%r12) //%11 for char
	cmpwi %cr0, %r11, 0
	beq %cr0, .LCONN
	b .L1
.LCONN:
	lbzu %r11, 1(%r4)
	stb %r11, 1(%12)
	cmpwi %cr0, %r11, 0
	bne 0, .LCONN
	blr
	
