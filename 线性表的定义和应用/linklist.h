#include "Set.h"

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;

Status InitList2(LinkList &L); //��ʼ��
void CreateList_H(LinkList &L, int n, int dataArray[]); //�������
Status ListDelete2(LinkList &L, int i);  //ɾ��
Status ListInsert2(LinkList &L, int i, int e);  //����
LNode *LocateElem2(LinkList L,int i, int &e); //����
Status GetElem(LinkList L, int i, int &e);//ȡֵ
int GetListLength(LinkList L);//��ȡ����
void CreateList_H2();//������еĺ���
void MergeList_L(LinkList &LA, LinkList &LB, LinkList &LC);//�����ĺϲ�������ĺϲ���






