#include "Set.h"


//����ת��
int Coversion(int M, int N);
//һ���˵�
void Conversion_menu_first_level();

//���к���
int Conversion_Run();

#define MAXSIZE 100
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
int Pop(Sq_Stack &S,int &e);
//ȡջ��Ԫ��
int GetTop(Sq_Stack S);
//�ж�ջ��
int StackEmpty(Sq_Stack &S);
// �ͷ�ջ�ڴ�
void DestroyStack(Sq_Stack &S);
