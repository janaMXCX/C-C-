#include "Set.h"


void CreateBinaryTree4(BiTree2 &root2) {
    char cha;
    std::cin >> cha; // 输入节点值，用.表示空结点

    if (cha == '.') {
        root2 = NULL;
        return;
    }

    root2 = new BiTNode2;
    root2->data = cha;
    CreateBinaryTree4(root2->lchild); // 递归创建左子树
    CreateBinaryTree4(root2->rchild); // 递归创建右子树
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
        return 0; // 如果节点为空，返回0
    }
    if (T->lchild == NULL && T->rchild == NULL) {
        return 1; // 如果节点是叶子节点，返回1
    }
    return NodeCount(T->lchild) + NodeCount(T->rchild); // 递归计算左子树和右子树的叶子节点个数
}



int Leaf_run() {
    int a = 0;
    BiTNode2* root2 = nullptr;
    std::cout << "(叶子节点个数)请输入字符序列，'.' 表示空节点：" << std::endl;
    CreateBinaryTree4(root2); // 调用递归函数创建二叉树
    std::cout << "创建成功,叶子节点个数为：";
    a = NodeCount(root2); // 计算叶子节点的个数
    std::cout << a;
    cout << endl;
    return 0;
}



int Depth_run() {
    int a=0;
    BiTNode2* root2 = nullptr;
    std::cout << "(深度)请输入字符序列，'.' 表示空节点：" << std::endl;
    CreateBinaryTree4(root2); // 调用递归函数创建二叉树
    std::cout << "创建成功,深度为：";
    a = Depth(root2);
    std::cout << a; // 使用 std::cout 输出 a 的值
    cout << endl;
    return 0;
}
