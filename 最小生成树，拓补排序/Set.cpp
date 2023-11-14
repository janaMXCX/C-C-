#include "Set.h"

void menu()
{
    cout<< "**********************"<< endl;
    cout<< "请选择所需要的功能"<< endl;
    cout<< "1.构造最小生成树（prim算法）"<< endl;
    cout<< "2.已知有向图，输出其拓扑排序"<< endl;
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
            case 0: break;

            default:printf("请输入0-4之间的数字");//如果用户输入不在0-4之间提示
        }
        if (n==0) break;
    }
}


void run_first()
{
    run1();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
void run_second()
{
    run2();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}

