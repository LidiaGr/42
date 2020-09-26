section .text
extern _ft_strlen
extern _ft_strcpy
extern _malloc
global _ft_strdup

_ft_strdup:
	xor rax, rax        ; rax = 0

.count:
	push rdi            ; save str at the top of stack
	call _ft_strlen     ; ft_strlen(rdi), result into rax
	mov rdi, rax        ; rdi = ft_strlen(rdi)
	inc rdi             ; rdi++
	call _malloc        ; result into rax
	cmp rax, 0          ; if (rax == 0)
	je .end             ; jump if equal
	pop rsi             ; take str from stack and move to rsi
	mov rdi, rax        ; malloced memory pointer into rdi 
	call _ft_strcpy     ; to rdi from rsi
	ret

.end:
	ret