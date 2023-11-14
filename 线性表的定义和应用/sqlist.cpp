#include "sqlist.h"

//初始化操作
Status InitList(SqList &L)
{
    L.elem = new int[MAXSIXE];
    L.length = 0;
    return OK;
}
//取值
int GetList(SqList L,int i,int &e)
{
    if(i<1||i>L.length) return ERROR;

    e = L.elem[i-1];

    return OK;
}
//查找
int LocateElem(SqList L,int e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.elem[i]==e) return i+1;
    }
    return 0;
}
//插入
int ListInsert(SqList &L, int i,int e)
{
    if((i<1)||(i>L.length+1)) return ERROR;
    if (L.length==MAXSIXE) return ERROR;
    for(int j=L.length-1;j>=i-1;j--)
        L.elem[j+1]=L.elem[j];
    L.elem[i-1]=e;
    ++L.length;
    return OK;
}
//删除
int ListDelete(SqList &L,int i)
{
    if((i<1)||(i>L.length+1)) return ERROR;
    for(int j=i;j<L.length-1;j++)
    {
        L.elem[j-1]=L.elem[j];
    }
    --L.length;
    return OK;
}
//取长度
int ListLength(SqList &L)
{
    int i;
    i = L.length;
    return i;
}


//合并
void MergeList(SqList &LA, SqList LB)
{
    int m = ListLength(LA);
    int n = ListLength(LB);

    for (int i = 1; i <= n; i++)
    {
        int e;
        GetList(LB, i, e);
        if (!LocateElem(LA, e))
            ListInsert(LA, m + 1, e);
    }

    printf("合并之后的数组为：");
    for (int i = 1; i <= ListLength(LA); i++)
    {
        int e;
        GetList(LA, i, e);
        printf("%d ", e);
    }
    printf("\n");
}

int SetList()
{
    SqList LA;
    InitList(LA);

    SqList LB;
    InitList(LB);

    printf("第一个数组\n");
    int option;
    int m,n;
    printf("请输入第一个数组中数据的个数：");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        option = 0;
        scanf("%d", &option);
        ListInsert(LA, i + 1, option);
    }

    printf("第二个数组\n");
    printf("请输入第而个数组中数据的个数：");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        option = 0;
        scanf("%d", &option);
        ListInsert(LB, i + 1, option);
    }

    MergeList(LA,LB);
    return OK;
}

//顺序有序表的合并

void MergeList_Sq(const SqList &LA, const SqList &LB, SqList &LC)
{
    // 顺序有序表 LA 和 LB 的元素按照非递减排列
    LC.length = LA.length + LB.length;
    LC.elem = new int[LC.length];
    int *pc = LC.elem; // 指向 LC 的指针
    const int *pa = LA.elem; // 指向 LA 的指针
    const int *pb = LB.elem; // 指向 LB 的指针
    const int *pa_last = LA.elem + LA.length - 1; // LA 的最后一个元素的指针
    const int *pb_last = LB.elem + LB.length - 1; // LB 的最后一个元素的指针

    while ((pa <= pa_last) && (pb <= pb_last))
    {
        if (*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }

    while (pa <= pa_last)
        *pc++ = *pa++;

    while (pb <= pb_last)
        *pc++ = *pb++;
        printf("合并之后的数组为：");
    for (int i = 1; i <= ListLength(LC); i++)
    {
        int e;
        GetList(LC, i, e);
        printf("%d ", e);
    }
    printf("\n");
}













