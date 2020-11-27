section .text
global _print_char
global _init_brks
global _alloc_mem
global _dealloc_mem
global _print_int
global _input_int
global _last_brk
global _current_brk

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

_print_int:
  xor rsi, rsi
  xor rdx, rdx
  xor rax, rax
  xor rdi, rdi
  ; print new line
  mov rsi, _endl
  mov rdx, 1
  mov rax, 1
  mov rdi, 1
  syscall

  pop r15
  pop rax
  push r15

  mov [_int_str_size], dword 0
  mov rcx, _int_str
  add rcx, 9
  xor rdx, rdx

.go_on:
  mov rbx, dword 10
  div rbx
  add rdx, '0'
  mov byte [rcx], dl
  dec rcx
  inc dword [_int_str_size]
  xor rdx, rdx
  cmp rax, 0
  jne .go_on

  inc rcx
  mov rsi, rcx
  mov rdx, [_int_str_size]
  mov rax, 1  ; print
  mov rdi, 1
  syscall

  ; print new line
  mov rsi, _endl
  mov rdx, 1
  mov rax, 1
  mov rdi, 1
  syscall

  ret

_input_int:
  mov [_input_res], dword 0

  mov rax, 0
  mov rdi, 0
  mov rsi, _input_buff
  mov rdx, 128
  syscall

  mov rbx, _input_buff
.convert:
  xor rcx, rcx

  mov cl, byte [rbx]
  cmp cl, byte 10
  je .finish

  mov edx, dword 10
  mov eax, dword [_input_res]
  mul rdx

  sub cl, '0'
  add eax, ecx
  mov [_input_res], eax
  inc rbx
  jmp .convert

.finish:
  pop r15
  mov eax, [_input_res]
  push rax
  push r15
  ret

section .data
_last_brk dq 0
_current_brk dq 0
_endl db 10

section .bss
_input_buff resb 128
_input_res resd 1
_int_str resb 10
_int_str_size resd 1