#include "Set.h"
void menu()
{
    printf("**********************\n");
    printf("��ѡ������Ҫ�Ĺ���\n");
    printf("1.����ת��\n");
    printf("2.���ʽ��ֵ\n");
    printf("3.�����������\n");
    printf("**********************\n");
    printf("����ѡ��Ĺ����ǣ�");
}

//ѡ��˵�����
void select_menu()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        switch(n)
        {
            case 1: Conversion_first();
                    break;
            case 2: Operation_first();
                    break;
            case 3: Dance_first();
                    break;
            default:printf("������0-3֮�������");//����û����벻��0-3֮����ʾ
        }
        if (n==0) break;
    }
}


void Conversion_first()
{
    Conversion_Run();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
void Operation_first()
{
    operation();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
void Dance_first()
{
    dance();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}

