#include "linklist2.h"

//��������ʽ
void CreatePolyn(Polynomial &p,int n)
{
    p = new PNode;
    p->next = NULL;

    PNode* s;
    PNode* pre, * q; //�Ժ����м��õ���ָ����з���

    for(int i=1;i<=n;++i)//ѭ��д�����ݣ��������
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
//����ʽ�ļӷ�
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
// �ͷ��ڴ�
void DestroyLinkList(Polynomial* A) {
    while (*A != NULL) {
        struct PNode* temp = *A;
        *A = (*A)->next;
        free(temp);
    }
}
// ��ȡ����ʽ�ĳ���
int GetPolynomialLength(Polynomial poly) {
    int length = 0;
    PNode* current = poly->next;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

//���봴��
void SetLinkList()
 {  Polynomial A=NULL, B=NULL;
    int sizeA, sizeB;

    printf("���������ʽA������: ");
    scanf("%d", &sizeA);
    printf("���������ʽA�ĸ��ϵ����ָ�����м����ÿո���м����:\n");
    CreatePolyn(A, sizeA);

    printf("���������ʽB������: ");
    scanf("%d", &sizeB);
    printf("���������ʽB�ĸ��ϵ����ָ�����м����ÿո���м����:\n");
    CreatePolyn(B, sizeB);

    AddPolyn(A, B);
    int m = 0;
    m=GetPolynomialLength(A);

    printf("�������ʽ��ϵ����ָ����:\n");
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
