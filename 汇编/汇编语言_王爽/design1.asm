;将实验7中的power idea公司的数据按照格式在屏幕上显示出来

assume cs:codesg, ss:stack, ds:data
data segment
db	'1975','1976','1977','1978','1979','1980','1981','1982','1983'
db	'1984','1985','1986','1987','1988','1989','1990','1991','1992'
db	'1993','1994','1995'
;以上是表示21年的21个字符串
dd	16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
dd	345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000
;以上是表示21年公司总收入的21个dword型数据
dw	3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
dw	11542,14430,15257,17800
;以上是表示21年公司雇员人数的21个word型数据
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
;将数据按照table里的格式，存储在内存里，es:bx指向内存，ds:di指向data
	call move

;将table里的数据，展示在屏幕上
;展示年份，ds:si指向table，es:di指向显存
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
	
;展示总收入,es:bx指向table， ds:si指向string， es:di指向显存
	mov bx,0
	mov ax,string
	mov ds,ax
	mov si,0	
	mov di,200
	mov cx,21;重复21次（共21行）
	;ax存低16位，dx存高16位，cx存除数
ssum:	mov ax,table
	mov es,ax
	mov ax,es:[bx].5
	mov dx,es:[bx].7
	;将收入es:bx转换成字符串，并放在ds:si中
	call dtoc
	add bx,16
	mov ax,0b800H
	mov es,ax
	call show_str
	add di,160
	loop ssum
	
; ;测试dtoc
	; mov ax,string
	; mov ds,ax
	; mov si,0	
	; mov di,40
	; mov ax,2390
	; mov dx,0
	; ;将收入es:bx转换成字符串，并放在ds:si中
	; call dtoc
	; mov ax,0b800H
	; mov es,ax
	; call show_str
	
;展示雇员数，es:bx指向table， ds:si指向string， es:di指向显存
	mov bx,0
	mov si,0
	mov di,240
	mov cx,21
sempl:	mov ax,table
	mov es,ax
	mov ax,es:[bx].10;雇员数
	call wtoc
	add bx,16
	mov ax,0b800H
	mov es,ax
	call show_str
	add di,160
	loop sempl
	
;展示平均收入，es:bx指向table， ds:si指向string， es:di指向显存
	mov bx,0
	mov si,0
	mov cx,21
	mov di,280
saver:	mov ax,table
	mov es,ax
	mov ax,es:[bx].13;平均工资
	call wtoc
	add bx,16
	mov ax,0b800H
	mov es,ax
	call show_str
	add di,160
	loop saver
	
	mov ax,4c00H
	int 21H

	
;将ds:si中的字符串展示在屏幕上es:di
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

;子程序wtoc
;功能：将word型数据转变为表示十进制的字符串，字符串以‘0’为结尾符
;参数：(ax)=word型数据，ds:si指向字符串的首地址
wtoc:	push cx
	push bx
	push si;先存入0，作为pop的终点，并在程序完成后返回初始值
	mov bx,10
wtocs:	mov dx,0
	div bx
	add dx,30H
	push dx;将结果放在栈内，再pop出来，以得到正确的字符串（字符串原来是倒序）
	mov cx,ax
	jcxz wtocend1;判断商是否为0
	mov cx,10
	loop wtocs;在最后一次时，cx=1，loop以后cx=0，结束循环，结果直接到了下一步，所以需要给cx设置一个大点的值，使程序不会异常结束
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
	
;dtoc子程序
;功能：将dword型数转变为表示十进制数的字符串，字符串以0为结尾符
;参数：(ax)=dword型数据的低16位，(dx)=dword型数据的高16位，ds:si指向字符串的首地址
;返回：无
dtoc:	push cx
	push si
d:	mov cx,0aH
	call divdw
	add cx,30H
	push cx;余数入栈
	mov cx,dx
	jcxz jlow
	mov cx,0aH;当cx=1时，不会自动结束循环
	loop d
jlow:	mov cx,ax
	jcxz end1
	mov cx,0aH;当cx=1时，不会自动结束循环
	loop d
end1:	pop cx
	jcxz end2
	mov [si],cl
	inc si
	loop end1
end2:	mov [si],cl;字符串以0为结尾符
	mov si,cx
	pop cx;
	ret
	
;子程序divdw描述
;功能：进行不会产生溢出的除法运算，被除数为dword型，除数为word型，结果为dword型。
;参数：(ax)=dword型数据的低16位，(dx)=dword型数据的高16位，(cx)=除数
;返回：(dx)=结果的高16位，(ax)=结果的低16位，(cx)=余数
;应用举例：计算1000000/10（F4240H/0AH）
;公式：X/N=int(H/N)*65536+[rem(H/N)*65536+L]/N
divdw:	push bx
	push ds
	mov bx,divdata
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
	pop ds
	pop bx
	ret

	
;子程序move
;将data数据按照一定格式，移动到table里
;es:bx指向table，ds:di指向data
move:	mov bx,0
	mov di,0
	mov cx,21
;移动year，每次移动4个字符
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

;移动收入，收入为dword类型，高16位和低16位分开移动
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

;移动雇员数
	mov bx,0
	mov cx,21
mempl:	mov ax,[di]
	add di,2
	mov es:[bx].10,ax
	add bx,16
	loop mempl

;计算平均收入，并移动
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