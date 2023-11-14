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


//��ʼ��
int InitStack(Sq_Stack &S);
//��ջ
int Push(Sq_Stack &S, char e);
//��ջ
int Pop(Sq_Stack &S,char &e);
//ȡջ��Ԫ��
int GetTop(Sq_Stack S);
//�ж�ջ��
int StackEmpty(Sq_Stack &S);
//����
void CreateBinaryTree2(BiTree& root);
//������
int create_run3();
//�ǵݹ��������
void InOrderTraverse(BiTree T);
