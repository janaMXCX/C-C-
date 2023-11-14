#include "Set.h"

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;

Status InitList2(LinkList &L); //初始化
void CreateList_H(LinkList &L, int n, int dataArray[]); //填充链表
Status ListDelete2(LinkList &L, int i);  //删除
Status ListInsert2(LinkList &L, int i, int e);  //插入
LNode *LocateElem2(LinkList L,int i, int &e); //查找
Status GetElem(LinkList L, int i, int &e);//取值
int GetListLength(LinkList L);//获取长度
void CreateList_H2();//最后运行的函数
void MergeList_L(LinkList &LA, LinkList &LB, LinkList &LC);//有序表的合并（链表的合并）






