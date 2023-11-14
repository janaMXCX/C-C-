#include "Set.h"

//哈夫曼树存储表示
typedef struct{
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;

//查找权值
void Select(HuffmanTree HT, int n, int &s1, int &s2);
//初始化和创建
void CreateHuffmanTree(HuffmanTree &HT, int n);
//运行
void run();
void PrintHuffmanTreeInfo(const HuffmanTree &nodeInfo, int totalNodes);
