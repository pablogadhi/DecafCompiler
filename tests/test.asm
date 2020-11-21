; ----------------------------------------------------------------------------------------
; Manual fibonacci implementation
; ----------------------------------------------------------------------------------------


section	.text
  global _start

  extern _alloc_mem, _dealloc_mem, _init_brks
  extern _last_brk, _current_brk

_fib_0:
  ; store previous base addr on the stack
  mov r13, [_last_brk]
  push r13
  ; allocate some memory
  push 4
  call _alloc_mem
  ; retrieve previous base addr to put it again
  ; on the bottom of the stack (for this code segment)
  pop r13

  ; retrieve the call addr
  pop r15
  ; retrieve and store params
  mov r14, [_last_brk]

  pop rax
  mov [r14+0], eax

  ; store the call addr again
  push r15

  ; store the previous base addr to deallocate
  ; the memory later
  push r13

  ; do everything
.func_start:
  mov rax, [r14+0]
  cmp rax, 1
  jle .local_1
  jmp .local_2

.local_1:
  mov rax, [r14+0]
  mov r12, rax

  call _dealloc_mem
  pop r15
  push r12
  push r15
  ret

.local_2:
  mov rax, [r14+0]
  sub rax, 1
  push rax
  call _fib_0
  mov r14, [_last_brk]

  mov rbx, [r14+0]
  sub rbx, 2
  push rbx
  call _fib_0
  mov r14, [_last_brk]
  pop rbx
  pop rax

  add rax, rbx
  mov r12, rax

  call _dealloc_mem
  pop r15
  push r12
  push r15
  ret

_start:
  call _init_brks

  mov r13, [_last_brk]
  push r13
  push 9
  call _alloc_mem

  mov r14, [_last_brk]
  mov [r14+0], byte 'a'
  mov [r14+1], dword 9

  mov ebx, [r14+1]
  push rbx
  call _fib_0
  pop rax
.test
  jmp _exit

  ; xor rcx, rcx
  ; mov ecx, [rax+1]
  ; push rcx
  ; push 1
  ; call _print_char

  ; mov rcx, _last_brk+1
  ; push msg
  ; push len
  ; call _print_char

_exit:
  mov	rax, 60
  xor	rdi, rdi
  syscall

section	.data