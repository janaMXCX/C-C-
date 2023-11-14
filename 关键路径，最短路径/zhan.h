#include "Set.h"


typedef struct
{
    int *base;
    int *top;
    int stacksize;
}Sq_Stack;


//初始化
int InitStack(Sq_Stack &S);
//入栈
int Push(Sq_Stack &S, int e);
//出栈
int Pop(Sq_Stack &S,int &i);
//取栈顶元素
int GetTop(Sq_Stack S);
//判断栈空
int StackEmpty(Sq_Stack &S);
// 释放栈内存
void DestroyStack(Sq_Stack &S);
