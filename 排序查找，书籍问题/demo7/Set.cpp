#include "Set.h"

void menu()
{
    cout<< "**********************"<< endl;
    cout<< "请选择所需要的功能"<< endl;
    cout<< "1.排序"<< endl;
    cout<< "2.查找"<< endl;
    cout<< "3.按单价从小到大排序并输出排序后的书籍信息。"<< endl;
    cout<< "0.返回上级菜单"<< endl;
    cout<< "**********************"<< endl;
    cout<< "你所选择的功能是：";
}

void menu2()
{
    cout<< "**********************"<< endl;
    cout<< "请选择所需要的功能"<< endl;
    cout<< "1.直接插入排序（降序）"<< endl;
    cout<< "2.选择排序（升序）"<< endl;
    cout<< "3.冒泡排序（升序）"<< endl;
    cout<< "4.折半排序（降序）"<< endl;
    cout<< "0.返回上级菜单"<< endl;
    cout<< "**********************"<< endl;
    cout<< "你所选择的功能是：";
}
void menu3()
{
    cout<< "**********************"<< endl;
    cout<< "请选择所需要的功能"<< endl;
    cout<< "1.顺序查找"<< endl;
    cout<< "2.折半查找"<< endl;
    cout<< "0.返回上级菜单"<< endl;
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
            case 1: G2();
                    break;
            case 2: G3();
                    break;
            case 3: run_final();
                    break;
            case 0: break;

            default:printf("请输入0-3之间的数字");//如果用户输入不在0-4之间提示
        }
    }
}

void select_menu2()
{
    int m;
    while(1)
    {
        cin >> m;
        switch(m)
        {
            case 1: F1();
                    break;
            case 2: F2();
                    break;
            case 3: F3();
                    break;
            case 4: F4();
                    break;
            case 0: G1();
                    break;

            default:printf("请输入0-4之间的数字");//如果用户输入不在0-4之间提示
        }
    }
}
void select_menu3()
{
    int o;
    while(1)
    {
        cin >> o;
        switch(o)
        {
            case 1: S1();
                    break;
            case 2: S2();
                    break;
            case 0: G1();
                    break;

            default:printf("请输入0-2之间的数字");//如果用户输入不在0-4之间提示
        }
    }
}

void G1()
{
    menu();
    select_menu();
}
void G2()
{
    menu2();
    select_menu2();
}
void G3()
{
    menu3();
    select_menu3();
}

void F1()
{
    run1();
    system("Pause");//暂停
    system("cls");//清屏
    G1();
}
void F2()
{
    run2();
    system("Pause");//暂停
    system("cls");//清屏
    G1();
}
void F3()
{
    run3();
    system("Pause");//暂停
    system("cls");//清屏
    G1();
}

void F4()
{
    run4();
    system("Pause");//暂停
    system("cls");//清屏
    G1();
}


void S1()
{
    run5_1();
    system("Pause");//暂停
    system("cls");//清屏
    G1();
}


void S2()
{
    run6_1();
    system("Pause");//暂停
    system("cls");//清屏
    G1();
}

void H2()
{

    system("Pause");//暂停
    system("cls");//清屏
    G1();
}



