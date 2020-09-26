section .text
global _ft_strlen

_ft_strlen:
	xor	rax, rax				; rax = 0

.loop:
	cmp byte[rdi + rax], 0		; if (s[rax] == 0)
	je .end						; jump if equal
	inc rax						; s++
	jmp .loop

.end:				
	ret							; return (rax)