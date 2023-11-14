#include "Set.h"

#define MAXSIXE 100
typedef struct
{
    int *elem;
    int length;
}SqList;


int GetList(SqList L,int i,int &e);//取值
int InitList(SqList &L);//初始化
int LocateElem(SqList L,int e);//查找
int ListInsert(SqList &L, int i,int e);//插入
int ListDelete(SqList &L,int i);//删除
int ListLength(SqList &L);//获取长度
void MergeList(SqList &LA,SqList LB);//合并顺序表
int SetList();//运行函数
void MergeList_Sq(const SqList &LA, const SqList &LB, SqList &LC);//顺序有序表的合并



