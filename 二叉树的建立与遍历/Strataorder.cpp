#include "Set.h"

// ����������
TreeNode2* CreateBinaryTree3() {
    char cha;
    std::cin >> cha;

    if (cha == '.') {
        return NULL;
    }

    TreeNode2* root = new TreeNode2;
    root->data = cha;
    root->lchild = CreateBinaryTree3();
    root->rchild = CreateBinaryTree3();

    return root;
}
// �������
void Strata_orderTraversal(TreeNode2* root) {
    if (root == NULL) {
        return;
    }

    std::queue<TreeNode2*> q;  // �ں����ڲ���������
    q.push(root);

    while (!q.empty()) {
        TreeNode2* curr = q.front();
        q.pop();

        std::cout << curr->data << " ";

        if (curr->lchild != NULL) {
            q.push(curr->lchild);
        }

        if (curr->rchild != NULL) {
            q.push(curr->rchild);
        }
    }
}


void Strata_order_run()
{
    std::cout << "(�������)��������������ַ���ʾ��ʹ��'.'��ʾ�սڵ㣩��" << std::endl;

    // ����������
    TreeNode2* root = CreateBinaryTree3();

    // �������
    std::cout << "������������";
    Strata_orderTraversal(root);
    cout << endl;
}
