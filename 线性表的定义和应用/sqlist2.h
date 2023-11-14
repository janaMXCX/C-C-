#include "Set.h"

typedef struct data{
        float coef;   //系数
        int expn;     //指数
}data;  //定义数值
typedef struct SqList2{
        data * elem;
        int length;
}SqList2; //定义顺序表

//创建任务
void setsqlist();
// 初始化顺序表
void initSqList(SqList2* L, int size);
//清除内存
void destroySqList(SqList2* L);
// 多项式加法
SqList2 polynomialAddition(SqList2 A, SqList2 B);
// 添加元素到顺序表
void addElement(SqList2* L, float coef, int expn);
