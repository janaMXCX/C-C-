#ifndef DANCE_H_INCLUDED
#define DANCE_H_INCLUDED
#include <iostream>
#define MAXQSIZE 100

void dance();
using namespace std;
typedef struct
{
    char name[20];
    char sex;
}Person;//����˳�򴢴�

#define MAXQSIZE 100
typedef struct {
   Person *base;
   int front;
   int rear;
} SqQueue;



void InitQueue(SqQueue &Q);//��ʼ������
void EnQueue(SqQueue &Q, Person p); // ��Ӳ���
void DeQueue(SqQueue &Q, Person &p);// ���Ӳ���

bool QueueEmpty(SqQueue Q);//�ж϶����Ƿ�Ϊ��

Person GetHead(SqQueue Q);//��ȡ��ͷԪ��
void DancePartner(Person dancer[],int num);


#endif // DANCE_H_INCLUDED





