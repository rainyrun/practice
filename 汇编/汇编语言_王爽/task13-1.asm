;��д����װint 7ch�ж����̣�����Ϊ��ʾһ����0�������ַ������ж����̰�װ��0:200��
;������(dh)=�кţ�(dl)=�кţ�(cl)=��ɫ��ds:siָ���ַ����׵�ַ
assume cs:code
stack segment
	dw 8 dup (0)
stack ends
code segment
;���ж����̰�װ��0:200��
start:	mov ax,cs
	mov ds,ax
	mov si,offset showstr

	mov ax,0
	mov es,ax
	mov di,200h

	mov cx,offset showstr - offset showend
	cld
	rep movsb
;�����ж�������
	mov ax,0
	mov es,ax
	mov word ptr es:[4*7ch],200h
	mov word ptr es:[4*7ch+2],0

	mov ax,4c00h
	int 21h
;�ж�����
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
	mov dl,cl;ת����ɫ

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