.text
	.align 2
	.globl int2double
int2double:
	sldi %r11, %r3, 63
	sldi %r10, %r4, 52
	or %r9, %r11, %r10
	or %r9, %r9, %r5
	fcfid %r3, %r9
	blr