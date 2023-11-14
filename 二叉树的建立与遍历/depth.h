#include "Set.h"

typedef struct BiTNode2 {
    char data;
    struct BiTNode2* lchild;
    struct BiTNode2* rchild;
} BiTNode2;

typedef BiTNode2* BiTree2;

void CreateBinaryTree4(BiTree2 &root2);

int Depth(BiTree2 T);
int Depth_run();

int NodeCount(BiTree2 T);
int Leaf_run();

