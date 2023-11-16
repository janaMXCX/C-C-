#include "Set.h"

SqList L;

// 初始化线性表
int InitList(SqList &L) {
    L.elem = (int *)malloc(MAXSIZE * sizeof(int));
    if (!L.elem) {
        return -1;  // 内存分配失败
    }
    L.length = 0;
    return 0;  // 初始化成功
}

// 获取第i个元素的值
int GetList(SqList L, int i, int &e) {
    e = L.elem[i - 1];
    return 0;  // 获取成功
}

// 查找元素e在表中的位置
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            return i + 1;  // 返回位置（从1开始）
        }
    }
    return 0;  // 未找到元素
}

// 在第i个位置插入元素e
int ListInsert(SqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1 || L.length == MAXSIZE) {
        return -1;  // 插入位置不合法或表满
    }

    for (int j = L.length; j >= i; j--) {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i - 1] = e;
    L.length++;
    return 0;  // 插入成功
}

// 删除第i个位置的元素
int ListDelete(SqList &L, int i) {
    if (i < 1 || i > L.length) {
        return -1;  // 删除位置不合法
    }

    for (int j = i; j < L.length; j++) {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return 0;  // 删除成功
}

// 获取线性表的长度
int ListLength(SqList &L) {
    return L.length;
}
// 直接插入排序
void InsertSort(SqList &L) {
    int i, key, j;
    for (i = 1; i < L.length; i++) {
        key = L.elem[i];
        j = i - 1;

        while (j >= 0 && key > L.elem[j]) {
            L.elem[j + 1] = L.elem[j];
            j = j - 1;
        }
        L.elem[j + 1] = key;
    }
}


void run1()
{
    InitList(L);
    int option,m;
    printf("请输入数组中数据的个数：");
    scanf("%d", &m);
    printf("依次输入相应的数据:");
    L.length++;
    ListInsert(L,0,0);
    for (int i = 1; i < m+1; i++)
    {
        option = 0;
        scanf("%d", &option);
        ListInsert(L, i + 1, option);
    }
    InsertSort(L);
    printf("排序结果为：");
    for (int i = 1; i < ListLength(L); i++)
    {
        int e;
        GetList(L, i+1, e);
        printf("%d ", e);
    }
}

// 选择排序
void SelectSort(SqList &L) {

    int i, j, minIndex, temp;
    for (i = 0; i < L.length - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < L.length; j++) {
            if (L.elem[j] < L.elem[minIndex]) {
                minIndex = j;
            }
        }
        temp = L.elem[i];
        L.elem[i] = L.elem[minIndex];
        L.elem[minIndex] = temp;
    }
}

void run2()
{
    InitList(L);
    int option, m;
    printf("请输入数组中数据的个数：");
    scanf("%d", &m);
    printf("依次输入相应的数据:");
    for (int i = 1; i < m + 1; i++)
    {
        option = 0;
        scanf("%d", &option);
        ListInsert(L, i, option);
    }
    SelectSort(L);
    printf("排序结果为：");
    for (int i = 1; i <= ListLength(L); i++)
    {
        int e;
        GetList(L, i, e);
        printf("%d ", e);
    }
}

// 冒泡排序
void BubbleSort(SqList &L) {
    int i, j, temp;
    for (i = 0; i < L.length - 1; i++) {
        for (j = 0; j < L.length - 1 - i; j++) {
            if (L.elem[j] > L.elem[j + 1]) {
                // 交换元素
                temp = L.elem[j];
                L.elem[j] = L.elem[j + 1];
                L.elem[j + 1] = temp;
            }
        }
    }
}

void run3()
{
    InitList(L);
    int option, m;
    printf("请输入数组中数据的个数：");
    scanf("%d", &m);
    printf("依次输入相应的数据:");
    for (int i = 1; i < m + 1; i++)
    {
        option = 0;
        scanf("%d", &option);
        ListInsert(L, i, option);
    }
    BubbleSort(L);
    printf("排序结果为：");
    for (int i = 1; i <= ListLength(L); i++)
    {
        int e;
        GetList(L, i, e);
        printf("%d ", e);
    }
}

// 折半降序排序
void BinarySort(SqList &L) {
    int i, j, low, high, mid, key;
    for (i = 1; i < L.length; i++) {
        key = L.elem[i];
        low = 0;
        high = i - 1;

        // 使用二分法找到插入位置
        while (low <= high) {
            mid = (low + high) / 2;
            if (key > L.elem[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // 插入元素到正确的位置
        for (j = i - 1; j >= low; j--) {
            L.elem[j + 1] = L.elem[j];
        }
        L.elem[low] = key;
    }
}

void run4()
{
    InitList(L);
    int option, m;
    printf("请输入数组中数据的个数：");
    scanf("%d", &m);
    printf("依次输入相应的数据");
    for (int i = 1; i < m + 1; i++)
    {
        option = 0;
        scanf("%d", &option);
        ListInsert(L, i, option);
    }
    BinarySort(L);
    printf("排序结果为：");
    for (int i = 1; i <= ListLength(L); i++)
    {
        int e;
        GetList(L, i, e);
        printf("%d ", e);
    }
}

// 顺序查找
int SequentialSearch(SqList L, int target) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == target) {
            return i + 1;  // 返回位置（从1开始）
        }
    }
    return 0;  // 未找到元素
}

// 折半查找
int BinarySearch(SqList L, int target) {
    int low = 0, high = L.length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.elem[mid] == target) {
            return mid + 1;  // 返回位置（从1开始）
        } else if (L.elem[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;  // 未找到元素
}

void run5(SqList &L)
{
    int target;
    printf("请输入要查找的元素：");
    scanf("%d", &target);

    int result = SequentialSearch(L, target);
    if (result != 0) {
        printf("元素 %d 在位置 %d 处。\n", target, result);
    } else {
        printf("未找到元素 %d。\n", target);
    }
}

void run6(SqList &L)
{
    int target;
    printf("请输入要查找的元素：");
    scanf("%d", &target);

    int result = BinarySearch(L, target);
    if (result != 0) {
        printf("元素 %d 在位置 %d 处。\n", target, result);
    } else {
        printf("未找到元素 %d。\n", target);
    }
}

void run5_1()
{
    run5(L);
}

void run6_1()
{
    run6(L);
}

// 比较函数，用于sort函数排序
bool compareBooks(const Book &a, const Book &b) {
    return a.price < b.price;
}

// 输入书籍信息
void inputBooks(Book books[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "请输入第 " << i + 1 << " 本书的名称: ";
        cin.ignore();  // 清空输入缓冲区
        getline(cin, books[i].name);

        cout << "请输入第 " << i + 1 << " 本书的单价: ";
        cin >> books[i].price;
    }
}

// 输出书籍信息
void outputBooks(const Book books[], int n) {
    cout << "排序后的书籍信息：" << endl;
    for (int i = 0; i < n; ++i) {
        cout << books[i].name << " " << fixed << setprecision(1) << books[i].price << endl;
    }
}

// 按单价从小到大排序书籍信息
void sortBooks(Book books[], int n) {
    sort(books, books + n, compareBooks);
}

void run_final() {
    int n;
    cout << "请输入书籍数量 n (n < 10): ";
    cin >> n;

    if (n >= 10 || n <= 0) {
        cout << "输入的数量不符合要求，请重新运行程序并输入符合要求的数量。" << endl;
    }

    // 创建结构数组
    Book books[10];
    // 输入书籍信息
    inputBooks(books, n);
    // 按单价从小到大排序书籍信息
    sortBooks(books, n);
    // 输出排序后的书籍信息
    outputBooks(books, n);
}






