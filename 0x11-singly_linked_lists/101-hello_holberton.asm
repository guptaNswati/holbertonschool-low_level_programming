;  assemble:	nasm -f elf64 101-hello_holberton.asm
;  link: 	gcc 101-hello_holberton.o
;  run:	        101-hello_holberton.asm
;  output is:	Hello Holberton, followed by a new line using printf

extern printf			; declare external function printf
section .data 			; data section
	fmt:	db "Hello, Holberton", 10, 0	; message with new line

section .text			; code section
	global main		; entry point

main:

	push	rbp		; set up stack frame
	mov 	rdi, fmt	; format for printf
	mov	rax, 0		; no xmm registers
	call	printf		; Call C function
	pop 	rbp		; restore stack
	mov 	rax, 0		; no error, return values
	ret			; return
