线性表实习题
1.3集合的并、交和差运算的程序

1.需求分析
（1）输入的形式和输入值的范围；
输入的形式：在屏幕上输入字符串，以回车符作为结尾，字符串内允许出现非法字符和重复字符，程序能自动过滤。
输入值的范围：不超过30个字符，输入内容为“a-z”
（2）输出的形式
计算机显示提示信息。用户输入的字符串，程序经过过滤重组后，展示在屏幕上。输入完2个集合后，用户输入求交、求并、求差的指令，计算后将结果显示在屏幕上。可以多次输入集合
（3）程序所能达到的功能
1.将用户输入字符串转换成集合；2.求集合的并；3.求集合的交；4.求集合的差
（4）测试数据：包括正确的输入及其输出结果和含有错误的输入及其输出结果

2.概要设计
抽象数据类型：结点、有序表、集合
ADT Node{
	数据对象：D = {a(i) | a(i) € CharSet, i = 1, 2……, n >= 0}
	数据关系：R1 = {}
	基本操作：
	MakeNode(&p, e)
		操作结果：p指向新生成的结点，新结点的数据域为e，指针域为null。若空间分配失败，则返回false
	FreeNode(&p)
		初始条件：p指向的结点存在
		操作结果：释放p指向的结点，并将p指向null
	CopyNode(&p)
		初始条件：p指向的结点存在
		操作结果：生成新结点，结点数据域复制p结点的数据域，指针域为null
}
ADT OrderedList{
	数据对象：D = {a(i) | a(i) € Node, i = 1, 2……, n >= 0}
	数据关系：R1 = {<a(i-1), a(i)> | a(i) € Node }
	基本操作：
	InitList(&L)
		操作结果：构造一个空的有序表L
	DestroyList(&L)
		初始条件：有序表L存在
		操作结果：销毁有序表L
	AppendElem(&L, p)
		初始条件：有序表L存在
		操作结果：在有序表L的末尾插入结点p
	InsertAfter(&L, p, e)
		初始条件：有序表L存在，p指向的结点在链表L内
		操作结果：将元素e插在p指向结点之后，插入失败返回false
	LocateElem(L，e)
		初始条件：有序表L存在
		操作结果：返回指针p，指向不大于e的最大元素的结点，若有元素=e，则返回null
}
ADT OrderedSet{
	数据对象：D = {a(i) | a(i) € Node, i = 1, 2……, n >= 0}
	数据关系：R1 = {}
	基本操作：
	CreatSet(&T, str)
		初始条件：存在字符串str
		操作结果：过滤str中的非法字符和重复字符，并生成一个数据升序排列的集合T
	DestroySet(&T)
		初始条件：集合T存在
		操作结果：销毁集合T
	Union(&T, set1, set2)
		初始条件：se1, set2存在
		操作结果：求set1，set2点并集T
	Intersection(&T, set1, set2)
		初始条件：se1, set2存在
		操作结果：求set1，set2点交集T
	Difference(&T, set1, set2)
		初始条件：se1, set2存在
		操作结果：求set1，set2点差集T
	PrintSet(T)
		初始条件：集合T存在
		操作结果：打印集合T中的元素
}
调用关系：
主流程-->集合模块-->有序表模块-->结点模块

3.详细设计
有序表选择链表
typedef char ElemType;

typedef struct NodeType{
	ElemType data;
	NodeType *next;
}NodeType, *LinkType;

//typedef LinkType OrderedList;
typedef struct OrderedList{
	LinkType head, tail;
} OrderedList;

typedef OrderedList OrderedSet;

//结点的操作
status MakeNode(LinkType &p, e){
	p = (LinkType)malloc(sizeof(NodeType));
	if(!p) return false;
	p->data = e; p->next = null;
	return ture;
}
void FreeNode(LinkType &p){
	free(p);
	p = null;
}
LinkType CopyNode(LinkType p){
	if(!MakeNode(s, p->data))
		return null;
	s->next = null;
	return s;
}

//有序链表的操作
status InitList(OrderedList &L){
	//需要增设头指针作为MakeNode的参数
	if(!MakeNode(L.head, ' '))
		return false;
	return ture;
}
void DestroyList(LinkType &L){
	p = L;
	while(p){
	s = p; p = p->next; FreeNode(s);
	}
}
void AppendElem(LinkType &L, LinkType s){
	if(L.head && s){
		//需要增设有序链表的尾指针，否则AppendElem的时间复杂度为O(n)，而此函数又经常用到
		L.tail->next = p;
		L.tail = p;
	}
}//AppendElem
status InsertAfter(OrderedLink &L, LinkType p, ElemType e){
	if(!MakeNode(q, e))
		return false;
	if(!p->next)
		L.tail = q;
	q->next = p->next;
	p->next = q;
	return ture;
}
LinkType LocateElem(OrderedList L, ElemType e){
	s = L.head;
	p = L.head->next;
	while(p && p->data <= e){
		if(p->data == e)
			return null;
		s = p; p = p->next;
	}
	return s;
}

//集合的操作
status CreatSet(OrderedSet &T, char *s){
	if(InitList(&T)){//构造空集合T
		for(i = 0; i < Length(s); i++ ){
			//生成集合时，需要将元素插在合适的位置，链表需增设InsertAfter()将元素放在合适的位置，增设LocateElem()查找插入的位置
			if(islower(s[i]))//过滤非法元素
				p = LocateElem(T, s[i]);
				if(p){
					if(!nsertAfter(T, p, e))
						return false;
			}
		}
	}
	return ture;
}//CreatSet
status DestroySet(OrderedSet &T){
	DestroyList(T);
}//DestroySet
//在操作过程中，有很多地方扔需要判断结点是否生成。应尽量封装在各类操作中，使用时不用考虑太多空间问题
void Union(OrderedSet &T, OrderedSet set1, OrderedSet set2){
	if(InitList(T)){
		p = set1.head; q = set2.head;
		while(p && q){
			if(p->data <= q->data){
				AppendElem(T, CopyNode(p));
				p = p->next;
				if(p->data == q->data)
					q = q->next;
			}
			else{
				AppendElem(T, CopyNode(q))
				q = p->next;
			}
		}//while
		while(p){
			AppendElem(T, CopyNode(p))
			p = p->next;
		}
		while(q){
			AppendElem(T, CopyNode(q))
			q = q->next;
		}
	}
}//Union
void Intersection(OrderedSet &T, OrderedSet set1, OrderedSet set2){
	if(InitList(T)){
		p = set1.head; q = set2.head;
		while(p && q){
			if(p->data <= q->data){
				p = p->next;
				if(p->data == q->data){
					AppendElem(T, CopyNode(p));
					q = q->next;
				}
			}
			else{
				q = p->next;
			}
		}//while
	}
}//Intersection
void Difference(OrderedSet &T, OrderedSet set1, OrderedSet set2){
	if(InitList(T)){
		p = set1.head; q = set2.head;
		while(p && q){
			if(p->data == q->data){
				p = p->next;
				q = q->next;
			}
			else if(p->data < q->data){
				AppendElem(T, CopyNode(p));
				p = p->next;
			}
			else{
				q = q->next;
			}
		}//while
		while(p){
			AppendElem(T, CopyNode(p))
			p = p->next;
		}
	}
}//Difference
void PrintSet(OrderedSet T){
	p = T.head->next;
	while(p){
		printf("%s, ", p->data);
	}
	printf(".\n");
}

//主函数
void main(void){
	Initialization();//屏幕初始化，展示操作命令提示
	do{
		ReadCommand(c);
		Interpret(c);
	}while(c != 'q' && c != 'Q');
}//main
void Initialization(){
	printf("please input cmds.\n");
	printf("  1 = input set1.\n  2 = input set2.\n  u = union.\n  i = intersection.\n  d = difference.\n  q&&Q = quit.\n");
}
void ReadCommand(char &c){
	do{
		c = getchar();
	}while(c != 命令);
}
void Interpret(char c){
	switch(c){
		case '1':
			//获取字符串str1，以回车为结尾
			//set1存在时，要先销毁
			CreatSet(set1, str1);
			PrintSet(set1);
			break;
		case '2':
			//获取字符串str2，以回车为结尾
			CreatSet(set2, str2);
			PrintSet(set2);
			break;
		case 'u':
			Union(T1, set1, set2);
			PrintSet(T1);
			DestroySet(T1);
			break;
		case 'i':
			Intersection(T2, set1, set2);
			PrintSet(T2);
			DestroySet(T2);
			break;
		case 'd':
			Difference(T3, set1, set2);
			PrintSet(T3);
			DestroySet(T3);
			break;
		case 'q':
		case 'Q':
			DestroySet(set1);
			DestroySet(set2);
			break;
	}
}
4.调试分析
（1）由于对指针的相关运算不熟悉，在初始化函数中，曾经给形参中的指针变量分配地址，结果实参的地址并没有改变（应该使用指针的指针，指针的地址才会改变；或者使用c++的引用）。对于c语言，比较适合将分配的空间的地址当作返回值
（2）集合和有序表模块结构划分的不太合理。集合变量还用到了有序表的初始化函数。
