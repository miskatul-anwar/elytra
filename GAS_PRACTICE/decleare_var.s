.section .data 
x: .quad 42

.section .text 
.globl _start

_start:
  movq x, %rax 
  movq $60, %rax 
  xorq %rdi, %rdi
  syscall
