#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLEN 1000
#define MAXTOKEN 100

enum type_tag { IDENTIFIER, QUALIFIER, TYPE };

struct token {
	char type;
	char string[MAXLEN];
};

int sp = -1;
struct token stack[MAXTOKEN];
struct token thisToken;

#define push(c) stack[++sp] = c
#define pop stack[sp--]

enum type_tag classify_string()
{
	char *s = thisToken.string;
	if (!strcmp(s, "const"))
	{
		s = "read-only";
		return QUALIFIER;
	}
	if (!strcmp(s, "volatile"))
		return QUALIFIER;
	if (!strcmp(s, "void"))
		return TYPE;
	if (!strcmp(s, "signed"))
		return TYPE;
	if (!strcmp(s, "unsigned"))
		return TYPE;
	if (!strcmp(s, "short"))
		return TYPE;
	if (!strcmp(s, "int"))
		return TYPE;
	if (!strcmp(s, "long"))
		return TYPE;
	if (!strcmp(s, "float"))
		return TYPE;
	if (!strcmp(s, "double"))
		return TYPE;
	if (!strcmp(s, "struct"))
		return TYPE;
	if (!strcmp(s, "enum"))
		return TYPE;
	if (!strcmp(s, "union"))
		return TYPE;
	if (!strcmp(s, "char"))
		return TYPE;
	return IDENTIFIER;
}

/*取一个token，跳过空格*/
void getToken()
{
	char *p = thisToken.string;
	while ((*p = getchar()) == ' ');
	if (isalnum(*p))
	{
		while (isalnum(*++p = getchar()));
		ungetc(*p,stdin);
		*p = '\0';
		thisToken.type = classify_string();
		return;//return表示程序告一段落，后续就不需要使用else再区分了。
	}

	if (*p == '*')
	{
		thisToken.type = '*';
		//p = "pointing to"; p的地址改变了，而thisToken.string的内容没有发生变化
		strcpy(p, "pointing to");
		return;
	}
	p[1] = '\0';
	thisToken.type = *p;
	return;
}

/*在取到第一个identifier之前，将token push入栈*/
void readToFirstIdentifier()
{
	getToken();
	while (thisToken.type != IDENTIFIER)
	{
		push(thisToken);
		getToken();
	}
	printf("%s is ", thisToken.string);
	getToken();
}

void dealWithArray()//dealWithArrays，最好使用复数
{
	char *s = thisToken.string;//其实不需要这一行，直接使用thisToken即可
	while (thisToken.type == '[')
	{
		printf("array ");
		getToken();//取下一个字符
		if (isdigit(s[0]))
		{
			printf("0…%d ", atoi(s)-1);
			getToken();//取]
		}
		getToken();//取[（如果有的话）
		printf("of ");
	}
}

void dealWithFunction()
{
	while (thisToken.type != ')')
		getToken();
	printf("function returning ");
	getToken();
}

/*处理遇到第一个标识符后的声明*/
void dealWithDecliration()
{
	//readToFirstIdentifier();放在主函数内处理
	switch (thisToken.type)
	{
	case '(':
		dealWithFunction();
		break;
	case '[':
		dealWithArray();
		break;
	}
	while (stack[sp].type == '*')
		printf("%s ", pop.string);//可单独写成一个函数：dealWithPointer()
	while (sp >= 0)
	{
		if (stack[sp].type == '(')
		{
			pop;
			getToken();//取)下一个token
			dealWithDecliration();
		}
		else 
			printf("%s ", pop.string);
	}
}

void main()
{
	readToFirstIdentifier();
	dealWithDecliration();
	printf("\n");
}

//void main()
//{
//	char *a = "abc";
//	char *s = a;
//	s = "read-only";
//	printf("s = %s", s);
//}

/*函数内声明的变量，即局部变量，是可以作为返回值的*/
//int p()
//{
//	int i = 123;
//	return i;
//}
//
//void main()
//{
//	int a;
//	a = p();
//	printf("a is %d\n", a);
//}
