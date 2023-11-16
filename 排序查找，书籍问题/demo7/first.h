#include "Set.h"

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct
{
    int *elem;
    int length;
}SqList;

// 定义书籍结构体
struct Book {
    string name;
    double price;
};

void run1();
void run2();
void run3();
void run4();
void run5(SqList &L);
void run6(SqList &L);
void run5_1();
void run6_1();
void run_final();
