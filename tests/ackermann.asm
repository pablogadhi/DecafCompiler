section .text

extern _alloc_mem, _dealloc_mem, _init_brks, _print_int, _input_int
extern _last_brk, _current_brk

global _start

_ackermann_0:
  mov r13, [_last_brk]
  push r13
  push 8
  call _alloc_mem
  pop r13
  pop r15
  mov r14, [_last_brk]
  pop rbx
  mov [r14+4], ebx
  pop rbx
  mov [r14+0], ebx
  push r15
  push r13

  mov ebx, [r14+0]
  cmp rbx, dword 0
  je .LOCAL_1
  jmp .LOCAL_2

.LOCAL_1:
  mov ebx, [r14+4]
  add rbx, dword 1
  mov r12, rbx
  call _dealloc_mem
  pop r15
  push r12
  push r15
  ret

.LOCAL_2:
  mov ebx, [r14+0]
  cmp rbx, dword 0
  jg .LOCAL_4
  jmp .LOCAL_6

.LOCAL_4:
  mov ebx, [r14+4]
  cmp rbx, dword 0
  je .LOCAL_5
  jmp .LOCAL_6

.LOCAL_5:
  mov ebx, [r14+0]
  sub rbx, dword 1
  push rbx
  push dword 1
  call _ackermann_0
  mov r14, [_last_brk]
  pop rbx
  mov r12, rbx
  call _dealloc_mem
  pop r15
  push r12
  push r15
  ret

.LOCAL_6:
  mov ebx, [r14+0]
  cmp rbx, dword 0
  jg .LOCAL_8
  jmp .LOCAL_10

.LOCAL_8:
  mov ebx, [r14+4]
  cmp rbx, dword 0
  jg .LOCAL_9
  jmp .LOCAL_10

.LOCAL_9:
  mov ebx, [r14+0]
  sub rbx, dword 1
  push rbx
  mov ebx, [r14+0]
  push rbx
  mov ebx, [r14+4]
  sub rbx, dword 1
  push rbx
  call _ackermann_0
  mov r14, [_last_brk]
  pop rbx
  push rbx
  call _ackermann_0
  mov r14, [_last_brk]
  pop rbx
  mov r12, rbx
  call _dealloc_mem
  pop r15
  push r12
  push r15
  ret

.LOCAL_10:

_start:
  call _init_brks

  mov r13, [_last_brk]
  push r13
  push 12
  call _alloc_mem
  pop r13
  pop r15
  mov r14, [_last_brk]
  mov [r14+0], dword 0
  mov [r14+4], dword 0
  mov [r14+8], dword 0
  push r15
  push r13

  call _input_int
  mov r14, [_last_brk]
  pop rbx
  mov [r14+4], ebx
  call _input_int
  mov r14, [_last_brk]
  pop rbx
  mov [r14+8], ebx
  mov ebx, [r14+4]
  push rbx
  mov ebx, [r14+8]
  push rbx
  call _ackermann_0
  mov r14, [_last_brk]
  pop rbx
  mov [r14+0], ebx
  mov ebx, [r14+0]
  push rbx
  call _print_int
  mov r14, [_last_brk]

.END_11:
  mov rax, 60
  xor rdi, rdi
  syscall
