
#include "Set.h"

// 初始化队列
void InitQueue(SqQueue &Q) {
    Q.base = new int[MAXQSIZE];
    Q.front = Q.rear = 0;
}
//入队操作
void EnQueue(SqQueue &Q, int p) {
    if ((Q.rear + 1) % MAXQSIZE == Q.front) {
        // 队列已满，可以根据需求添加错误处理逻辑
        return;
    }
    Q.base[Q.rear] = p;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
}
// 出队操作
void DeQueue(SqQueue &Q, int &p) {
    if (Q.front == Q.rear) {
        // 队列为空，可以根据需求添加错误处理逻辑
        return;
    }
    p = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
}
// 判断队列是否为空
bool QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}


// 获取队头元素
int GetHead(SqQueue Q) {
    return Q.base[Q.front];
}
