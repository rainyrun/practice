;�ӳ���dtoc
;���ܣ���word������ת��Ϊ��ʾʮ���Ƶ��ַ������ַ����ԡ�0��Ϊ��β��
;������(ax)=word�����ݣ�ds:siָ���ַ������׵�ַ
;���أ���
;Ӧ�þ�������̣�������12666��ʮ���Ƶ���ʽ����Ļ��8��3�У�����ɫ��ʾ����������ʾʱ�����ǵ��ñ���ʵ���еĵ�һ���ӳ���show_str��
assume cs:code, ds:data, ss:stack

data segment
db 10 dup (0)
data ends

stack segment
dw 10 dup (0)
stack ends

code segment
start:	mov ax,12666
	mov bx,data
	mov ds,bx
	mov si,0
	call dtoc

	mov dh,8
	mov dl,3
	mov cl,2
	call show_str
	
	mov ax,004cH
	int 21H

dtoc:	mov bx,stack
	mov ss,bx
	push si;�ȴ���0����Ϊpop���յ㣬���ڳ�����ɺ󷵻س�ʼֵ
	mov bx,10
s:	mov dx,0
	div bx
	add dx,30H
	push dx;���������ջ�ڣ���pop�������Եõ���ȷ���ַ������ַ���ԭ���ǵ���
	mov cx,ax
	jcxz ok1;�ж����Ƿ�Ϊ0
	mov cx,10
	loop s;�����һ��ʱ��cx=1��loop�Ժ�cx=0������ѭ�������ֱ�ӵ�����һ����������Ҫ��cx����һ������ֵ��ʹ���򲻻��쳣����
ok1:	pop cx
	jcxz en
	mov ds:[si],cl
	inc si
	loop ok1
en:	mov byte ptr ds:[si],0
	mov si,0
	ret

show_str:
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
	jcxz ok2
	mov es:[bx+di],cl
	mov es:[bx+di+1],al
	add di,2
	inc si
	loop show
ok2:	ret

code ends
end start
;2018.3.8�������Ͽ�������Ӧ��û�����⣬��ʵ���ϣ����к�û��ֹͣ����debug���ԣ���int 21HʱҲһ�����������һ��ʱ���ͳ��ֳ����쳣��ϵͳ���ˡ�
