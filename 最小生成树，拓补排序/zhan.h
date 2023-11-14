#include "Set.h"


typedef struct
{
    int *base;
    int *top;
    int stacksize;
}Sq_Stack;


//��ʼ��
int InitStack(Sq_Stack &S);
//��ջ
int Push(Sq_Stack &S, int e);
//��ջ
int Pop(Sq_Stack &S,int &i);
//ȡջ��Ԫ��
int GetTop(Sq_Stack S);
//�ж�ջ��
int StackEmpty(Sq_Stack &S);
// �ͷ�ջ�ڴ�
void DestroyStack(Sq_Stack &S);
