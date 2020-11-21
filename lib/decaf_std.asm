section .text
global _print_char
global _init_brks
global _alloc_mem
global _dealloc_mem
global _last_brk
global _current_brk

_print_char:
  pop r15
  pop rdx
  pop rsi
  push r15
  mov	rax, 1
  mov	rdi, 1
  syscall     ; print a message
  ret

_init_brks:
  mov	rax, 12 ; sys_brk
  xor	rdi, rdi
  syscall
  mov [_last_brk], rax
  mov [_current_brk], rax
  ret

_alloc_mem:
  pop r15
  pop rax
  push r15
  add rax, [_current_brk]
  mov	rdi, rax
  mov	rax, 12 ; sys_brk
  syscall

  ; T0DO Handle allocation error
  ; cmp	rax, 0
  ; jl	_exit     ; exit, if error

  mov rbx, [_current_brk]
  mov [_last_brk], rbx
  mov [_current_brk], rax
  ret

_dealloc_mem:
  pop r15
  pop rax
  push r15

  mov rdi, [_last_brk]
  mov [_last_brk], rax

  mov rax, 12
  syscall

  mov [_current_brk], rax

  ret

section .data
_last_brk dq 0
_current_brk dq 0