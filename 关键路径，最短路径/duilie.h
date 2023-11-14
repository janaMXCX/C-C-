#include "Set.h"


#define MAXQSIZE 100
typedef struct {
   int *base;
   int front;
   int rear;
} SqQueue;


void InitQueue(SqQueue &Q);//初始化队列
void EnQueue(SqQueue &Q, int p); // 入队操作
void DeQueue(SqQueue &Q, int &p);// 出队操作

bool QueueEmpty(SqQueue Q);//判断队列是否为空

int GetHead(SqQueue Q);//获取队头元素
