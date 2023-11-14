#include "linklist2.h"

//创建多项式
void CreatePolyn(Polynomial &p,int n)
{
    p = new PNode;
    p->next = NULL;

    PNode* s;
    PNode* pre, * q; //对函数中间用到的指针进行分配

    for(int i=1;i<=n;++i)//循环写入数据，组成链表
    {
        s = new PNode;
        scanf("%f %d", &(s->coef), &(s->expn));
        pre = p;
        q = p->next;
        while(q&&q->expn<s->expn)
        {
            pre = q;
            q=q->next;
        }
        s->next = q;
        pre->next = s;
    }
}
//多项式的加法
void AddPolyn(Polynomial &Pa,Polynomial &Pb)
{
    PNode* p1 = Pa->next;
    PNode* p2 = Pb->next;
    PNode* p3 = Pa;
    PNode* r;
    float sum;

    while(p1&&p2)
    {
        if(p1->expn==p2->expn)
        {
            sum=p1->coef+p2->coef;
            if(sum!=0)
            {
                p1->coef = sum;
                p3->next = p1;
                p3 = p1;
                p1 = p1->next;
                r = p2; p2 = p2->next;
                delete r;
            }
            else
            {
                r = p1; p1 = p1->next; delete r;
                r = p2; p2 = p2->next; delete r;
            }
        }
        else if(p1->expn<p2->expn)
        {
            p3->next = p1;
            p3 = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p3 = p2;
            p2 = p2->next;
        }
    }
    p3->next = p1?p1:p2;
}
// 释放内存
void DestroyLinkList(Polynomial* A) {
    while (*A != NULL) {
        struct PNode* temp = *A;
        *A = (*A)->next;
        free(temp);
    }
}
// 获取多项式的长度
int GetPolynomialLength(Polynomial poly) {
    int length = 0;
    PNode* current = poly->next;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

//输入创建
void SetLinkList()
 {  Polynomial A=NULL, B=NULL;
    int sizeA, sizeB;

    printf("请输入多项式A的项数: ");
    scanf("%d", &sizeA);
    printf("请输入多项式A的各项（系数和指数，中间请用空格进行间隔）:\n");
    CreatePolyn(A, sizeA);

    printf("请输入多项式B的项数: ");
    scanf("%d", &sizeB);
    printf("请输入多项式B的各项（系数和指数，中间请用空格进行间隔）:\n");
    CreatePolyn(B, sizeB);

    AddPolyn(A, B);
    int m = 0;
    m=GetPolynomialLength(A);

    printf("结果多项式（系数和指数）:\n");
    PNode* current = A->next;
    int i = 0;
    while (current != NULL) {
        i++;
        printf("%.2fX^%d", current->coef, current->expn);
        current = current->next;
        if(i<m){
            printf("+");
        }
    }
    DestroyLinkList(&A);
 }
