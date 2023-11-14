#include "Set.h"

// ��ʼ��
int InitStack(Sq_Stack &S)
{
    S.base = new char[MAXSIZE];
    if (!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
    return OK;
}

// ��ջ
int Push(Sq_Stack &S, char e)
{
    if (S.top - S.base == S.stacksize) return ERROR;
    *S.top++ = e;
    return OK;
}

// ��ջ
int Pop(Sq_Stack &S, char &e)
{
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;
}

// ȡջ��Ԫ��
int GetTop(Sq_Stack S, char &e)
{
    if (S.top != S.base)
    {
        e = *(S.top - 1);
        return OK;
    }
    return ERROR;
}

// �ж�ջ��
int StackEmpty(Sq_Stack &S)
{
    if (S.top == S.base)
        return OK;
    else
        return ERROR;
}

// �������
void InOrderTraverse(BiTree T)
{
    BiTree p = T;
    Sq_Stack S;
    InitStack(S);

    while (p || !StackEmpty(S))
    {
        if (p)
        {
            Push(S, p->data);  // �洢�ڵ���ַ�����
            p = p->lchild;
        }
        else
        {
            Pop(S, p->data);  // �����ڵ���ַ�����
            std::cout << p->data;
            p = p->rchild;
        }
    }
}
// ����������
void CreateBinaryTree2(BiTree &root) {
    char cha;
    std::cin >> cha; // ����ڵ�ֵ����.��ʾ�ս��

    if (cha == '.') {
        root = NULL;
        return;
    }

    root = new BiTNode;
    root->data = cha;
    CreateBinaryTree2(root->lchild); // �ݹ鴴��������
    CreateBinaryTree2(root->rchild); // �ݹ鴴��������
}

void preorderTraversal4(BiTNode* root) {
    if (root) {
        cout << root->data << " "; // �����ǰ�ڵ������
        preorderTraversal4(root->lchild); // �ݹ����������
        preorderTraversal4(root->rchild); // �ݹ����������
    }
}

int create_run3() {
    BiTNode* root = nullptr;
    std::cout << "���ǵݹ�����������������ַ����У�'.' ��ʾ�սڵ㣺" << std::endl;
    CreateBinaryTree2(root); // ���õݹ麯������������

    std::cout << "�����ɹ�,�ǵݹ�����������Ϊ��";
    preorderTraversal4(root);
    //InOrderTraverse(root);
    cout << endl;
    return 0;
}
