#include "Set.h"

// 创建二叉树
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
// 层序遍历
void Strata_orderTraversal(TreeNode2* root) {
    if (root == NULL) {
        return;
    }

    std::queue<TreeNode2*> q;  // 在函数内部声明队列
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
    std::cout << "(层序遍历)请输入二叉树的字符表示（使用'.'表示空节点）：" << std::endl;

    // 创建二叉树
    TreeNode2* root = CreateBinaryTree3();

    // 层序遍历
    std::cout << "层序遍历结果：";
    Strata_orderTraversal(root);
    cout << endl;
}
