;在屏幕中间展示3行‘welcome to masm!’，颜色分别为 绿字、红底绿字、白底蓝字
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
	mov bx,224;64+160,第0行不知道为什么没有展示出来，所以从第一行开始
	mov si,0
	mov di,0
	mov cx,3
s0:	push cx
	mov cx,16
s:	mov al,[si]	;取字母
	mov es:[bx].0,al	;字母放入内存
	mov ah,[16+di]	;取颜色
	mov es:[bx].1,ah	;颜色放入内存
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
