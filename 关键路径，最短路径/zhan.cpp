#include "Set.h"


//��ʼ��
int InitStack(Sq_Stack &S)
{
    S.base=new int[MAXSIZE];
    if(!S.base) exit(OVERFLOW);
    S.top=S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
//��ջ
int Push(Sq_Stack &S, int e)
{
    if(S.top-S.base==S.stacksize) return ERROR;
    *S.top++=e;
    return OK;
}
//��ջ
int Pop(Sq_Stack &S,int &i)
{
    if(S.top==S.base) return ERROR;
    i=*--S.top;
    return OK;
}
//ȡջ��Ԫ��
int GetTop(Sq_Stack S)
{
    if(S.top!=S.base)
        return *(S.top-1);
}
//�ж�ջ��
int StackEmpty(Sq_Stack &S)
{
    if(S.top==S.base)
        return OK;
    else
        return ERROR;
}

// �ͷ�ջ�ڴ�
void DestroyStack(Sq_Stack &S)
{
    delete[] S.base;
    S.base = nullptr;
    S.top = nullptr;
    S.stacksize = 0;
}
