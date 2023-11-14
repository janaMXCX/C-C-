#include "Set.h"
#include <iostream>
using namespace std;

void Traversal(){
    menu2();
    select_menu2();
}

// 先序
void preorderTraversal2(TreeNode* root) {
    if (root) {
        cout << root->data << " "; // 输出当前节点的数据
        preorderTraversal2(root->left); // 递归遍历左子树
        preorderTraversal2(root->right); // 递归遍历右子树
    }
}
//中
void MiddleTraversal(TreeNode* root) {
    if (root) {
        MiddleTraversal(root->left); // 递归遍历左子树
        cout << root->data << " "; // 输出当前节点的数据
        MiddleTraversal(root->right); // 递归遍历右子树
    }
}
//后
void PostorderTraversal(TreeNode* root) {
    if (root) {
        PostorderTraversal(root->left); // 递归遍历左子树
        PostorderTraversal(root->right); // 递归遍历右子树
        cout << root->data << " "; // 输出当前节点的数据
    }
}



//创建
int create_run2(){
    TreeNode* root2 = nullptr;
    cout << "请输入字符序列，'.' 表示空节点：" << endl;
    CreateBinaryTree(root2); // 调用递归函数创建二叉树

    cout << "创建成功" << endl;
    //先序
    cout << "先序遍历结果：";
    preorderTraversal2(root2);
    cout << endl;
    //中序
    cout << "中序遍历结果：";
    MiddleTraversal(root2);
    cout << endl;
    //后序
    cout << "后序遍历结果：";
    PostorderTraversal(root2);
    cout << endl;

    return 0;
}




