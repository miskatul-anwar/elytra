.section .data 
x: .quad 42
.section .text
.globl _start 
_start:
  movq x, %rax
  
  cmpq $1, %rax
  je inc_x

  cmpq $3, %rax
  je dec_x

  movq $2, %rax
  jmp store_x


inc_x:
  addq $1, %rax
  jmp store_x

dec_x:
  subq $1, %rax
  jmp store_x

store_x:
  movq %rax, x

exit_syscall:
  movq $60, %rax
  xorq %rdi, %rdi
  syscall

