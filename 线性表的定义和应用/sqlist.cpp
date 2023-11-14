#include "sqlist.h"

//��ʼ������
Status InitList(SqList &L)
{
    L.elem = new int[MAXSIXE];
    L.length = 0;
    return OK;
}
//ȡֵ
int GetList(SqList L,int i,int &e)
{
    if(i<1||i>L.length) return ERROR;

    e = L.elem[i-1];

    return OK;
}
//����
int LocateElem(SqList L,int e)
{
    for(int i=0;i<L.length;i++)
    {
        if(L.elem[i]==e) return i+1;
    }
    return 0;
}
//����
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
//ɾ��
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
//ȡ����
int ListLength(SqList &L)
{
    int i;
    i = L.length;
    return i;
}


//�ϲ�
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

    printf("�ϲ�֮�������Ϊ��");
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

    printf("��һ������\n");
    int option;
    int m,n;
    printf("�������һ�����������ݵĸ�����");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        option = 0;
        scanf("%d", &option);
        ListInsert(LA, i + 1, option);
    }

    printf("�ڶ�������\n");
    printf("������ڶ������������ݵĸ�����");
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

//˳�������ĺϲ�

void MergeList_Sq(const SqList &LA, const SqList &LB, SqList &LC)
{
    // ˳������� LA �� LB ��Ԫ�ذ��շǵݼ�����
    LC.length = LA.length + LB.length;
    LC.elem = new int[LC.length];
    int *pc = LC.elem; // ָ�� LC ��ָ��
    const int *pa = LA.elem; // ָ�� LA ��ָ��
    const int *pb = LB.elem; // ָ�� LB ��ָ��
    const int *pa_last = LA.elem + LA.length - 1; // LA �����һ��Ԫ�ص�ָ��
    const int *pb_last = LB.elem + LB.length - 1; // LB �����һ��Ԫ�ص�ָ��

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
        printf("�ϲ�֮�������Ϊ��");
    for (int i = 1; i <= ListLength(LC); i++)
    {
        int e;
        GetList(LC, i, e);
        printf("%d ", e);
    }
    printf("\n");
}













