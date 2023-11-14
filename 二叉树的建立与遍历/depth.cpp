#include "Set.h"


void CreateBinaryTree4(BiTree2 &root2) {
    char cha;
    std::cin >> cha; // ����ڵ�ֵ����.��ʾ�ս��

    if (cha == '.') {
        root2 = NULL;
        return;
    }

    root2 = new BiTNode2;
    root2->data = cha;
    CreateBinaryTree4(root2->lchild); // �ݹ鴴��������
    CreateBinaryTree4(root2->rchild); // �ݹ鴴��������
}

int Depth(BiTree2 T)
{
    int m=0,n=0;
    if(T==NULL) return 0;
    else{
        m = Depth(T->lchild);
        n = Depth(T->rchild);
        if(m>n) return(m+1);
        else return(n+1);
    }
}

int NodeCount(BiTree2 T) {
    if (T == NULL) {
        return 0; // ����ڵ�Ϊ�գ�����0
    }
    if (T->lchild == NULL && T->rchild == NULL) {
        return 1; // ����ڵ���Ҷ�ӽڵ㣬����1
    }
    return NodeCount(T->lchild) + NodeCount(T->rchild); // �ݹ��������������������Ҷ�ӽڵ����
}



int Leaf_run() {
    int a = 0;
    BiTNode2* root2 = nullptr;
    std::cout << "(Ҷ�ӽڵ����)�������ַ����У�'.' ��ʾ�սڵ㣺" << std::endl;
    CreateBinaryTree4(root2); // ���õݹ麯������������
    std::cout << "�����ɹ�,Ҷ�ӽڵ����Ϊ��";
    a = NodeCount(root2); // ����Ҷ�ӽڵ�ĸ���
    std::cout << a;
    cout << endl;
    return 0;
}



int Depth_run() {
    int a=0;
    BiTNode2* root2 = nullptr;
    std::cout << "(���)�������ַ����У�'.' ��ʾ�սڵ㣺" << std::endl;
    CreateBinaryTree4(root2); // ���õݹ麯������������
    std::cout << "�����ɹ�,���Ϊ��";
    a = Depth(root2);
    std::cout << a; // ʹ�� std::cout ��� a ��ֵ
    cout << endl;
    return 0;
}
