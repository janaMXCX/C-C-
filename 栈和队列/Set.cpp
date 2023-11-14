#include "Set.h"
void menu()
{
    printf("**********************\n");
    printf("请选择所需要的功能\n");
    printf("1.进制转换\n");
    printf("2.表达式求值\n");
    printf("3.跳舞配队问题\n");
    printf("**********************\n");
    printf("你所选择的功能是：");
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
            case 1: Conversion_first();
                    break;
            case 2: Operation_first();
                    break;
            case 3: Dance_first();
                    break;
            default:printf("请输入0-3之间的数字");//如果用户输入不在0-3之间提示
        }
        if (n==0) break;
    }
}


void Conversion_first()
{
    Conversion_Run();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
void Operation_first()
{
    operation();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
void Dance_first()
{
    dance();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}

