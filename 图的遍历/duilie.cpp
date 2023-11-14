
#include "Set.h"

// ��ʼ������
void InitQueue(SqQueue &Q) {
    Q.base = new int[MAXQSIZE];
    Q.front = Q.rear = 0;
}
//��Ӳ���
void EnQueue(SqQueue &Q, int p) {
    if ((Q.rear + 1) % MAXQSIZE == Q.front) {
        // �������������Ը���������Ӵ������߼�
        return;
    }
    Q.base[Q.rear] = p;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
}
// ���Ӳ���
void DeQueue(SqQueue &Q, int &p) {
    if (Q.front == Q.rear) {
        // ����Ϊ�գ����Ը���������Ӵ������߼�
        return;
    }
    p = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
}
// �ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}


// ��ȡ��ͷԪ��
int GetHead(SqQueue Q) {
    return Q.base[Q.front];
}
