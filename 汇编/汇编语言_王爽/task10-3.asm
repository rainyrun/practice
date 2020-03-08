;子程序dtoc
;功能：将word型数据转变为表示十进制的字符串，字符串以‘0’为结尾符
;参数：(ax)=word型数据，ds:si指向字符串的首地址
;返回：无
;应用举例：编程，将数据12666以十进制的形式在屏幕的8行3列，用绿色显示出来。在显示时，我们调用本次实验中的第一个子程序show_str。
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
	push si;先存入0，作为pop的终点，并在程序完成后返回初始值
	mov bx,10
s:	mov dx,0
	div bx
	add dx,30H
	push dx;将结果放在栈内，再pop出来，以得到正确的字符串（字符串原来是倒序）
	mov cx,ax
	jcxz ok1;判断商是否为0
	mov cx,10
	loop s;在最后一次时，cx=1，loop以后cx=0，结束循环，结果直接到了下一步，所以需要给cx设置一个大点的值，使程序不会异常结束
ok1:	pop cx
	jcxz en
	mov ds:[si],cl
	inc si
	loop ok1
en:	mov byte ptr ds:[si],0
	mov si,0
	ret

show_str:
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
	jcxz ok2
	mov es:[bx+di],cl
	mov es:[bx+di+1],al
	add di,2
	inc si
	loop show
ok2:	ret

code ends
end start
;2018.3.8：理论上看，程序应该没有问题，但实际上，运行后没有停止，用debug调试，到int 21H时也一切正常，最后一步时，就出现程序异常的系统框了。
