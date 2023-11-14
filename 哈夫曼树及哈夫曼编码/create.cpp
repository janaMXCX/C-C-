#include "Set.h"


//初始化以及创建树
void CreateHuffmanTree(HuffmanTree &HT, int n) {
    // 初始化
    int m;
    if (n <= 1) return;
    m = 2 * n - 1;
    HT = new HTNode[m + 1];

    for (int i = 1; i <= m; ++i) {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].parent = 0;
    }
    cout << "请输入各个节点的权重（中间用空格间隔）: ";
    for (int i = 1; i <= n; ++i) {
        cin >> HT[i].weight;
    }

    // 创建
    for (int i = n + 1; i <= m; ++i) {
        int s1, s2;
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

void Select(HuffmanTree HT, int n, int &s1, int &s2)
{
    // 找到两个权重最小的节点的下标s1和s2
    int min1, min2;

    // 初始化min1和min2为一个足够大的值
    min1 = min2 = INT_MAX;

    for (int i = 1; i <= n; ++i) {
        if (HT[i].parent == 0) {
            // 如果节点未被合并
            if (HT[i].weight < min1) {
                // 如果权重小于当前的最小权重(min1)，将min1的值赋给min2
                min2 = min1;
                s2 = s1;
                min1 = HT[i].weight;
                s1 = i;
            } else if (HT[i].weight < min2) {
                // 如果权重介于min1和min2之间，更新min2
                min2 = HT[i].weight;
                s2 = i;
            }
        }
    }
}

void PrintHuffmanTreeInfo(const HuffmanTree &HT, int a) {
    for (int i = 1; i <= a; ++i) {
        cout << HT[i].weight << " " << HT[i].parent << " " << HT[i].lchild << " " << HT[i].rchild << endl;
    }
}

void run() {
    int m;
    HuffmanTree HT = nullptr;
    cout << "请输入叶子节点的个数：";
    cin >> m;
    CreateHuffmanTree(HT, m);
    cout << "创建成功！！" << endl;

    // 输出哈夫曼树节点信息
    int a = 2 * m - 1;
    PrintHuffmanTreeInfo(HT, a);

    // 释放内存
    if (HT) {
        delete[] HT;
        HT = nullptr;
    }
}













