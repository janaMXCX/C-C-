#include "Set.h"

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : data(val), left(NULL), right(NULL) {}
};
//��Ҫ�����к���
int create_run();
// ����
void preorderTraversal1(TreeNode* root);
// ����������
void CreateBinaryTree(TreeNode*& root);








