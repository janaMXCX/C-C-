#include "Set.h"

#define MAXSIXE 100
typedef struct
{
    int *elem;
    int length;
}SqList;


int GetList(SqList L,int i,int &e);//ȡֵ
int InitList(SqList &L);//��ʼ��
int LocateElem(SqList L,int e);//����
int ListInsert(SqList &L, int i,int e);//����
int ListDelete(SqList &L,int i);//ɾ��
int ListLength(SqList &L);//��ȡ����
void MergeList(SqList &LA,SqList LB);//�ϲ�˳���
int SetList();//���к���
void MergeList_Sq(const SqList &LA, const SqList &LB, SqList &LC);//˳�������ĺϲ�



