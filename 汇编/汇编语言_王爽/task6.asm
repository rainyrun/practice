assume cs:codesg, ss:stacksg, ds:datasg

stacksg segment
dw 0,0,0,0,0,0,0,0
stacksg ends

datasg segment
db '1. display      '
db '2. brows        '
db '3. replace      '
db '4. modify       '
datasg ends

codesg segment
start:	mov ax, datasg
	mov ds, ax
	mov bx, 0
	mov cx, 4
s0:	push cx
	mov si, 0
	mov cx, 4
s:	mov ax, [bx+si+3]
	and al, 11011111B
	mov [bx+si+3], ax
	inc si
	loop s
	add bx, 16
	pop cx
	loop s0
	mov ax, 4c00H
	int 21H
codesg ends
end start