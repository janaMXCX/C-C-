#include "Set.h"
#include <iostream>
using namespace std;

// ����������
void CreateBinaryTree(TreeNode*& root) {
    char ch;
    cin >> ch; // ����ڵ�ֵ����.��ʾ�ս��

    if (ch == '.') {
        root = NULL;
        return;
    }

    root = new TreeNode(ch);
    CreateBinaryTree(root->left); // �ݹ鴴��������
    CreateBinaryTree(root->right); // �ݹ鴴��������
}
// �������������������֤�������Ĵ���
void preorderTraversal1(TreeNode* root) {
    if (root) {
        cout << root->data << " "; // �����ǰ�ڵ������
        preorderTraversal1(root->left); // �ݹ����������
        preorderTraversal1(root->right); // �ݹ����������
    }
}

int create_run() {
    TreeNode* root = nullptr;
    cout << "�������ַ����У�'.' ��ʾ�սڵ㣺" << endl;
    CreateBinaryTree(root); // ���õݹ麯������������

    cout << "�����ɹ�" << endl;
    cout << "����������" << endl;
    preorderTraversal1(root);
    cout << endl;
    return 0;
}

