#include"dance.h"

SqQueue Mdancers; // ��
SqQueue Fdancers; // Ů

// ��ʼ������
void InitQueue(SqQueue &Q) {
    Q.base = new Person[MAXQSIZE];
    Q.front = Q.rear = 0;
}
//��Ӳ���
void EnQueue(SqQueue &Q, Person p) {
    if ((Q.rear + 1) % MAXQSIZE == Q.front) {
        // �������������Ը���������Ӵ������߼�
        return;
    }
    Q.base[Q.rear] = p;
    Q.rear = (Q.rear + 1) % MAXQSIZE;
}
// ���Ӳ���
void DeQueue(SqQueue &Q, Person &p) {
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
Person GetHead(SqQueue Q) {
    return Q.base[Q.front];
}

void DancePartner(Person dancer[],int num)//�������
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
    printf("��ӳɹ�����:\n");
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
        printf("��һ���ҵ�����Ůʿ��:%s\n",p.name);
    }
    else if(!QueueEmpty(Mdancers))
    {
        p=GetHead(Mdancers);
        printf("��һ���ҵ�������ʿ��:%s\n",p.name);
    }
}
void dance()
{
    Person dancer[MAXQSIZE];
    int i,num;
    printf("������������������\n");
    scanf("%d",&num);
    printf("������������ߵ��������Ա�'F'��ʾŮ�ԣ�'M'��ʾ���ԣ���\n");
    for(i=0;i<num;i++)
    {
        printf("�������%d�����ߵ��������Ա𣨿ո��������\n",i+1);
        scanf("%s %c",&dancer[i].name,&dancer[i].sex);
    }
    DancePartner(dancer,num);
}
