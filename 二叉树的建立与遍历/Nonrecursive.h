#include "Set.h"

typedef struct BiTNode {
    char data;
    struct BiTNode* lchild;
    struct BiTNode* rchild;
} BiTNode;

typedef BiTNode* BiTree;


#define MAXSIZE 100
typedef struct
{
    char *base;
    char *top;
    int stacksize;
}Sq_Stack;


//初始化
int InitStack(Sq_Stack &S);
//入栈
int Push(Sq_Stack &S, char e);
//出栈
int Pop(Sq_Stack &S,char &e);
//取栈顶元素
int GetTop(Sq_Stack S);
//判断栈空
int StackEmpty(Sq_Stack &S);
//创建
void CreateBinaryTree2(BiTree& root);
//主运行
int create_run3();
//非递归先序遍历
void InOrderTraverse(BiTree T);
