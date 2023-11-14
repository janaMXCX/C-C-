#include "Set.h"

void menu()
{
    cout<< "**********************"<< endl;
    cout<< "请选择所需要的功能"<< endl;
    cout<< "1.深度优先遍历（邻接矩阵）"<< endl;
    cout<< "2.深度优先遍历（邻接表）"<< endl;
    cout<< "3.广度优先遍历（邻接矩阵）"<< endl;
    cout<< "4.广度优先遍历（邻接表）"<< endl;
    cout<< "**********************"<< endl;
    cout<< "你所选择的功能是：";
}

void select_menu()
{
    int n;
    while(1)
    {
        cin >> n;
        switch(n)
        {
            case 1: run_first();
                    break;
            case 2: run_second();
                    break;
            case 3: run_third();
                    break;
            case 4: run_fourth();
                    break;
            case 0: break;

            default:printf("请输入0-4之间的数字");//如果用户输入不在0-4之间提示
        }
        if (n==0) break;
    }
}


void run_first()
{
    matrix_deep();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
void run_second()
{
    table_deep();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
void run_third()
{
    matrix_wide();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
void run_fourth()
{
    table_wide();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
