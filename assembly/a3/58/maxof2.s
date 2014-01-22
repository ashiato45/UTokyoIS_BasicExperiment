.text
	.align 2
	.globl maxof2

maxof2:
	cmpw %cr0, %r3, %r4
	ble %cr0, .LYLARGE
	blr
.LYLARGE:
	addi %r3, %r4, 0
	blr

	
	
