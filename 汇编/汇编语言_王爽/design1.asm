;��ʵ��7�е�power idea��˾�����ݰ��ո�ʽ����Ļ����ʾ����

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
dw	20 dup (0)
stack ends

string segment
db 20 dup (0)
string ends

divdata segment
dw 5 dup (0)	;H,L,N,int(H/N),rem(H/N)
divdata ends

codesg segment
start:	mov ax,data
	mov ds,ax
	mov ax,table
	mov es,ax
	mov ax,stack
	mov ss,ax
	mov sp,0
;�����ݰ���table��ĸ�ʽ���洢���ڴ��es:bxָ���ڴ棬ds:diָ��data
	call move

;��table������ݣ�չʾ����Ļ��
;չʾ��ݣ�ds:siָ��table��es:diָ���Դ�
	mov ax,table
	mov ds,ax
	mov ax,0b800H
	mov es,ax
	mov si,0
	mov di,160
	mov cx,21
syear:	mov al,[si].0
	mov es:[di].0,al
	mov al,[si].1
	mov es:[di].2,al
	mov al,[si].2
	mov es:[di].4,al
	mov al,[si].3
	mov es:[di].6,al
	add si,16
	add di,160
	loop syear
	
;չʾ������,es:bxָ��table�� ds:siָ��string�� es:diָ���Դ�
	mov bx,0
	mov ax,string
	mov ds,ax
	mov si,0	
	mov di,200
	mov cx,21;�ظ�21�Σ���21�У�
	;ax���16λ��dx���16λ��cx�����
ssum:	mov ax,table
	mov es,ax
	mov ax,es:[bx].5
	mov dx,es:[bx].7
	;������es:bxת�����ַ�����������ds:si��
	call dtoc
	add bx,16
	mov ax,0b800H
	mov es,ax
	call show_str
	add di,160
	loop ssum
	
; ;����dtoc
	; mov ax,string
	; mov ds,ax
	; mov si,0	
	; mov di,40
	; mov ax,2390
	; mov dx,0
	; ;������es:bxת�����ַ�����������ds:si��
	; call dtoc
	; mov ax,0b800H
	; mov es,ax
	; call show_str
	
;չʾ��Ա����es:bxָ��table�� ds:siָ��string�� es:diָ���Դ�
	mov bx,0
	mov si,0
	mov di,240
	mov cx,21
sempl:	mov ax,table
	mov es,ax
	mov ax,es:[bx].10;��Ա��
	call wtoc
	add bx,16
	mov ax,0b800H
	mov es,ax
	call show_str
	add di,160
	loop sempl
	
;չʾƽ�����룬es:bxָ��table�� ds:siָ��string�� es:diָ���Դ�
	mov bx,0
	mov si,0
	mov cx,21
	mov di,280
saver:	mov ax,table
	mov es,ax
	mov ax,es:[bx].13;ƽ������
	call wtoc
	add bx,16
	mov ax,0b800H
	mov es,ax
	call show_str
	add di,160
	loop saver
	
	mov ax,4c00H
	int 21H

	
;��ds:si�е��ַ���չʾ����Ļ��es:di
show_str:	push di
	push cx
	push si
	mov ch,0
show:	mov cl,[si]
	jcxz endshow
	mov es:[di],cl
	add di,2
	inc si
	loop show
endshow:	pop si
	pop cx
	pop di
	
	ret

;�ӳ���wtoc
;���ܣ���word������ת��Ϊ��ʾʮ���Ƶ��ַ������ַ����ԡ�0��Ϊ��β��
;������(ax)=word�����ݣ�ds:siָ���ַ������׵�ַ
wtoc:	push cx
	push bx
	push si;�ȴ���0����Ϊpop���յ㣬���ڳ�����ɺ󷵻س�ʼֵ
	mov bx,10
wtocs:	mov dx,0
	div bx
	add dx,30H
	push dx;���������ջ�ڣ���pop�������Եõ���ȷ���ַ������ַ���ԭ���ǵ���
	mov cx,ax
	jcxz wtocend1;�ж����Ƿ�Ϊ0
	mov cx,10
	loop wtocs;�����һ��ʱ��cx=1��loop�Ժ�cx=0������ѭ�������ֱ�ӵ�����һ����������Ҫ��cx����һ������ֵ��ʹ���򲻻��쳣����
wtocend1:	pop cx
	jcxz wtocend2
	mov ds:[si],cl
	inc si
	loop wtocend1
wtocend2:	mov byte ptr ds:[si],0
	pop bx
	pop cx
	mov si,0
	ret
	
;dtoc�ӳ���
;���ܣ���dword����ת��Ϊ��ʾʮ���������ַ������ַ�����0Ϊ��β��
;������(ax)=dword�����ݵĵ�16λ��(dx)=dword�����ݵĸ�16λ��ds:siָ���ַ������׵�ַ
;���أ���
dtoc:	push cx
	push si
d:	mov cx,0aH
	call divdw
	add cx,30H
	push cx;������ջ
	mov cx,dx
	jcxz jlow
	mov cx,0aH;��cx=1ʱ�������Զ�����ѭ��
	loop d
jlow:	mov cx,ax
	jcxz end1
	mov cx,0aH;��cx=1ʱ�������Զ�����ѭ��
	loop d
end1:	pop cx
	jcxz end2
	mov [si],cl
	inc si
	loop end1
end2:	mov [si],cl;�ַ�����0Ϊ��β��
	mov si,cx
	pop cx;
	ret
	
;�ӳ���divdw����
;���ܣ����в����������ĳ������㣬������Ϊdword�ͣ�����Ϊword�ͣ����Ϊdword�͡�
;������(ax)=dword�����ݵĵ�16λ��(dx)=dword�����ݵĸ�16λ��(cx)=����
;���أ�(dx)=����ĸ�16λ��(ax)=����ĵ�16λ��(cx)=����
;Ӧ�þ���������1000000/10��F4240H/0AH��
;��ʽ��X/N=int(H/N)*65536+[rem(H/N)*65536+L]/N
divdw:	push bx
	push ds
	mov bx,divdata
	mov ds,bx
	;�洢H,L,N��ֵ
	mov ds:[0],dx;mov [0],dx ��ʾimmediate mode illegal
	mov ds:[2],ax
	mov ds:[4],cx
	;����H/N
	mov dx,0
	mov ax,ds:[0]
	div word ptr ds:[4]
	;�洢int(H/N),rem(H/N)
	mov ds:[6],ax
	mov ds:[8],dx
	;����[rem(H/N)*65536+L]/N
	mov ax,ds:[2]
	mov dx,ds:[8]
	div word ptr ds:[4]
	mov cx,dx
	mov dx,ds:[6]
	pop ds
	pop bx
	ret

	
;�ӳ���move
;��data���ݰ���һ����ʽ���ƶ���table��
;es:bxָ��table��ds:diָ��data
move:	mov bx,0
	mov di,0
	mov cx,21
;�ƶ�year��ÿ���ƶ�4���ַ�
myear:	push cx
	mov cx,4
	mov si,0
s0:	mov al,[di]
	mov es:[bx].0[si],al
	inc di
	inc si
	loop s0
	add bx,16
	pop cx
	loop myear

;�ƶ����룬����Ϊdword���ͣ���16λ�͵�16λ�ֿ��ƶ�
	mov bx,0
	mov cx,21
msum:	mov ax,[di]
	add di,2
	mov dx,[di]
	add di,2
	mov es:[bx].5,ax
	mov es:[bx].7,dx
	add bx,16
	loop msum

;�ƶ���Ա��
	mov bx,0
	mov cx,21
mempl:	mov ax,[di]
	add di,2
	mov es:[bx].10,ax
	add bx,16
	loop mempl

;����ƽ�����룬���ƶ�
	mov bx,0
	mov cx,21
maver:	mov ax,es:[bx].5
	mov dx,es:[bx].7
	div word ptr es:[bx].10
	mov es:[bx].13,ax
	add bx,16
	loop maver

	ret

codesg ends
end start