;子程序show_str描述
;功能：在指定的位置，用指定的颜色，显示一个用0结束的字符串。
;参数：(dh)=行号（取值范围0~24），(dl)=列号（取值范围0~79），(cl)=颜色，ds:si指向字符串的首地址
;返回：无
;应用举例：在屏幕的8行3列，用绿色显示data段中的字符串。
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
;显存地址换算，bx存放行，di存放列，es存放段地址，bx+di组成偏移地址
	mov ax,0b800H
	mov es,ax
	mov al,160
	mul dh
	mov bx,ax;行
	mov dh,0
	add dx,dx
	mov di,dx;列
;循环，将内存的内容转移到显存上，cx为中转寄存器，颜色存在al里
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