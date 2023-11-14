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
int Pop(Sq_Stack &S,int &e)
{
    if(S.top==S.base) return ERROR;
    e=*--S.top;
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

// 进制转化
int Conversion(int M, int N)
{
    Sq_Stack S;
    InitStack(S); // 初始化栈
    int e;

    switch (M)
    {
    case 0:
        DestroyStack(S); // 释放栈内存
        return 0;        // 退出程序
    case 2:
        while (N)
        {
            Push(S, N % 2);
            N = N / 2;
        }
        printf("二进制表示：");
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
        printf("八进制表示：");
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
        printf("十六进制表示：");
        while (!StackEmpty(S))
        {
            Pop(S, e);
            if (e < 10)
                printf("%d", e);
            else
                printf("%c", 'A' + e - 10); // 将大于等于10的数字转为A~F
        }
        printf("\n");
        break;
    default:
        printf("不支持的进制\n");
        break;
    }

    DestroyStack(S); // 释放栈内存
    return 1;         // 返回1表示成功执行
}

// 十进制二级菜单
void Conversion_menu_first_level()
{
    printf("**************************\n");
    printf("十进制转化菜单\n");
    printf("1.十进制转二进制\n");
    printf("2.十进制转八进制\n");
    printf("3.十进制转十六进制\n");
    printf("**************************\n");
}

// 运行函数
int Conversion_Run()
{
    while (1)
    {
        Conversion_menu_first_level();
        int n, m;
        printf("请输入十进制数：");
        scanf("%d", &n);
        if (n == -1)
        {
            // 在输入-1时返回主菜单
            printf("返回主菜单\n");
            break; // 继续下一轮循环
        }
        printf("请输入要转化的进制（2, 8, 16）：");
        scanf("%d", &m);

        if (m != 2 && m != 8 && m != 16)
        {
            printf("不支持的进制\n");
            continue; // 继续下一轮循环
        }

        Conversion(m, n);
    }

    return 0;
}






