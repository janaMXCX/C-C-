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
int Pop(Sq_Stack &S,int &e)
{
    if(S.top==S.base) return ERROR;
    e=*--S.top;
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

// ����ת��
int Conversion(int M, int N)
{
    Sq_Stack S;
    InitStack(S); // ��ʼ��ջ
    int e;

    switch (M)
    {
    case 0:
        DestroyStack(S); // �ͷ�ջ�ڴ�
        return 0;        // �˳�����
    case 2:
        while (N)
        {
            Push(S, N % 2);
            N = N / 2;
        }
        printf("�����Ʊ�ʾ��");
        while (!StackEmpty(S))
        {
            Pop(S, e);
            printf("%d", e);
        }
        printf("\n");
        break;
    case 8:
        while (N)
        {
            Push(S, N % 8);
            N = N / 8;
        }
        printf("�˽��Ʊ�ʾ��");
        while (!StackEmpty(S))
        {
            Pop(S, e);
            printf("%d", e);
        }
        printf("\n");
        break;
    case 16:
        while (N)
        {
            Push(S, N % 16);
            N = N / 16;
        }
        printf("ʮ�����Ʊ�ʾ��");
        while (!StackEmpty(S))
        {
            Pop(S, e);
            if (e < 10)
                printf("%d", e);
            else
                printf("%c", 'A' + e - 10); // �����ڵ���10������תΪA~F
        }
        printf("\n");
        break;
    default:
        printf("��֧�ֵĽ���\n");
        break;
    }

    DestroyStack(S); // �ͷ�ջ�ڴ�
    return 1;         // ����1��ʾ�ɹ�ִ��
}

// ʮ���ƶ����˵�
void Conversion_menu_first_level()
{
    printf("**************************\n");
    printf("ʮ����ת���˵�\n");
    printf("1.ʮ����ת������\n");
    printf("2.ʮ����ת�˽���\n");
    printf("3.ʮ����תʮ������\n");
    printf("**************************\n");
}

// ���к���
int Conversion_Run()
{
    while (1)
    {
        Conversion_menu_first_level();
        int n, m;
        printf("������ʮ��������");
        scanf("%d", &n);
        if (n == -1)
        {
            // ������-1ʱ�������˵�
            printf("�������˵�\n");
            break; // ������һ��ѭ��
        }
        printf("������Ҫת���Ľ��ƣ�2, 8, 16����");
        scanf("%d", &m);

        if (m != 2 && m != 8 && m != 16)
        {
            printf("��֧�ֵĽ���\n");
            continue; // ������һ��ѭ��
        }

        Conversion(m, n);
    }

    return 0;
}






