#include "Set.h"

typedef struct{
    char sym;
    int weight;
    int parent,lchild,rchild;
}HTNode2,*HuffmanTree2;

//查找权值最小
void Select2(HuffmanTree2 HT, int n, int &s1, int &s2);
//初始化以及创建
void CreateHuffmanTree2(HuffmanTree2 &HT, int n, char characters[], int weights[]);
//哈夫曼编码
void GenerateHuffmanCodes(HuffmanTree2 HT, int n, std::map<char, std::string>& huffmanCodes);
//运行
void run2();
