#include "Set.h"


typedef struct PNode{
        float coef;   //ϵ��
        int expn;     //ָ��
        struct PNode * next;//ָ��
}PNode,*Polynomial;


//��������ʽ
void CreatePolyn(Polynomial &p,int n);
//����ʽ�ļӷ�
void AddPolyn(Polynomial &Pa,Polynomial &Pb);
// �ͷ��ڴ�
void DestroyLinkList(Polynomial &A);
//���봴��
void SetLinkList();

int GetPolynomialLength(Polynomial poly);
