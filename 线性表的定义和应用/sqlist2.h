#include "Set.h"

typedef struct data{
        float coef;   //ϵ��
        int expn;     //ָ��
}data;  //������ֵ
typedef struct SqList2{
        data * elem;
        int length;
}SqList2; //����˳���

//��������
void setsqlist();
// ��ʼ��˳���
void initSqList(SqList2* L, int size);
//����ڴ�
void destroySqList(SqList2* L);
// ����ʽ�ӷ�
SqList2 polynomialAddition(SqList2 A, SqList2 B);
// ���Ԫ�ص�˳���
void addElement(SqList2* L, float coef, int expn);
