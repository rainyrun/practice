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

/*ȡһ��token�������ո�*/
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
		return;//return��ʾ�����һ���䣬�����Ͳ���Ҫʹ��else�������ˡ�
	}

	if (*p == '*')
	{
		thisToken.type = '*';
		//p = "pointing to"; p�ĵ�ַ�ı��ˣ���thisToken.string������û�з����仯
		strcpy(p, "pointing to");
		return;
	}
	p[1] = '\0';
	thisToken.type = *p;
	return;
}

/*��ȡ����һ��identifier֮ǰ����token push��ջ*/
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

void dealWithArray()//dealWithArrays�����ʹ�ø���
{
	char *s = thisToken.string;//��ʵ����Ҫ��һ�У�ֱ��ʹ��thisToken����
	while (thisToken.type == '[')
	{
		printf("array ");
		getToken();//ȡ��һ���ַ�
		if (isdigit(s[0]))
		{
			printf("0��%d ", atoi(s)-1);
			getToken();//ȡ]
		}
		getToken();//ȡ[������еĻ���
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

/*����������һ����ʶ���������*/
void dealWithDecliration()
{
	//readToFirstIdentifier();�����������ڴ���
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
		printf("%s ", pop.string);//�ɵ���д��һ��������dealWithPointer()
	while (sp >= 0)
	{
		if (stack[sp].type == '(')
		{
			pop;
			getToken();//ȡ)��һ��token
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

/*�����������ı��������ֲ��������ǿ�����Ϊ����ֵ��*/
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
