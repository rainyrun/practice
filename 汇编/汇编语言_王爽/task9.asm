;����Ļ�м�չʾ3�С�welcome to masm!������ɫ�ֱ�Ϊ ���֡�������֡��׵�����
assume cs:code, ds:data, ss:stack
data segment
db 'welcome to masm!'
db 02h, 42h, 71h
data ends

stack segment
db 2 dup (0)
stack ends

code segment
start:	mov ax,data
	mov ds,ax
	mov ax,0b800h
	mov es,ax
	mov bx,224;64+160,��0�в�֪��Ϊʲôû��չʾ���������Դӵ�һ�п�ʼ
	mov si,0
	mov di,0
	mov cx,3
s0:	push cx
	mov cx,16
s:	mov al,[si]	;ȡ��ĸ
	mov es:[bx].0,al	;��ĸ�����ڴ�
	mov ah,[16+di]	;ȡ��ɫ
	mov es:[bx].1,ah	;��ɫ�����ڴ�
	inc si
	add bx,2
	loop s
	pop cx
	add bx,128
	mov si,0
	inc di
	loop s0
	mov ax,4c00h
	int 21h
code ends
end start
