section .text	; code section
	global main	; entry point

main:
	mov	ebx, 1	; write
	mov 	eax, 4	; stdout
	mov 	ecx, message	; message address
	mov 	edx, 17	; message length
	int 	0x80	; interrupt 80 hex, call kernel

	mov 	ebx, 0	; exit code
	xor 	eax, 1	; output to kernel
	int 	0x80

section .data 	; data section
	message:	db 'Hello, Holberton', 0x0A 	; message with new line
