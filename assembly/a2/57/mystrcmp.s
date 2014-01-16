.text
	.align 2
	.globl mystrcmp
mystrcmp:
	lbzu %r12, 1(%r3)
	lbzu %r11, 1(%r4)
	cmpw %cr0, %r12, %r11
	blt %cr0, .L1
	bgt %cr0, .L3
	cmpwi %cr0, %r12, 0
	beq %cr0, .L2
	b mystrcmp
.L1:
	li %r3, -1
	blr
.L2:
	li %r3, 0
	blr
.L3:
	li %r3, 1
	blr
