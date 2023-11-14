#include "Set.h"


//��ʼ���Լ�������
void CreateHuffmanTree(HuffmanTree &HT, int n) {
    // ��ʼ��
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
    cout << "����������ڵ��Ȩ�أ��м��ÿո�����: ";
    for (int i = 1; i <= n; ++i) {
        cin >> HT[i].weight;
    }

    // ����
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
    // �ҵ�����Ȩ����С�Ľڵ���±�s1��s2
    int min1, min2;

    // ��ʼ��min1��min2Ϊһ���㹻���ֵ
    min1 = min2 = INT_MAX;

    for (int i = 1; i <= n; ++i) {
        if (HT[i].parent == 0) {
            // ����ڵ�δ���ϲ�
            if (HT[i].weight < min1) {
                // ���Ȩ��С�ڵ�ǰ����СȨ��(min1)����min1��ֵ����min2
                min2 = min1;
                s2 = s1;
                min1 = HT[i].weight;
                s1 = i;
            } else if (HT[i].weight < min2) {
                // ���Ȩ�ؽ���min1��min2֮�䣬����min2
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
    cout << "������Ҷ�ӽڵ�ĸ�����";
    cin >> m;
    CreateHuffmanTree(HT, m);
    cout << "�����ɹ�����" << endl;

    // ������������ڵ���Ϣ
    int a = 2 * m - 1;
    PrintHuffmanTreeInfo(HT, a);

    // �ͷ��ڴ�
    if (HT) {
        delete[] HT;
        HT = nullptr;
    }
}













