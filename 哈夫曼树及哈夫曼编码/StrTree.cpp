#include "Set.h"

void Select2(HuffmanTree2 HT, int n, int &s1, int &s2)
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

void CreateHuffmanTree2(HuffmanTree2 &HT, int n, char characters[], int weights[])
 {
    // ��ʼ��
    int m = 2 * n - 1;
    HT = new HTNode2[m + 1];
    for (int i = 1; i <= m; ++i) {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].sym = ' ';
    }
    for (int i = 1; i <= n; ++i) {
        HT[i].weight = weights[i - 1];
        HT[i].sym = characters[i - 1];
    }

    // ����
    for (int i = n + 1; i <= m; ++i) {
        int s1, s2;
        Select2(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

void GenerateHuffmanCodes(HuffmanTree2 HT, int n, std::map<char, std::string>& huffmanCodes)
{
    for (int i = 1; i <= n; ++i) {
        // ��ʼ�������������ַ���
        std::string code = "";
        int current = i;
        int parent = HT[i].parent;

        // ��Ҷ�ӽڵ���ݵ����ڵ㣬��������������
        while (parent != 0) {
            if (HT[parent].lchild == current) {
                code = "0" + code; // ���������Ϊ0
            } else {
                code = "1" + code; // ���������Ϊ1
            }
            current = parent;
            parent = HT[current].parent;
        }

        huffmanCodes[HT[i].sym] = code;
    }
}

void run2()
{
    int n;
    HuffmanTree2 HT = nullptr;
    std::cout << "������Ҷ�ӽڵ�ĸ�����";
    std::cin >> n;

    // �����ַ������Ȩ������
    char* characters = new char[n];
    int* weights = new int[n];

    std::cout << "���������ַ����޿ո�: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> characters[i];
    }

    std::cout << "����Ȩ�أ��ո�ָ���: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }

    // ������������
    CreateHuffmanTree2(HT, n, characters, weights);

    // �����ַ��Ĺ���������
    std::map<char, std::string> huffmanCodes;
    GenerateHuffmanCodes(HT, n, huffmanCodes);

    // ����ַ������Ӧ�Ĺ���������
    std::cout << "���������룺" << std::endl;
    for (const auto& entry : huffmanCodes) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    // �ͷ��ڴ�
    if (HT) {
        delete[] HT;
        HT = nullptr;
    }

    delete[] characters;
    delete[] weights;
}
