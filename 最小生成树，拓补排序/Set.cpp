#include "Set.h"

void menu()
{
    cout<< "**********************"<< endl;
    cout<< "��ѡ������Ҫ�Ĺ���"<< endl;
    cout<< "1.������С��������prim�㷨��"<< endl;
    cout<< "2.��֪����ͼ���������������"<< endl;
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
            case 1: run_first();
                    break;
            case 2: run_second();
                    break;
            case 0: break;

            default:printf("������0-4֮�������");//����û����벻��0-4֮����ʾ
        }
        if (n==0) break;
    }
}


void run_first()
{
    run1();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
void run_second()
{
    run2();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}

