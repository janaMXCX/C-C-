#include "Set.h"
void menu()
{
    cout<< "**********************"<< endl;
    cout<< "��ѡ������Ҫ�Ĺ���"<< endl;
    cout<< "1.����������"<< endl;
    cout<< "2.�������ĸ��ֱ���"<< endl;
    cout<< "3.�����"<< endl;
    cout<< "4.��Ҷ�ӽڵ����"<< endl;
    cout<< "**********************"<< endl;
    cout<< "����ѡ��Ĺ����ǣ�";
}

void menu2(){
    cout << "**********************" << endl;
    cout << "1.�ݹ��������������������򡢺������" <<endl;
    cout << "2.�ǵݹ��������" <<endl;
    cout << "3.�������" <<endl;
    cout << "0.�˳������˵�" <<endl;
    cout << "**********************" << endl;
    cout<< "����ѡ��Ĺ����ǣ�";
}

//ѡ��˵�����
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
            default:printf("������0-4֮�������");//����û����벻��0-4֮����ʾ
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

        default:printf("������0-3֮�������");//����û����벻��0-3֮����ʾ
    }
}

void create_first()
{
    create_run();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
void Traversal_first()
{
    Traversal();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
void Depth_run_first()
{
    Depth_run();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
void Leaf_run_first()
{
    Leaf_run();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}

