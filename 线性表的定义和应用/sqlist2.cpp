#include "sqlist2.h"


// 初始化顺序表
void initSqList(SqList2* L, int size)
{
    L->elem = new data[size]; // 使用new分配内存
    L->length = 0;
}
// 添加元素到顺序表
void addElement(SqList2* L, float coef, int expn) {
    L->elem[L->length].coef = coef; // 存储系数
    L->elem[L->length].expn = expn; // 存储指数
    L->length++; // 增加顺序表的长度
}
// 多项式加法
SqList2 polynomialAddition(SqList2 A, SqList2 B) {
    SqList2 result;
    initSqList(&result, A.length + B.length); // 初始化结果顺序表，大小为两个多项式项数之和

    int i = 0, j = 0;

    while (i < A.length && j < B.length) {
        if (A.elem[i].expn == B.elem[j].expn) {
            float sum = A.elem[i].coef + B.elem[j].coef; // 系数相加
            if (sum != 0) {
                addElement(&result, sum, A.elem[i].expn); // 将结果添加到结果多项式中
            }
            i++;
            j++;
        } else if (A.elem[i].expn < B.elem[j].expn) {
            addElement(&result, A.elem[i].coef, A.elem[i].expn); // 将A的当前项添加到结果多项式中
            i++;
        } else {
            addElement(&result, B.elem[j].coef, B.elem[j].expn); // 将B的当前项添加到结果多项式中
            j++;
        }
    }

    while (i < A.length) {
        addElement(&result, A.elem[i].coef, A.elem[i].expn); // 将A的剩余项添加到结果多项式中
        i++;
    }

    while (j < B.length) {
        addElement(&result, B.elem[j].coef, B.elem[j].expn); // 将B的剩余项添加到结果多项式中
        j++;
    }

    return result; // 返回结果多项式
}
// 释放顺序表的内存
void destroySqList(SqList2* L) {
    free(L->elem); // 释放内存
    L->length = 0; // 长度设为0
}

//创建任务
void setsqlist()
{
    SqList2 A,B;
    int sizeA, sizeB;

    printf("输入A中的数据数量：");
    scanf("%d", &sizeA);
    initSqList(&A, sizeA); // 初始化多项式A的顺序表

     printf("输入要填充到A中的数据（中间请用空格进行间隔）：\n");
    for (int i = 0; i < sizeA; i++) {
        float coef;
        int expn;
        scanf("%f %d", &coef, &expn);
        addElement(&A, coef, expn); // 添加多项式A的项到顺序表中
    }

    printf("输入B中的数据数量");
    scanf("%d", &sizeB);
    initSqList(&B, sizeB); // 初始化多项式B的顺序表

    printf("输入要填充到B中的数据（中间请用空格进行间隔）：\n");
    for (int i = 0; i < sizeB; i++) {
        float coef;
        int expn;
        scanf("%f %d", &coef, &expn);
        addElement(&B, coef, expn); // 添加多项式B的项到顺序表中
    }

    SqList2 result = polynomialAddition(A, B); // 进行多项式加法

    printf("结果多项式（系数和指数）：\n");

    for (int i = 0; i < result.length; i++) {
        printf("%.2fX^%d", result.elem[i].coef, result.elem[i].expn); // 输出结果多项式的项
        if(i<result.length-1){
            printf("+");
        }
    }


    // 释放内存
    destroySqList(&A);
    destroySqList(&B);
    destroySqList(&result);
}




