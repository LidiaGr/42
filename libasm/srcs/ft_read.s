section .text
extern  ___error
global _ft_read

_ft_read:
    mov rax, 0x02000003         ; syscall for read (rdi, rsi, rdx)
    syscall
    jc .error                   ; jump if condition is met (an error in write)
    ret

.error:
    push rax                    ; push rax to stack to save errno value
    call ___error               ; to get errno adress 
    pop rdx                     ; pop a value from the stack to rdx (errno value)
    mov [rax], edx              ; move errno value to errno adress
    mov rax, -1                 ; rax = -1
    ret
    