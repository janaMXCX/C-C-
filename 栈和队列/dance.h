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
}Person;//队列顺序储存

#define MAXQSIZE 100
typedef struct {
   Person *base;
   int front;
   int rear;
} SqQueue;



void InitQueue(SqQueue &Q);//初始化队列
void EnQueue(SqQueue &Q, Person p); // 入队操作
void DeQueue(SqQueue &Q, Person &p);// 出队操作

bool QueueEmpty(SqQueue Q);//判断队列是否为空

Person GetHead(SqQueue Q);//获取队头元素
void DancePartner(Person dancer[],int num);


#endif // DANCE_H_INCLUDED





