#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

//===========��������==========
//����˵�
void menu();
void select_menu();

//���Ա�ϲ�
void SqListSettings();
//�����ϲ�
void SqListSettings2();
//ϡ�����ʽ�ӷ���˳���
void LinkListSettings();
//ϡ�����ʽ�ӷ���������
void LinkListSettings2();


#endif // MENU_H_INCLUDED
