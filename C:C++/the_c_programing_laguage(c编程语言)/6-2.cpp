#include <stdio.h>
/*��дһ���������Զ���һ��c���Գ��򣬲�����ĸ��˳������ӡ��������
Ҫ��ÿһ���ڸ���������ǰ6���ַ���ͬ�������ַ���ͬ��
�ַ�����ע���еĵ��ʲ��迼�ǡ��뽫6��Ϊһ���������������趨�Ĳ�����*/
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100
struct node
{
	char *name;
	struct node *next;
	struct node *left;
	struct node *right;
};

//enum token {
//	TOK_KEYWORDS,
//	TOK_ALUM,
//	TOK_OTHER
//};

char* getToken(int);
void addTree(node, char *,int);

void main(int argc, char *argv[])
{
	int n;
	char *name;
	struct node *root;
	if (argc == 2)
		n = *argv[1];
	while ((name = getToken(n)) != NULL)
		addTree(root, name, n);
}

char* getToken(int n)
{
	int c;
	int incommen;
	char *s;
	while ((c = getchar()) != EOF)
	{
		switch (c)
		{
		case '\'':
			while ((c = getchar()) != '\'')
				;
			break;
		case '"':
			while ((c = getchar()) != '"')
				;
			break;
		case '/':
			if (incommen == 0)
			{
				if ((c = getchar()) == '*')
					incommen = 1;
			}
			break;
		case '*':
			if (incommen == 1)
			{
				if ((c = getchar()) == '/')
					incommen = 0;
			}
			break;
		case '#':
			while ((c = getchar()) != '\n')
				;
			break;
		default:
			if (incommen == 0)
			{
				if (c == '_' || isalpha(c))
				{
					char *p = s;
					while (isalnum(c))
						*p++ = c;
					*p = '\0';
				}
			}
			return s;
			break;
		}
	}
	return NULL;
}
struct node *addTree(node *p, char *name, int n)
{
	if (p == NULL)
	{
		p = talloc();
		p->name = name;
		p->left = NULL;
		p->right = NULL;
		p->next = NULL;
	}
	else
	{
		int m;
		m = strncmp(name, p->name, n);
		if (m > 0)
			p->left = addTree(p->right, name, n);
		if (m < 0)
			p->right = addTree(p->left, name, n);
		if (m == 0)
			p->next = addTree(p->next, name, n);
	}
	return p;
}

void treePrint(struct node *p)
{
	struct node *t;
	t = p;
	if (p != NULL)
	{
		treePrint(p->left);
		while (t->next != NULL)
		{
			printf("%s\n", t->name);
			t = t->next;
		}
		treePrint(p->right);
	}
}

struct node *talloc(void)
{
	return (struct node *)malloc(sizeof(struct node));
}