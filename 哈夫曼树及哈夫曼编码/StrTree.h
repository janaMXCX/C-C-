#include "Set.h"

typedef struct{
    char sym;
    int weight;
    int parent,lchild,rchild;
}HTNode2,*HuffmanTree2;

//����Ȩֵ��С
void Select2(HuffmanTree2 HT, int n, int &s1, int &s2);
//��ʼ���Լ�����
void CreateHuffmanTree2(HuffmanTree2 &HT, int n, char characters[], int weights[]);
//����������
void GenerateHuffmanCodes(HuffmanTree2 HT, int n, std::map<char, std::string>& huffmanCodes);
//����
void run2();
