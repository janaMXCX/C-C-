#include "Set.h"
#include "pathlong.h"
void menu()
{
    cout<< "**********************"<< endl;
    cout<< "��ѡ������Ҫ�Ĺ���"<< endl;
    cout<< "1.������������"<< endl;
    cout<< "2.���ÿ���ַ��Ĺ���������"<< endl;
    cout<< "3.������������Ĵ�Ȩ·�����ȣ������"<< endl;
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
            case 3: run_third();
                    break;
            case 0: break;

            default:printf("������0-3֮�������");//����û����벻��0-3֮����ʾ
        }
        if (n==0) break;
    }
}


void run_first()
{
    run();
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
void run_third()
{
    run3();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
