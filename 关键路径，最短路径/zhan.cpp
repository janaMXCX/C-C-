#include "Set.h"


//初始化
int InitStack(Sq_Stack &S)
{
    S.base=new int[MAXSIZE];
    if(!S.base) exit(OVERFLOW);
    S.top=S.base;
    S.stacksize = MAXSIZE;
    return OK;
}
//入栈
int Push(Sq_Stack &S, int e)
{
    if(S.top-S.base==S.stacksize) return ERROR;
    *S.top++=e;
    return OK;
}
//出栈
int Pop(Sq_Stack &S,int &i)
{
    if(S.top==S.base) return ERROR;
    i=*--S.top;
    return OK;
}
//取栈顶元素
int GetTop(Sq_Stack S)
{
    if(S.top!=S.base)
        return *(S.top-1);
}
//判断栈空
int StackEmpty(Sq_Stack &S)
{
    if(S.top==S.base)
        return OK;
    else
        return ERROR;
}

// 释放栈内存
void DestroyStack(Sq_Stack &S)
{
    delete[] S.base;
    S.base = nullptr;
    S.top = nullptr;
    S.stacksize = 0;
}
