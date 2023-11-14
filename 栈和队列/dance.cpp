#include"dance.h"

SqQueue Mdancers; // 男
SqQueue Fdancers; // 女

// 初始化队列
void InitQueue(SqQueue &Q) {
    Q.base = new Person[MAXQSIZE];
    Q.front = Q.rear = 0;
}
//入队操作
void EnQueue(SqQueue &Q, Person p) {
    if ((Q.rear + 1) % MAXQSIZE == Q.front) {
        // 队列已满，可以根据需求添加错误处理逻辑
        return;
    }
    Q.base[Q.rear] = p;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
}
// 出队操作
void DeQueue(SqQueue &Q, Person &p) {
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
Person GetHead(SqQueue Q) {
    return Q.base[Q.front];
}

void DancePartner(Person dancer[],int num)//舞伴问题
{
    Person p;
    SqQueue Mdancers,Fdancers;
    int i;
    InitQueue(Mdancers);
    InitQueue(Fdancers);
    for(i=0;i<num;i++)
    {
        p =dancer[i];
        if(p.sex=='F') EnQueue(Fdancers,p);
        else EnQueue(Mdancers,p);
    }
    printf("配队成功的是:\n");
    while(!QueueEmpty(Fdancers)&&!QueueEmpty(Mdancers))
    {
        DeQueue(Fdancers,p);
        printf("%s ",p.name);
        DeQueue(Mdancers,p);
        printf("%s\n",p.name);
    }
    if(!QueueEmpty(Fdancers))
    {
        p=GetHead(Fdancers);
        printf("第一个找到舞伴的女士是:%s\n",p.name);
    }
    else if(!QueueEmpty(Mdancers))
    {
        p=GetHead(Mdancers);
        printf("第一个找到舞伴的男士是:%s\n",p.name);
    }
}
void dance()
{
    Person dancer[MAXQSIZE];
    int i,num;
    printf("请输入跳舞总人数：\n");
    scanf("%d",&num);
    printf("请输入各个舞者的姓名和性别（'F'表示女性，'M'表示男性）：\n");
    for(i=0;i<num;i++)
    {
        printf("请输入第%d个舞者的姓名和性别（空格隔开）：\n",i+1);
        scanf("%s %c",&dancer[i].name,&dancer[i].sex);
    }
    DancePartner(dancer,num);
}
