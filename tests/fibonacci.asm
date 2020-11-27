section .text

extern _alloc_mem, _dealloc_mem, _init_brks, _print_int, _input_int
extern _last_brk, _current_brk

global _start

_fib_0:
  mov r13, [_last_brk]
  push r13
  push 4
  call _alloc_mem
  pop r13
  pop r15
  mov r14, [_last_brk]
  pop rbx
  mov [r14+0], ebx
  push r15
  push r13

  mov ebx, [r14+0]
  cmp rbx, dword 1
  jle .LOCAL_1
  jmp .LOCAL_2

.LOCAL_1:
  mov r12d, [r14+0]
  call _dealloc_mem
  pop r15
  push r12
  push r15
  ret

.LOCAL_2:
  mov ebx, [r14+0]
  sub rbx, dword 1
  push rbx
  call _fib_0
  mov r14, [_last_brk]
  mov ecx, [r14+0]
  sub rcx, dword 2
  push rcx
  call _fib_0
  mov r14, [_last_brk]
  pop rcx
  pop rbx
  mov rbx, rbx
  add rbx, rcx
  mov r12, rbx
  call _dealloc_mem
  pop r15
  push r12
  push r15
  ret

_start:
  call _init_brks

  mov r13, [_last_brk]
  push r13
  push 8
  call _alloc_mem
  pop r13
  pop r15
  mov r14, [_last_brk]
  mov [r14+0], dword 0
  mov [r14+4], dword 0
  push r15
  push r13

  call _input_int
  mov r14, [_last_brk]
  pop rbx
  mov [r14+0], ebx
  mov ebx, [r14+0]
  push rbx
  call _fib_0
  mov r14, [_last_brk]
  pop rbx
  mov [r14+4], ebx
  mov ebx, [r14+4]
  push rbx
  call _print_int
  mov r14, [_last_brk]

.END_3:
  mov rax, 60
  xor rdi, rdi
  syscall
