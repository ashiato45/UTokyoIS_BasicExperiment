.text
	.align 2
	.globl mystrcmp
mystrcmp:
	stb %r12, 1(%3)
	stb %r11, 1(%4)
	cmpw %cr0,%r12, %11
	bne %cr0, .LEND
	cmpwi %cr0, %r12, 0
	beq %cr0, .LEQ
	b mystrcmp
.LEND
	sub %r3, %r12, %r11
	blr
