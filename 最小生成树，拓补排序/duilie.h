#include "Set.h"


#define MAXQSIZE 100
typedef struct {
   int *base;
   int front;
   int rear;
} SqQueue;


void InitQueue(SqQueue &Q);//��ʼ������
void EnQueue(SqQueue &Q, int p); // ��Ӳ���
void DeQueue(SqQueue &Q, int &p);// ���Ӳ���

bool QueueEmpty(SqQueue Q);//�ж϶����Ƿ�Ϊ��

int GetHead(SqQueue Q);//��ȡ��ͷԪ��
