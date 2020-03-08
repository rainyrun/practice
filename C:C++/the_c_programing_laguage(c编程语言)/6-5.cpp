#include <stdio.h>
#include <stdlib.h>
/*��д����undef����������lookup��installά���ı���ɾ��һ���������䶨�塣*/
struct nlist
{
	char *name;
	char *defn;
	struct nlist *next;
};
void newfree(struct nlist*);
//�����������hash��ṹ������ҵ����ɾ����һ���ڵ㣬��֮��Ľڵ㲢��ɾ�������������ϸ��ڵ㡣
void undef(char *name)
{
	struct nlist *np;
	if ((np = lookup(name)) != NULL)
		newfree(np);
}

void newfree(struct nlist *np)
{
	if (np->next == NULL)
		free(np);
	else
		newfree(np->next);
}