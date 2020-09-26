section .text
global _ft_strcpy

_ft_strcpy:
	mov rax, rdi			; rax = s1

.loop:
	mov dl, byte[rsi]		; dl = *s2 
	mov byte[rdi], dl		; *s1 = dl
	cmp dl, 0				; if (dl == 0)
	je .end					; jump if equal
	inc rdi					; s1++;
	inc rsi					; s2++;
	jmp .loop

.end:
	ret						; return (rax)