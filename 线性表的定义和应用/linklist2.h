#include "Set.h"


typedef struct PNode{
        float coef;   //系数
        int expn;     //指数
        struct PNode * next;//指针
}PNode,*Polynomial;


//创建多项式
void CreatePolyn(Polynomial &p,int n);
//多项式的加法
void AddPolyn(Polynomial &Pa,Polynomial &Pb);
// 释放内存
void DestroyLinkList(Polynomial &A);
//输入创建
void SetLinkList();

int GetPolynomialLength(Polynomial poly);
