#include <stdio.h>
/*
 编写一个程序，用以读入一个c语言程序，并按字母表顺序分组打印变量名，要求每一组内各变量名的前6个字符相同，其余字符不同。
 字符串和注释中的单词不予以考虑。请将6作为一个可在命令行中设定的参数。
 思路：
 1. 需要识别变量名。可将限定符等存储在二叉树结构内，识别某个token是否是变量。
 2. 需要过滤字符串和注释。处理过滤后的程序
 3. 在tnode节点中，增加一个字符串数组，若前6个字符相同，且在数组中没有重复项，则加入数组。
 4. 采用二叉树来组织变量的查找。
 
 6-3
 思路：将计数改为行号，参考教材上的程序
 
 6-4
 思路：按教材上的程序统计单词频率后，再中序遍历，倒换到数组wordf[]中。
 struct *tnode wordf[];
 wordf的下标表示出现的频率，wordf[i]指向node链表。再打印wordf[i]->word即可。
 
 6-5
 思路：使用lookup查找，若没找到，则不做处理；若找到，则从链表中取出，释放对应的空间。
 */
