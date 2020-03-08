#include <stdio.h>
#include <stdlib.h>
/*编写函数undef，它将从由lookup和install维护的表中删除一个变量及其定义。*/
struct nlist
{
	char *name;
	char *defn;
	struct nlist *next;
};
void newfree(struct nlist*);
//我理解错了这个hash表结构。如果找到则仅删除这一个节点，它之后的节点并不删除，而是连到上个节点。
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