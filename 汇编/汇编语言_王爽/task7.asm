assume cs:codesg, ss:stack, ds:data
data segment
db	'1975','1976','1977','1978','1979','1980','1981','1982','1983'
db	'1984','1985','1986','1987','1988','1989','1990','1991','1992'
db	'1993','1994','1995'
;�����Ǳ�ʾ21���21���ַ���
dd	16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
dd	345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000
;�����Ǳ�ʾ21�깫˾�������21��dword������
dw	3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
dw	11542,14430,15257,17800
;�����Ǳ�ʾ21�깫˾��Ա������21��word������
data ends

table segment
db	21 dup ('year summ ne ?? ')
table ends

stack segment
dw	8 dup (0)
stack ends

codesg segment
start:	mov ax,data
	mov ds,ax
	mov ax,table
	mov es,ax
	mov ax,stack
	mov ss,ax
	mov sp,0

	;�ƶ�year
	mov bx,0
	mov cx,21
	mov di,0
s1:	push cx
	mov cx,4
	mov si,0
s0:	mov al,[di]
	mov es:[bx].0[si],al
	inc di
	inc si
	loop s0
	add bx,16
	pop cx
	loop s1

	;�ո���Բ����ƶ����ڷ���ռ�ʱ����д
	;�ƶ��ո�
	mov bx,0
	mov cx,21
s2:	mov byte ptr es:[bx].4,' '
	add bx,16
	loop s2

	;�ƶ�����
	mov bx,0
	mov cx,21
s3:	mov ax,[di]
	add di,2
	mov dx,[di]
	add di,2
	mov es:[bx].5,ax
	mov es:[bx].7,dx
	add bx,16
	loop s3

	;�ƶ��ո�
	mov bx,0
	mov cx,21
s4:	mov byte ptr es:[bx].9,' '
	add bx,16
	loop s4

	;�ƶ���Ա��
	mov bx,0
	mov cx,21
s5:	mov ax,[di]
	add di,2
	mov es:[bx].10,ax
	add bx,16
	loop s5

	;�ƶ��ո�
	mov bx,0
	mov cx,21
s6:	mov byte ptr es:[bx].12,' '
	add bx,16
	loop s6

	;����ƽ�����룬���洢
	mov bx,0
	mov cx,21
s7:	mov ax,es:[bx].5
	mov dx,es:[bx].7
	div word ptr es:[bx].10
	mov es:[bx].13,ax
	add bx,16
	loop s7

	;�ƶ��ո�
	mov bx,0
	mov cx,21
s8:	mov byte ptr es:[bx].15,' '
	add bx,16
	loop s8

	mov ax,4c00H
	int 21H
codesg ends
end start