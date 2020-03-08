;子程序divdw描述
;功能：进行不会产生溢出的除法运算，被除数为dword型，除数为word型，结果为dword型。
;参数：(ax)=dword型数据的低16位，(dx)=dword型数据的高16位，(cx)=除数
;返回：(dx)=结果的高16位，(ax)=结果的低16位，(cx)=余数
;应用举例：计算1000000/10（F4240H/0AH）
;公式：X/N=int(H/N)*65536+[rem(H/N)*65536+L]/N
assume cs:code, ds:data
data segment
dw 5 dup (0)	;H,L,N,int(H/N),rem(H/N)
data ends

code segment
start:	mov ax,4240H
	mov dx,000FH
	mov cx,0AH
	call divdw
	
	mov ax,004cH
	int 21H
	
divdw:	mov bx,data
	mov ds,bx
	;存储H,L,N的值
	mov ds:[0],dx;mov [0],dx 提示immediate mode illegal
	mov ds:[2],ax
	mov ds:[4],cx
	;计算H/N
	mov dx,0
	mov ax,ds:[0]
	div word ptr ds:[4]
	;存储int(H/N),rem(H/N)
	mov ds:[6],ax
	mov ds:[8],dx
	;计算[rem(H/N)*65536+L]/N
	mov ax,ds:[2]
	mov dx,ds:[8]
	div word ptr ds:[4]
	mov cx,dx
	mov dx,ds:[6]
	ret

code ends
end start

;曾经使用栈来存储中间结果，但是完成程序需要精确设计入栈和出栈顺序
;65536 = 2^16，是一个dword类型的数字，而mul操作数的最高位数是16，所以只能人工控制移位，相当于左移16位，从低16位转换成了高16位
