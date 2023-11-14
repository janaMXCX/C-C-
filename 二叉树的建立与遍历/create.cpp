#include "Set.h"
#include <iostream>
using namespace std;

// 创建二叉树
void CreateBinaryTree(TreeNode*& root) {
    char ch;
    cin >> ch; // 输入节点值，用.表示空结点

    if (ch == '.') {
        root = NULL;
        return;
    }

    root = new TreeNode(ch);
    CreateBinaryTree(root->left); // 递归创建左子树
    CreateBinaryTree(root->right); // 递归创建右子树
}
// 先序遍历函数，用于验证二叉树的创建
void preorderTraversal1(TreeNode* root) {
    if (root) {
        cout << root->data << " "; // 输出当前节点的数据
        preorderTraversal1(root->left); // 递归遍历左子树
        preorderTraversal1(root->right); // 递归遍历右子树
    }
}

int create_run() {
    TreeNode* root = nullptr;
    cout << "请输入字符序列，'.' 表示空节点：" << endl;
    CreateBinaryTree(root); // 调用递归函数创建二叉树

    cout << "创建成功" << endl;
    cout << "中序遍历检查" << endl;
    preorderTraversal1(root);
    cout << endl;
    return 0;
}

