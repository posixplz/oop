section .data
	mystr db "Hello World!",0x0a

section .text
	global _start

_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, mystr
	mov rdx, 14
	syscall

	mov rax, 60
	mov rdi, 0
	syscall
