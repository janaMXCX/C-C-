#include "Set.h"

void menu()
{
    cout<< "**********************"<< endl;
    cout<< "��ѡ������Ҫ�Ĺ���"<< endl;
    cout<< "1.����"<< endl;
    cout<< "2.����"<< endl;
    cout<< "3.�����۴�С������������������鼮��Ϣ��"<< endl;
    cout<< "0.�����ϼ��˵�"<< endl;
    cout<< "**********************"<< endl;
    cout<< "����ѡ��Ĺ����ǣ�";
}

void menu2()
{
    cout<< "**********************"<< endl;
    cout<< "��ѡ������Ҫ�Ĺ���"<< endl;
    cout<< "1.ֱ�Ӳ������򣨽���"<< endl;
    cout<< "2.ѡ����������"<< endl;
    cout<< "3.ð����������"<< endl;
    cout<< "4.�۰����򣨽���"<< endl;
    cout<< "0.�����ϼ��˵�"<< endl;
    cout<< "**********************"<< endl;
    cout<< "����ѡ��Ĺ����ǣ�";
}
void menu3()
{
    cout<< "**********************"<< endl;
    cout<< "��ѡ������Ҫ�Ĺ���"<< endl;
    cout<< "1.˳�����"<< endl;
    cout<< "2.�۰����"<< endl;
    cout<< "0.�����ϼ��˵�"<< endl;
    cout<< "**********************"<< endl;
    cout<< "����ѡ��Ĺ����ǣ�";
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

            default:printf("������0-3֮�������");//����û����벻��0-4֮����ʾ
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

            default:printf("������0-4֮�������");//����û����벻��0-4֮����ʾ
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

            default:printf("������0-2֮�������");//����û����벻��0-4֮����ʾ
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
    system("Pause");//��ͣ
    system("cls");//����
    G1();
}
void F2()
{
    run2();
    system("Pause");//��ͣ
    system("cls");//����
    G1();
}
void F3()
{
    run3();
    system("Pause");//��ͣ
    system("cls");//����
    G1();
}

void F4()
{
    run4();
    system("Pause");//��ͣ
    system("cls");//����
    G1();
}


void S1()
{
    run5_1();
    system("Pause");//��ͣ
    system("cls");//����
    G1();
}


void S2()
{
    run6_1();
    system("Pause");//��ͣ
    system("cls");//����
    G1();
}

void H2()
{

    system("Pause");//��ͣ
    system("cls");//����
    G1();
}



