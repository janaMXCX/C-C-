#include "Set.h"

void menu()
{
    cout<< "**********************"<< endl;
    cout<< "��ѡ������Ҫ�Ĺ���"<< endl;
    cout<< "1.������ȱ������ڽӾ���"<< endl;
    cout<< "2.������ȱ������ڽӱ�"<< endl;
    cout<< "3.������ȱ������ڽӾ���"<< endl;
    cout<< "4.������ȱ������ڽӱ�"<< endl;
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
            case 4: run_fourth();
                    break;
            case 0: break;

            default:printf("������0-4֮�������");//����û����벻��0-4֮����ʾ
        }
        if (n==0) break;
    }
}


void run_first()
{
    matrix_deep();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
void run_second()
{
    table_deep();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
void run_third()
{
    matrix_wide();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
void run_fourth()
{
    table_wide();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
