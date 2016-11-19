global main	; entry point

section	.text
main:
	mov rax, 1	; write
	mov rdi, 1	; stdout
	mov rsi, message	; message address
	mov rdx, 17	; message length
	syscall

	mov rax, 60	; system exit
	xor rdi, 0	; return 0
	syscall

section .data
	message: db 'Hello, Holberton', 0x0A 	; message with new line
