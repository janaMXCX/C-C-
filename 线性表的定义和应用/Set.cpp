#include "Set.h"
#include "sqlist.h"
#include "linklist.h"
#include "sqlist2.h"
#include "linklist2.h"

//����˵�
void menu()
{
    printf("\n\n");
    printf("******��ӭʹ�����¹���******\n");
    printf("1.���Ա�ϲ�\n");
    printf("2.�����ϲ�\n");
    printf("3.ϡ�����ʽ�ӷ���˳���\n");
    printf("3.ϡ�����ʽ�ӷ���������\n");
    printf("��ѡ�����ݽṹ���ͣ�");
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
            case 1: SqListSettings();
                    break;
            case 2: SqListSettings2();
                    break;
            case 3: LinkListSettings();
                    break;
            case 4: LinkListSettings2();
                    break;
            default:printf("������0-4֮�������");//����û����벻��0-5֮����ʾ
        }
        if (n==0) break;
    }
}
void SqListSettings()
{
    SetList();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
void SqListSettings2()
{
    CreateList_H2();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
void LinkListSettings()
{
    setsqlist();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
void LinkListSettings2()
{
    SetLinkList();
    system("Pause");//��ͣ
    system("cls");//����
    menu();
}
