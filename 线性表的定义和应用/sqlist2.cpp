#include "sqlist2.h"


// ��ʼ��˳���
void initSqList(SqList2* L, int size)
{
    L->elem = new data[size]; // ʹ��new�����ڴ�
    L->length = 0;
}
// ���Ԫ�ص�˳���
void addElement(SqList2* L, float coef, int expn) {
    L->elem[L->length].coef = coef; // �洢ϵ��
    L->elem[L->length].expn = expn; // �洢ָ��
    L->length++; // ����˳���ĳ���
}
// ����ʽ�ӷ�
SqList2 polynomialAddition(SqList2 A, SqList2 B) {
    SqList2 result;
    initSqList(&result, A.length + B.length); // ��ʼ�����˳�����СΪ��������ʽ����֮��

    int i = 0, j = 0;

    while (i < A.length && j < B.length) {
        if (A.elem[i].expn == B.elem[j].expn) {
            float sum = A.elem[i].coef + B.elem[j].coef; // ϵ�����
            if (sum != 0) {
                addElement(&result, sum, A.elem[i].expn); // �������ӵ��������ʽ��
            }
            i++;
            j++;
        } else if (A.elem[i].expn < B.elem[j].expn) {
            addElement(&result, A.elem[i].coef, A.elem[i].expn); // ��A�ĵ�ǰ����ӵ��������ʽ��
            i++;
        } else {
            addElement(&result, B.elem[j].coef, B.elem[j].expn); // ��B�ĵ�ǰ����ӵ��������ʽ��
            j++;
        }
    }

    while (i < A.length) {
        addElement(&result, A.elem[i].coef, A.elem[i].expn); // ��A��ʣ������ӵ��������ʽ��
        i++;
    }

    while (j < B.length) {
        addElement(&result, B.elem[j].coef, B.elem[j].expn); // ��B��ʣ������ӵ��������ʽ��
        j++;
    }

    return result; // ���ؽ������ʽ
}
// �ͷ�˳�����ڴ�
void destroySqList(SqList2* L) {
    free(L->elem); // �ͷ��ڴ�
    L->length = 0; // ������Ϊ0
}

//��������
void setsqlist()
{
    SqList2 A,B;
    int sizeA, sizeB;

    printf("����A�е�����������");
    scanf("%d", &sizeA);
    initSqList(&A, sizeA); // ��ʼ������ʽA��˳���

     printf("����Ҫ��䵽A�е����ݣ��м����ÿո���м������\n");
    for (int i = 0; i < sizeA; i++) {
        float coef;
        int expn;
        scanf("%f %d", &coef, &expn);
        addElement(&A, coef, expn); // ��Ӷ���ʽA���˳�����
    }

    printf("����B�е���������");
    scanf("%d", &sizeB);
    initSqList(&B, sizeB); // ��ʼ������ʽB��˳���

    printf("����Ҫ��䵽B�е����ݣ��м����ÿո���м������\n");
    for (int i = 0; i < sizeB; i++) {
        float coef;
        int expn;
        scanf("%f %d", &coef, &expn);
        addElement(&B, coef, expn); // ��Ӷ���ʽB���˳�����
    }

    SqList2 result = polynomialAddition(A, B); // ���ж���ʽ�ӷ�

    printf("�������ʽ��ϵ����ָ������\n");

    for (int i = 0; i < result.length; i++) {
        printf("%.2fX^%d", result.elem[i].coef, result.elem[i].expn); // ����������ʽ����
        if(i<result.length-1){
            printf("+");
        }
    }


    // �ͷ��ڴ�
    destroySqList(&A);
    destroySqList(&B);
    destroySqList(&result);
}




