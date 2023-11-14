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
 *          佛祖保佑             永无BUG
 */

#include "linklist.h"

//初始化

Status InitList2(LinkList &L)
{//构造一个空的单链表L
    L = new LNode;
    L->next = NULL;
    return OK;
}
//以下为基本操作页面
//取值
Status GetElem(LinkList L, int i, int &e)
{
    int j;
    //首先，检查链表是否为空
    if (L == NULL || L->next == NULL)
    {
        return ERROR;//链表为空,无法获取元素
    }

    LinkList p = L->next; //p指向链表的第一个节点
    j = 1;

    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    //如果p为空，说明链表长度小于i，或者i小于等于0
    if (!p || j > i)
    {
        return ERROR;
    }

    e = p->data; //将找到的元素值赋给e
    return OK; //成功找到并返回元素
}


//查找
LNode *LocateElem2(LinkList L,int i, int &e)
{
    LinkList p = L->next; //p指向链表的第一个节点
    p=L->next;
    while(p && p->data != e)
    {
        p=p->next;
    }
    return p;
}

//插入
Status ListInsert2(LinkList &L, int i, int e)
{
    int j;
    LinkList p = L; // 从头节点开始查找
    j = 0;

    while (p && (j < i - 1))
    {
        p = p->next;
        ++j;
    }

    // 如果p为空，说明链表长度小于i-1，或者i小于等于0
    if (!p || (j > i - 1))
    {
        return ERROR; // 插入位置无效，返回错误状态
    }

    LinkList s = new LNode; // 创建新节点s
    if (!s)
    {
        return ERROR; // 内存分配失败，返回错误状态
    }

    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK; // 插入成功，返回成功状态
}

//删除
Status ListDelete2(LinkList &L, int i)
{
    int j;
    LinkList p = L; // 从头节点开始查找
    j = 0;

    while ((p->next) && (j < i - 1))
    {
        p = p->next;
        ++j;
    }

    // 如果p->next为空，说明链表长度小于i，或者i小于等于0
    if (!(p->next) || (j > i - 1))
    {
        return ERROR; // 删除位置无效，返回错误状态
    }

    LinkList q = p->next; // 将要删除的节点赋给q
    p->next = q->next;   // 调整指针，删除节点
    delete q;            // 释放内存

    return OK; // 删除成功，返回成功状态
}

//往链表之中加入数据
void CreateList_H(LinkList &L, int n, int dataArray[])
{
    L = new LNode;
    L->next = NULL;
    LinkList p;

    for (int i = 0; i < n; ++i)
    {
        p = new LNode; // 为新节点分配内存
        p->data = dataArray[i]; // 使用数组中的数据
        p->next = L->next;
        L->next = p;
    }
}
//读取链表大小的函数（散发怨气）
int GetListLength(LinkList L) {
    int length = 0; // 初始化长度为0
    LinkList p = L->next; // 从链表的第一个节点开始

    while (p != NULL) {
        length++; // 每遍历一个节点，长度加1
        p = p->next; // 移动到下一个节点
    }

    return length;
}
//有序表的合并（链表的合并）
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




//创建
void CreateList_H2()
{
    // 定义要插入链表的数据数组
    int dataArrayA[100];
    int dataArrayB[100];
    int dataArrayC[100];

    // 这个位置是输入之后写
    int n = 0; // n表示要插入的数据元素数量
    printf("请输入要插入的数据元素数量：");
    scanf("%d", &n);
    printf("请输入 %d 个整数：\n", n);
    for (int i = 0; i < n; ++i) {
        printf("输入第 %d 个元素：", i + 1);
        scanf("%d", &dataArrayA[i]);
    }
    int m = 0; // m表示要插入的数据元素数量
    printf("请输入要插入的数据元素数量：");
    scanf("%d", &m);
    printf("请输入 %d 个整数：\n", m);
    for (int i = 0; i < m; ++i) {
        printf("输入第 %d 个元素：", i + 1);
        scanf("%d", &dataArrayB[i]);
    }

    LinkList LA;
    LinkList LB;


    InitList2(LA);
    InitList2(LB);


    // 使用 GetListLength 获取链表长度
    int a = GetListLength(LA);
    int b = GetListLength(LB);

    // 创建链表 LA
    CreateList_H(LA, n, dataArrayA);
    // 创建链表 LB
    CreateList_H(LB, m, dataArrayB);

    MergeList_L(LA, LB);

    LinkList pLC = LA->next; // 从第一个节点开始
    printf("链表 LA 的数据：\n");
    while (pLC != NULL) {
        printf("%d ", pLC->data);
        pLC = pLC->next;
    }
}










