.text
	.align 2
	.globl mystrlen
mystrlen:
	li %r4, 0
.L1:/home05/9156125825/is/59/main.c
	lbzu %r5, 1(%r3)
	cmpwi %cr0, %r5, 0
	beq %cr0, .LBREAK
	addi %r4, %r4, 1
	b .L1
.LBREAK:
	addi %r3, %r4, 0
	blr
	
