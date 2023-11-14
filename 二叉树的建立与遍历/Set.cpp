#include "Set.h"
void menu()
{
    cout<< "**********************"<< endl;
    cout<< "请选择所需要的功能"<< endl;
    cout<< "1.创建二叉树"<< endl;
    cout<< "2.二叉树的各种遍历"<< endl;
    cout<< "3.求深度"<< endl;
    cout<< "4.求叶子节点个数"<< endl;
    cout<< "**********************"<< endl;
    cout<< "你所选择的功能是：";
}

void menu2(){
    cout << "**********************" << endl;
    cout << "1.递归遍历，依次输出先序、中序、后序遍历" <<endl;
    cout << "2.非递归中序遍历" <<endl;
    cout << "3.层序遍历" <<endl;
    cout << "0.退出二级菜单" <<endl;
    cout << "**********************" << endl;
    cout<< "你所选择的功能是：";
}

//选择菜单功能
void select_menu()
{
    int n;
    while(1)
    {
        cin >> n;
        switch(n)
        {
            case 1: create_first();
                    break;
            case 2: Traversal_first();
                    break;
            case 3: Depth_run_first();
                    break;
            case 4: Leaf_run_first();
                    break;
            default:printf("请输入0-4之间的数字");//如果用户输入不在0-4之间提示
        }
        if (n==0) break;
    }
}
void select_menu2()
{
    int m;

    cin >> m;
    switch(m)
    {
        case 1: create_run2();
                break;
        case 2: create_run3();
                break;
        case 3: Strata_order_run();
                break;
        case 0: break;

        default:printf("请输入0-3之间的数字");//如果用户输入不在0-3之间提示
    }
}

void create_first()
{
    create_run();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
void Traversal_first()
{
    Traversal();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
void Depth_run_first()
{
    Depth_run();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}
void Leaf_run_first()
{
    Leaf_run();
    system("Pause");//暂停
    system("cls");//清屏
    menu();
}

