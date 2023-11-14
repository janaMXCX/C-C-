#include "Set.h"

// 初始化
int InitStack(Sq_Stack &S)
{
    S.base = new char[MAXSIZE];
    if (!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

// 入栈
int Push(Sq_Stack &S, char e)
{
    if (S.top - S.base == S.stacksize) return ERROR;
    *S.top++ = e;
    return OK;
}

// 出栈
int Pop(Sq_Stack &S, char &e)
{
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}

// 取栈顶元素
int GetTop(Sq_Stack S, char &e)
{
    if (S.top != S.base)
    {
        e = *(S.top - 1);
        return OK;
    }
    return ERROR;
}

// 判断栈空
int StackEmpty(Sq_Stack &S)
{
    if (S.top == S.base)
        return OK;
    else
        return ERROR;
}

// 中序遍历
void InOrderTraverse(BiTree T)
{
    BiTree p = T;
    Sq_Stack S;
    InitStack(S);

    while (p || !StackEmpty(S))
    {
        if (p)
        {
            Push(S, p->data);  // 存储节点的字符数据
            p = p->lchild;
        }
        else
        {
            Pop(S, p->data);  // 弹出节点的字符数据
            std::cout << p->data;
            p = p->rchild;
        }
    }
}
// 创建二叉树
void CreateBinaryTree2(BiTree &root) {
    char cha;
    std::cin >> cha; // 输入节点值，用.表示空结点

    if (cha == '.') {
        root = NULL;
        return;
    }

    root = new BiTNode;
    root->data = cha;
    CreateBinaryTree2(root->lchild); // 递归创建左子树
    CreateBinaryTree2(root->rchild); // 递归创建右子树
}

void preorderTraversal4(BiTNode* root) {
    if (root) {
        cout << root->data << " "; // 输出当前节点的数据
        preorderTraversal4(root->lchild); // 递归遍历左子树
        preorderTraversal4(root->rchild); // 递归遍历右子树
    }
}

int create_run3() {
    BiTNode* root = nullptr;
    std::cout << "（非递归中序遍历）请输入字符序列，'.' 表示空节点：" << std::endl;
    CreateBinaryTree2(root); // 调用递归函数创建二叉树

    std::cout << "创建成功,非递归中序遍历结果为：";
    preorderTraversal4(root);
    //InOrderTraverse(root);
    cout << endl;
    return 0;
}
