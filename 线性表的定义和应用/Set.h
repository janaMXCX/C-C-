#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

//===========函数声明==========
//定义菜单
void menu();
void select_menu();

//线性表合并
void SqListSettings();
//有序表合并
void SqListSettings2();
//稀疏多项式加法（顺序表）
void LinkListSettings();
//稀疏多项式加法（单链表）
void LinkListSettings2();


#endif // MENU_H_INCLUDED
