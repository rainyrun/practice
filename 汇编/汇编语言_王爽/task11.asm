;名称：letterc
;功能：将以0结尾的字符串中的小写字母转变成大写字母
;参数：ds:si指向字符串首地址
;应用举例：
assume cs:codesg
datasg segment
db "Beginner's All-purpose Symbolic Instruction Code.",0
datasg ends

codesg segment
begin:	mov ax,datasg
	mov ds,ax
	mov si,0
	call letterc

	mov ax,4c00H
	int 21H

letterc:	mov al,'a'
	mov ah,'z'
s:	mov bl,[si]
	mov ch,0
	mov cl,bl
	jcxz endc
	cmp bl,al
	jb next
	cmp bl,ah
	ja next
	and bl,11011111B
	mov [si],bl
next:	inc si
	loop s
endc:	ret

codesg ends
end begin
