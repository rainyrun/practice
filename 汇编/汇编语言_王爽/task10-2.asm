;�ӳ���divdw����
;���ܣ����в����������ĳ������㣬������Ϊdword�ͣ�����Ϊword�ͣ����Ϊdword�͡�
;������(ax)=dword�����ݵĵ�16λ��(dx)=dword�����ݵĸ�16λ��(cx)=����
;���أ�(dx)=����ĸ�16λ��(ax)=����ĵ�16λ��(cx)=����
;Ӧ�þ���������1000000/10��F4240H/0AH��
;��ʽ��X/N=int(H/N)*65536+[rem(H/N)*65536+L]/N
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
	ret

code ends
end start

;����ʹ��ջ���洢�м�����������ɳ�����Ҫ��ȷ�����ջ�ͳ�ջ˳��
;65536 = 2^16����һ��dword���͵����֣���mul�����������λ����16������ֻ���˹�������λ���൱������16λ���ӵ�16λת�����˸�16λ
