#include "Set.h"

//���������洢��ʾ
typedef struct{
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;

//����Ȩֵ
void Select(HuffmanTree HT, int n, int &s1, int &s2);
//��ʼ���ʹ���
void CreateHuffmanTree(HuffmanTree &HT, int n);
//����
void run();
void PrintHuffmanTreeInfo(const HuffmanTree &nodeInfo, int totalNodes);
