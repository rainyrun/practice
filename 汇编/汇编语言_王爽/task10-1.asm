;�ӳ���show_str����
;���ܣ���ָ����λ�ã���ָ������ɫ����ʾһ����0�������ַ�����
;������(dh)=�кţ�ȡֵ��Χ0~24����(dl)=�кţ�ȡֵ��Χ0~79����(cl)=��ɫ��ds:siָ���ַ������׵�ַ
;���أ���
;Ӧ�þ���������Ļ��8��3�У�����ɫ��ʾdata���е��ַ�����
assume cs:code, ds:data;, ss:stack
data segment 
db 'Welcome to masm!',0
data ends

;stack segment
;db 2 dup (0)
;stack ends

code segment
start:	mov dh,8
	mov dl,3
	mov cl,2
	mov ax,data
	mov ds,ax
	mov si,0
	call show_str

	mov ax,4c00H
	int 21h
show_str:	;push dx
	;push cx
;�Դ��ַ���㣬bx����У�di����У�es��Ŷε�ַ��bx+di���ƫ�Ƶ�ַ
	mov ax,0b800H
	mov es,ax
	mov al,160
	mul dh
	mov bx,ax;��
	mov dh,0
	add dx,dx
	mov di,dx;��
;ѭ�������ڴ������ת�Ƶ��Դ��ϣ�cxΪ��ת�Ĵ�������ɫ����al��
	mov al,cl
	mov ch,0
show:	mov cl,[si]
	jcxz ok
	mov es:[bx+di],cl
	mov es:[bx+di+1],al
	add di,2
	inc si
	loop show
ok:	;pop cx
	;pop dx
	ret
code ends
end start