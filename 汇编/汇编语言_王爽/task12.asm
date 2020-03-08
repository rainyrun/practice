;编写0号中断的处理程序，使得在除法溢出发生时，在屏幕中间显示字符串“divide error！”，然后返回到dos
assume cs:code
code segment
;do0安装程序
;源地址：ds：[si](cs:do0)，目的地址：es：[di]（0：200H）
start:	mov ax,cs
	mov ds,ax
	mov si,offset do0

	mov ax,0
	mov es,ax
	mov di,200H
	mov cx,offset do0end - offset do0
	cld
	rep movsb

	;设置中断向量表
	mov ax,0
	mov es,ax
	mov word ptr es:[0],200H
	mov word ptr es:[2],0

	mov ax,4c00h
	int 21h
;显示字符串“divide error！”
do0:	jmp short do0start
	db "divide error!"
	;设置ds：si指向字符串
do0start:	mov ax,cs
	mov ds,ax
	mov si,202H

	mov ax,0b800H
	mov es,ax
	mov di,12*160+33*2

	mov cx,13
s:	mov al,[si]
	mov es:[di],al
	inc si
	add di,2
	loop s

	mov ax,4c00Hq
	int 21h

do0end:	nop

code ends
end start
