/*
 *                    _ooOoo_
 *                   o8888888o
 *                   88" . "88
 *                   (| -_- |)
 *                    O\ = /O
 *                ____/`---'\____
 *              .   ' \\| |// `.
 *               / \\||| : |||// \
 *             / _||||| -:- |||||- \
 *               | | \\\ - /// | |
 *             | \_| ''\---/'' | |
 *              \ .-\__ `-` ___/-. /
 *           ___`. .' /--.--\ `. . __
 *        ."" '< `.___\_<|>_/___.' >'"".
 *       | | : `- \`.;`\ _ /`;.`/ - ` : | |
 *         \ \ `-. \_ __\ /__ _/ .-` / /
 * ======`-.____`-.___\_____/___.-`____.-'======
 *                    `=---='
 *
 * .............................................
 *          ���汣��             ����BUG
 */

#include "linklist.h"

//��ʼ��

Status InitList2(LinkList &L)
{//����һ���յĵ�����L
    L = new LNode;
    L->next = NULL;
    return OK;
}
//����Ϊ��������ҳ��
//ȡֵ
Status GetElem(LinkList L, int i, int &e)
{
    int j;
    //���ȣ���������Ƿ�Ϊ��
    if (L == NULL || L->next == NULL)
    {
        return ERROR;//����Ϊ��,�޷���ȡԪ��
    }

    LinkList p = L->next; //pָ������ĵ�һ���ڵ�
    j = 1;

    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    //���pΪ�գ�˵��������С��i������iС�ڵ���0
    if (!p || j > i)
    {
        return ERROR;
    }

    e = p->data; //���ҵ���Ԫ��ֵ����e
    return OK; //�ɹ��ҵ�������Ԫ��
}


//����
LNode *LocateElem2(LinkList L,int i, int &e)
{
    LinkList p = L->next; //pָ������ĵ�һ���ڵ�
    p=L->next;
    while(p && p->data != e)
    {
        p=p->next;
    }
    return p;
}

//����
Status ListInsert2(LinkList &L, int i, int e)
{
    int j;
    LinkList p = L; // ��ͷ�ڵ㿪ʼ����
    j = 0;

    while (p && (j < i - 1))
    {
        p = p->next;
        ++j;
    }

    // ���pΪ�գ�˵��������С��i-1������iС�ڵ���0
    if (!p || (j > i - 1))
    {
        return ERROR; // ����λ����Ч�����ش���״̬
    }

    LinkList s = new LNode; // �����½ڵ�s
    if (!s)
    {
        return ERROR; // �ڴ����ʧ�ܣ����ش���״̬
    }

    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK; // ����ɹ������سɹ�״̬
}

//ɾ��
Status ListDelete2(LinkList &L, int i)
{
    int j;
    LinkList p = L; // ��ͷ�ڵ㿪ʼ����
    j = 0;

    while ((p->next) && (j < i - 1))
    {
        p = p->next;
        ++j;
    }

    // ���p->nextΪ�գ�˵��������С��i������iС�ڵ���0
    if (!(p->next) || (j > i - 1))
    {
        return ERROR; // ɾ��λ����Ч�����ش���״̬
    }

    LinkList q = p->next; // ��Ҫɾ���Ľڵ㸳��q
    p->next = q->next;   // ����ָ�룬ɾ���ڵ�
    delete q;            // �ͷ��ڴ�

    return OK; // ɾ���ɹ������سɹ�״̬
}

//������֮�м�������
void CreateList_H(LinkList &L, int n, int dataArray[])
{
    L = new LNode;
    L->next = NULL;
    LinkList p;

    for (int i = 0; i < n; ++i)
    {
        p = new LNode; // Ϊ�½ڵ�����ڴ�
        p->data = dataArray[i]; // ʹ�������е�����
        p->next = L->next;
        L->next = p;
    }
}
//��ȡ�����С�ĺ�����ɢ��Թ����
int GetListLength(LinkList L) {
    int length = 0; // ��ʼ������Ϊ0
    LinkList p = L->next; // ������ĵ�һ���ڵ㿪ʼ

    while (p != NULL) {
        length++; // ÿ����һ���ڵ㣬���ȼ�1
        p = p->next; // �ƶ�����һ���ڵ�
    }

    return length;
}
//�����ĺϲ�������ĺϲ���
void MergeList_L(LinkList &LA, LinkList &LB)
{
    LinkList pa = LA;
    LinkList pb = LB->next;

    while (pb)
    {
        while (pa->next && pa->next->data <= pb->data)
        {
            pa = pa->next;
        }

        if (!pa->next || pa->next->data != pb->data)
        {
            LinkList newNode = new LNode;
            newNode->data = pb->data;
            newNode->next = pa->next;
            pa->next = newNode;
        }

        pb = pb->next;
    }
}




//����
void CreateList_H2()
{
    // ����Ҫ�����������������
    int dataArrayA[100];
    int dataArrayB[100];
    int dataArrayC[100];

    // ���λ��������֮��д
    int n = 0; // n��ʾҪ���������Ԫ������
    printf("������Ҫ���������Ԫ��������");
    scanf("%d", &n);
    printf("������ %d ��������\n", n);
    for (int i = 0; i < n; ++i) {
        printf("����� %d ��Ԫ�أ�", i + 1);
        scanf("%d", &dataArrayA[i]);
    }
    int m = 0; // m��ʾҪ���������Ԫ������
    printf("������Ҫ���������Ԫ��������");
    scanf("%d", &m);
    printf("������ %d ��������\n", m);
    for (int i = 0; i < m; ++i) {
        printf("����� %d ��Ԫ�أ�", i + 1);
        scanf("%d", &dataArrayB[i]);
    }

    LinkList LA;
    LinkList LB;


    InitList2(LA);
    InitList2(LB);


    // ʹ�� GetListLength ��ȡ������
    int a = GetListLength(LA);
    int b = GetListLength(LB);

    // �������� LA
    CreateList_H(LA, n, dataArrayA);
    // �������� LB
    CreateList_H(LB, m, dataArrayB);

    MergeList_L(LA, LB);

    LinkList pLC = LA->next; // �ӵ�һ���ڵ㿪ʼ
    printf("���� LA �����ݣ�\n");
    while (pLC != NULL) {
        printf("%d ", pLC->data);
        pLC = pLC->next;
    }
}










