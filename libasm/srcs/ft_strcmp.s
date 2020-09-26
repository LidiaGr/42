section .text
global _ft_strcmp

_ft_strcmp:
	xor rax, rax			; rax = 0

.loop:
	mov al, byte[rdi]		; al = *s1
	mov dl, byte[rsi]		; dl = *s2
	sub rax, rdx			; rax = *s1 - *s2
	jnz .end				; jump if nonzero
	cmp dl, 0				; if (dl == 0)
	je	.end				; jump if equal
	inc rdi					; s1++;
	inc rsi					; s2++;
	jmp .loop

.end:
	ret						; return (rax)
