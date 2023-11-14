#include "Set.h"

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : data(val), left(NULL), right(NULL) {}
};
//主要的运行函数
int create_run();
// 先序
void preorderTraversal1(TreeNode* root);
// 创建二叉树
void CreateBinaryTree(TreeNode*& root);








