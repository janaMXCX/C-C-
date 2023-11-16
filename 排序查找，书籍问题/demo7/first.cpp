#include "Set.h"

SqList L;

// ��ʼ�����Ա�
int InitList(SqList &L) {
    L.elem = (int *)malloc(MAXSIZE * sizeof(int));
    if (!L.elem) {
        return -1;  // �ڴ����ʧ��
    }
    L.length = 0;
    return 0;  // ��ʼ���ɹ�
}

// ��ȡ��i��Ԫ�ص�ֵ
int GetList(SqList L, int i, int &e) {
    e = L.elem[i - 1];
    return 0;  // ��ȡ�ɹ�
}

// ����Ԫ��e�ڱ��е�λ��
int LocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            return i + 1;  // ����λ�ã���1��ʼ��
        }
    }
    return 0;  // δ�ҵ�Ԫ��
}

// �ڵ�i��λ�ò���Ԫ��e
int ListInsert(SqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1 || L.length == MAXSIZE) {
        return -1;  // ����λ�ò��Ϸ������
    }

    for (int j = L.length; j >= i; j--) {
        L.elem[j] = L.elem[j - 1];
    }
    L.elem[i - 1] = e;
    L.length++;
    return 0;  // ����ɹ�
}

// ɾ����i��λ�õ�Ԫ��
int ListDelete(SqList &L, int i) {
    if (i < 1 || i > L.length) {
        return -1;  // ɾ��λ�ò��Ϸ�
    }

    for (int j = i; j < L.length; j++) {
        L.elem[j - 1] = L.elem[j];
    }
    L.length--;
    return 0;  // ɾ���ɹ�
}

// ��ȡ���Ա�ĳ���
int ListLength(SqList &L) {
    return L.length;
}
// ֱ�Ӳ�������
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
    printf("���������������ݵĸ�����");
    scanf("%d", &m);
    printf("����������Ӧ������:");
    L.length++;
    ListInsert(L,0,0);
    for (int i = 1; i < m+1; i++)
    {
        option = 0;
        scanf("%d", &option);
        ListInsert(L, i + 1, option);
    }
    InsertSort(L);
    printf("������Ϊ��");
    for (int i = 1; i < ListLength(L); i++)
    {
        int e;
        GetList(L, i+1, e);
        printf("%d ", e);
    }
}

// ѡ������
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
    printf("���������������ݵĸ�����");
    scanf("%d", &m);
    printf("����������Ӧ������:");
    for (int i = 1; i < m + 1; i++)
    {
        option = 0;
        scanf("%d", &option);
        ListInsert(L, i, option);
    }
    SelectSort(L);
    printf("������Ϊ��");
    for (int i = 1; i <= ListLength(L); i++)
    {
        int e;
        GetList(L, i, e);
        printf("%d ", e);
    }
}

// ð������
void BubbleSort(SqList &L) {
    int i, j, temp;
    for (i = 0; i < L.length - 1; i++) {
        for (j = 0; j < L.length - 1 - i; j++) {
            if (L.elem[j] > L.elem[j + 1]) {
                // ����Ԫ��
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
    printf("���������������ݵĸ�����");
    scanf("%d", &m);
    printf("����������Ӧ������:");
    for (int i = 1; i < m + 1; i++)
    {
        option = 0;
        scanf("%d", &option);
        ListInsert(L, i, option);
    }
    BubbleSort(L);
    printf("������Ϊ��");
    for (int i = 1; i <= ListLength(L); i++)
    {
        int e;
        GetList(L, i, e);
        printf("%d ", e);
    }
}

// �۰뽵������
void BinarySort(SqList &L) {
    int i, j, low, high, mid, key;
    for (i = 1; i < L.length; i++) {
        key = L.elem[i];
        low = 0;
        high = i - 1;

        // ʹ�ö��ַ��ҵ�����λ��
        while (low <= high) {
            mid = (low + high) / 2;
            if (key > L.elem[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // ����Ԫ�ص���ȷ��λ��
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
    printf("���������������ݵĸ�����");
    scanf("%d", &m);
    printf("����������Ӧ������");
    for (int i = 1; i < m + 1; i++)
    {
        option = 0;
        scanf("%d", &option);
        ListInsert(L, i, option);
    }
    BinarySort(L);
    printf("������Ϊ��");
    for (int i = 1; i <= ListLength(L); i++)
    {
        int e;
        GetList(L, i, e);
        printf("%d ", e);
    }
}

// ˳�����
int SequentialSearch(SqList L, int target) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == target) {
            return i + 1;  // ����λ�ã���1��ʼ��
        }
    }
    return 0;  // δ�ҵ�Ԫ��
}

// �۰����
int BinarySearch(SqList L, int target) {
    int low = 0, high = L.length - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.elem[mid] == target) {
            return mid + 1;  // ����λ�ã���1��ʼ��
        } else if (L.elem[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;  // δ�ҵ�Ԫ��
}

void run5(SqList &L)
{
    int target;
    printf("������Ҫ���ҵ�Ԫ�أ�");
    scanf("%d", &target);

    int result = SequentialSearch(L, target);
    if (result != 0) {
        printf("Ԫ�� %d ��λ�� %d ����\n", target, result);
    } else {
        printf("δ�ҵ�Ԫ�� %d��\n", target);
    }
}

void run6(SqList &L)
{
    int target;
    printf("������Ҫ���ҵ�Ԫ�أ�");
    scanf("%d", &target);

    int result = BinarySearch(L, target);
    if (result != 0) {
        printf("Ԫ�� %d ��λ�� %d ����\n", target, result);
    } else {
        printf("δ�ҵ�Ԫ�� %d��\n", target);
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

// �ȽϺ���������sort��������
bool compareBooks(const Book &a, const Book &b) {
    return a.price < b.price;
}

// �����鼮��Ϣ
void inputBooks(Book books[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "������� " << i + 1 << " ���������: ";
        cin.ignore();  // ������뻺����
        getline(cin, books[i].name);

        cout << "������� " << i + 1 << " ����ĵ���: ";
        cin >> books[i].price;
    }
}

// ����鼮��Ϣ
void outputBooks(const Book books[], int n) {
    cout << "�������鼮��Ϣ��" << endl;
    for (int i = 0; i < n; ++i) {
        cout << books[i].name << " " << fixed << setprecision(1) << books[i].price << endl;
    }
}

// �����۴�С���������鼮��Ϣ
void sortBooks(Book books[], int n) {
    sort(books, books + n, compareBooks);
}

void run_final() {
    int n;
    cout << "�������鼮���� n (n < 10): ";
    cin >> n;

    if (n >= 10 || n <= 0) {
        cout << "���������������Ҫ�����������г����������Ҫ���������" << endl;
    }

    // �����ṹ����
    Book books[10];
    // �����鼮��Ϣ
    inputBooks(books, n);
    // �����۴�С���������鼮��Ϣ
    sortBooks(books, n);
    // ����������鼮��Ϣ
    outputBooks(books, n);
}






