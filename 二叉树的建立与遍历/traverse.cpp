#include "Set.h"
#include <iostream>
using namespace std;

void Traversal(){
    menu2();
    select_menu2();
}

// ����
void preorderTraversal2(TreeNode* root) {
    if (root) {
        cout << root->data << " "; // �����ǰ�ڵ������
        preorderTraversal2(root->left); // �ݹ����������
        preorderTraversal2(root->right); // �ݹ����������
    }
}
//��
void MiddleTraversal(TreeNode* root) {
    if (root) {
        MiddleTraversal(root->left); // �ݹ����������
        cout << root->data << " "; // �����ǰ�ڵ������
        MiddleTraversal(root->right); // �ݹ����������
    }
}
//��
void PostorderTraversal(TreeNode* root) {
    if (root) {
        PostorderTraversal(root->left); // �ݹ����������
        PostorderTraversal(root->right); // �ݹ����������
        cout << root->data << " "; // �����ǰ�ڵ������
    }
}



//����
int create_run2(){
    TreeNode* root2 = nullptr;
    cout << "�������ַ����У�'.' ��ʾ�սڵ㣺" << endl;
    CreateBinaryTree(root2); // ���õݹ麯������������

    cout << "�����ɹ�" << endl;
    //����
    cout << "������������";
    preorderTraversal2(root2);
    cout << endl;
    //����
    cout << "������������";
    MiddleTraversal(root2);
    cout << endl;
    //����
    cout << "������������";
    PostorderTraversal(root2);
    cout << endl;

    return 0;
}




