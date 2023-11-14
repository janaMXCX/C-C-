#include "Set.h"

void Select2(HuffmanTree2 HT, int n, int &s1, int &s2)
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

void CreateHuffmanTree2(HuffmanTree2 &HT, int n, char characters[], int weights[])
 {
    // 初始化
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

    // 创建
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
        // 初始化哈夫曼编码字符串
        std::string code = "";
        int current = i;
        int parent = HT[i].parent;

        // 从叶子节点回溯到根节点，构建哈夫曼编码
        while (parent != 0) {
            if (HT[parent].lchild == current) {
                code = "0" + code; // 左子树标记为0
            } else {
                code = "1" + code; // 右子树标记为1
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
    std::cout << "请输入叶子节点的个数：";
    std::cin >> n;

    // 创建字符数组和权重数组
    char* characters = new char[n];
    int* weights = new int[n];

    std::cout << "连续输入字符（无空格）: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> characters[i];
    }

    std::cout << "输入权重（空格分隔）: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }

    // 创建哈夫曼树
    CreateHuffmanTree2(HT, n, characters, weights);

    // 生成字符的哈夫曼编码
    std::map<char, std::string> huffmanCodes;
    GenerateHuffmanCodes(HT, n, huffmanCodes);

    // 输出字符及其对应的哈夫曼编码
    std::cout << "哈夫曼编码：" << std::endl;
    for (const auto& entry : huffmanCodes) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    // 释放内存
    if (HT) {
        delete[] HT;
        HT = nullptr;
    }

    delete[] characters;
    delete[] weights;
}
