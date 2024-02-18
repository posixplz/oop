.global _start
.data
mystr:.string "Hello World!\n"
.text
_start:
	mov $1,%rax
	mov $1,%rdi
	mov $mystr,%rsi
	mov $14,%rdx
	syscall

	mov $60,%rax
	mov $0,%rdi
	syscall
