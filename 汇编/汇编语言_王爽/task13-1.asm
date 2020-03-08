;编写并安装int 7ch中断例程，功能为显示一个用0结束的字符串，中断例程安装在0:200处
;参数：(dh)=行号，(dl)=列号，(cl)=颜色，ds:si指向字符串首地址
assume cs:code
stack segment
	dw 8 dup (0)
stack ends
code segment
;将中断例程安装在0:200处
start:	mov ax,cs
	mov ds,ax
	mov si,offset showstr

	mov ax,0
	mov es,ax
	mov di,200h

	mov cx,offset showstr - offset showend
	cld
	rep movsb
;设置中断向量表
	mov ax,0
	mov es,ax
	mov word ptr es:[4*7ch],200h
	mov word ptr es:[4*7ch+2],0

	mov ax,4c00h
	int 21h
;中断例程
showstr:	push es
	push di
	push si
	push bx
	push dx
	push cx

	mov ax,08b00h
	mov es,ax
	mov al,dh
	mov dh,160
	mul dh
	mov bx,ax
	mov dh,0
	add dx,dx
	mov di,dx
	mov dl,cl;转移颜色

s:	mov ch,0
	mov cl,[si]
	jcxz showret
	mov es:[bx+di],cl
	mov es:[bx+di+1],dl
	inc si
	add di,2
	loop s
showret:	pop cx
	pop dx
	pop bx
	pop si
	pop di
	pop es
	iret
showend:	nop
code ends
end start