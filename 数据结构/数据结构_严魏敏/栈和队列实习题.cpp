栈和队列实习题
2.9迷宫问题
1.需求分析
（1）输入的形式和输入值的范围
//迷宫地图以二维数组的形式输入，依次输入每行的数据。输入的值为0和1，0代表障碍，1代表通路。
用户以文件的形式输入迷宫的数据。迷宫的入口和出口位置可由用户随时设置。
（2）输出的形式
//输出一串三元组（i, j, d）作为通路，（i，j）表示坐标，d表示方向（共有4个方向）
打印通路路径，‘*’表示路径，‘#’表示障碍，‘@’表示死胡同，其余用空格表示
当迷宫不存在通路时，报告相应信息
（3）程序所能达到的功能
输入地图后，能找出一条通路，或告知没有通路
（4）测试数据：包括正确的输入及其输出结果和含有错误的输入及其输出结果
2.概要设计
说明本程序中用到的所有抽象数据类型的定义、主程序的流程以及各程序模块之间的层次（调用）关系
需要的抽象数据类型为：路径栈，由结点构成，表示通路上的每个结点；迷宫，画出通路结构
ADT Stack{
	数据对象：D = {ai |ai € ElemType, i = 1, 2, ……}
	数据关系：R = {<ai-1, ai>|ai € ElemType, i = 1, 2, …… }
	基本操作：
	InitStack(&S)
	操作结果：构造一个空栈
	Push(&S, e)
	初始条件：栈S存在
	操作结果：将元素e入栈
	Pop(&S, &e)
	初始条件：栈S存在
	操作结果：将栈顶元素出栈，并保存在元素e中
	DestroyStack(&S)
	初始条件：栈S存在
	操作结果：销毁栈S
	IsEmpty(S)
	初始条件：栈S存在
	操作结果：检查S是否为空栈
}
ADT Maze{
	数据对象：D = {ai | ai € mazetype, i = 1, 2, ……}
	数据关系：R = {<ai> | ai € mazetype, i = 1, 2, ……}
	基本操作：
	InitMaze(&M)
	操作结果：初始化迷宫M
	IsPass(M, p)
	初始条件：迷宫M存在
	操作结果，检查坐标p在迷宫M中是否能走通，即p不是障碍，没有走过
	FootPrint(&M, p)
	初始条件：迷宫M存在，p在迷宫内
	操作结果：将p在迷宫中的位置，标记为通路*
	MarkPrint(&M, p)
	初始条件：迷宫M存在，p在迷宫内
	操作结果：将p在迷宫中的位置，标记为死路@
	MazePath(&M)
	初始条件：迷宫M存在
	操作结果：在迷宫M中找到一条通路，没有通路时报告
	MazePrint(M)
	初始条件：迷宫M存在
	操作结果：打印迷宫M
}
3.详细设计
实现概要设计中定义的所有数据类型，对每个操作只需要写出伪码算法；
对主流程和其他模块也都需要写出伪码算法（详细程度为：按照伪码算法可以在计算机键盘直接输入高级程序设计语言程序）；画出函数的调用关系图。
#define RANGE 20
//1.坐标位置类型
typedef struct PosType
{
	int r, c;//迷宫中r行c列的位置
} PosType;
PosType NextPos(PosType p, int dir);//给定坐标p和方向，将下一个坐标保存在q中
bool Same(PosType a, PosType b);//比较a和b是否是同一个点，如果是，返回true；否则返回false
//2.栈类型
typedef struct ElemType{
	PosType seat;
	int d;//表示下一步的方向
} ElemType;
typedef struct NodeType{
	ElemType data;
	struct NodeType *next;
} NodeType, *NodeLink;
typedef struct Stack
{
	NodeLink top;
} Stack;
void InitStack(Stack &S);
void DestroyStack(Stack &S);
bool IsEmpty(Stack S)
void Push(Stack &S, ElemType e);
void Pop(Stack &S, ElemType &e);
NodeLink MakeNode(ElemType e);
//3.迷宫类型
typedef struct MazeType
{
	int m, n;//行和列
	char arr[RANGE][RANGE];
} MazeType;
void InitMaze(MazeType &maze, int a[][], int row, int col);
bool MazePath(MazeType &maze, PosType start, PosType end)
void MarkPrint(MazeType maze);
bool IsPass(MazeType maze, PosType p);
void FootPrint(MazeType &maze, PosType p);
void MazePrint(MazeType &maze, PosType p);

//1.坐标类型算法如下：
PosType NextPos(PosType p, int dir){
	PosType q;
	switch(dir){
		case 1:
		q.r = p.r;
		q.c = p.c + 1;
		break;
		case 2:
		q.r = p.r + 1;
		q.c = p.c;
		break;
		case 3:
		q.r = p.r;
		q.c = p.c - 1;
		break;
		case 4:
		q.r = p.r - 1;
		q.c = p.c;
		break;
	}
	return q;
}
bool Same(PosType a, PosType b){
	if(a.r == b.r && a.c == b.c)
		return TRUE;
	else
		return FALSE;
}

//2.栈类型算法如下：
void InitStack(Stack &S){
	S.top = NULL;
}
bool Push(Stack &S, ElemType e){
	//若空间分配成功，则在S的栈顶插入新的栈顶元素e，并返回TRUE；否则栈不变，并返回FALSE
	p = MakeNode(e);
	if(!p) return FALSE;
	p->next = S.top;
	S.top = p;
	return TRUE;
}
bool Pop(Stack &S, ElemType &e){
	//若栈不空，则删除S的栈顶元素并以e带回其值，且返回true；否则返回false，且e无意义
	if (IsEmpty(S))
		return FALSE;
	else{
		p = S.top;
		S.top = p->next;
		e = p->data;
		free(p);
	}
	
}
void DestroyStack(Stack &S){
	while(S.top){
		p = S.top;
		S.top = p->next;
		free(p);
	}
}
bool IsEmpty(Stack S){
	if(!S.top)
		return FALSE;
	else
		return TRUE;
}
NodeLink MakeNode(ElemType e){
	p = (NodeLink)malloc(sizeof(NodeType));
	p->data = e;
	p->next = NULL;
	return p;
}

//3.迷宫类型算法如下：
void InitMaze(MazeType &maze, int a[][], int row, int col){
	//按用户输入的row行col列初始化迷宫M
	//迷宫最外围包上一层障碍
	maze.m = row;
	maze.n = col;
	for (int i = 0; i < row + 2; ++i)
	{
		for (int j = 0; j < col + 2; ++j)
		{
			if(i == 0 || i == (row + 1) || j == 0 || j == (col + 1))
				maze.arr[i][j] = '#';
			else{
				switch(a[i-1, j-1]){
					case 0:
					maze.arr[i, j] = '#';
					break;
					case 1:
					maze.arr[i, j] = ' ';
				}
			}//else
		}//for
	}//for
}
bool IsPass(MazeType maze, PosType p){
	if(maze.arr[p.r][p.c] == ' ')
		return TRUE;
	else
		return FALSE;
}
void FootPrint(MazeType &maze, PosType p){
	maze.arr[p.r][p.c] == '*';
}
void MarkPrint(MazeType &maze, PosType p){
	maze.arr[p.r][p.c] == '@';
}
bool MazePath(MazeType &maze, PosType start, PosType end){
	//start和end在迷宫内，若迷宫maze中存在从入口start到出口end到通道，则求得一条存放在栈中，并返回true；否则返回false
	InitStack(S);
	PosType curpos = start;
	bool found = FALSE;
	do{
		if(IsPass(maze, curpos)){
			FootPrint(maze, curpos);
			e = (curpos, 1);//e是ElemType类型，是“e.seat = curpos; e.d = 1;”的简便记法
			Push(S, e);
			if(Same(curpos,end)) found = TRUE;
			else{
				curpos = NextPos(curpos, 1);
			}
		}//if
		else{//当前位置不能通过
			if(!IsEmpty(S)){
				Pop(S, e);
				while (e.d == 4 && !IsEmpty(S)){
					MarkPrint(maze, e.seat);
					Pop(S, e);
				}
				if(e.d < 4){
					e.d += 1;
					Push(S, e);
					curpos = NextPos(e.seat, e.d);
				}
			}
		}//else
	}while(!IsEmpty(S) && !found);
	return found;
}
void MazePrint(MazeType maze){
	for (int i = 1; i < (maze.m + 1); ++i){
		for (int j = 1; j < (maze.n + 1); ++j){
			printf("%c", maze.arr[i][j]);
		}
		printf("\n");
	}
}
//4.主函数和其他函数的伪码算法
void Initialization();
void ReadCommand(cmd);
void InterPret(cmd);
int main(void){
	Initialization();
	do{
		ReadCommand(cmd);//读入命令
		InterPret(cmd);
	}
	return 0;
}
void Initialization(){
	//初始化屏幕，显示指令说明
}
void ReadCommand(cmd){
	cmd = getchar();
	while(cmd != 正确命令){
		printf("please input correct command.\n");
		cmd = getchar();
	}
}
void InterPret(cmd){
	switch(cmd){
		case 'c':
		//提示用户输入迷宫数据的文件名filename；读入行列和二维数组的数据
		InitMaze(maze, a2, rnum, cnum);
		//输出迷宫初始化完成的信息；
		break;
		case 'm':
		//提示用户输入迷宫的入口from和出口term的坐标，坐标的行号列号从1开始
		if(MazePath(maze, from, term))
			//提示用户查看结果
		else
			//提示没有路径
		break;
		case 'p':
		MazePrint(maze);
		break;
	}//switch
}//InterPret
调用关系图：main=>maze=>stack=>pos
4.调试分析
内容包括：
（1）调试过程中遇到的问题是如何解决的以及对设计与实现的回顾讨论和分析；

（2）算法的时空分析
（3）经验和体会等
在MathPath函数的书写过程中，因为没有设置合适的变量，导致变量名很长，结构很深。设置一些名字清晰明了的变量，能帮助理清楚程序的结构
过分关注结构细节，使得伪代码中变量结构的细节过多，影响了伪代码的清晰简洁
结构体内的元素名起的过于简洁，使得理解起来很不方便
5.用户使用说明
说明如何使用你编写的程序，详细列出每一步的操作步骤。
6.测试结果
列出你的测试结果，包括输入和输出。这里的测试数据应该完整和严格，最好多于需求分析中所列。
7.附录
带注释的源程序。