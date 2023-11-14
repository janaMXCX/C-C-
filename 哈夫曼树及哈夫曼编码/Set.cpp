#include "Set.h"
#include "pathlong.h"
void menu()
{
    cout<< "**********************"<< endl;
    cout<< "请选择所需要的功能"<< endl;
    cout<< "1.创建哈夫曼树"<< endl;
    cout<< "2.输出每个字符的哈夫曼编码"<< endl;
    cout<< "3.计算哈夫曼树的带权路径长度，并输出"<< endl;
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
            case 0: break;

            default:printf("请输入0-3之间的数字");//如果用户输入不在0-3之间提示
        }
        if (n==0) break;
    }
}


void run_first()
{
    run();
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
void run_third()
{
    run3();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
