#include "Set.h"
#include "sqlist.h"
#include "linklist.h"
#include "sqlist2.h"
#include "linklist2.h"

//定义菜单
void menu()
{
    printf("\n\n");
    printf("******欢迎使用以下功能******\n");
    printf("1.线性表合并\n");
    printf("2.有序表合并\n");
    printf("3.稀疏多项式加法（顺序表）\n");
    printf("3.稀疏多项式加法（单链表）\n");
    printf("清选则数据结构类型：");
}

//选择菜单功能
void select_menu()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        switch(n)
        {
            case 1: SqListSettings();
                    break;
            case 2: SqListSettings2();
                    break;
            case 3: LinkListSettings();
                    break;
            case 4: LinkListSettings2();
                    break;
            default:printf("请输入0-4之间的数字");//如果用户输入不在0-5之间提示
        }
        if (n==0) break;
    }
}
void SqListSettings()
{
    SetList();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
void SqListSettings2()
{
    CreateList_H2();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
void LinkListSettings()
{
    setsqlist();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
void LinkListSettings2()
{
    SetLinkList();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
