#include "Set.h"
#define MaxInt 32767
#define MVNum 100

typedef struct ArcNode {
    int adjvex;
    struct ArcNode* nextarc;
    int info;
} ArcNode;

// 定义 VNode 结构
typedef struct VNode {
    VerTexType data;
    ArcNode* firstarc;
} VNode, AdjList[MVNum];

// 定义 ALGraph 结构
typedef struct ALGraph {
    AdjList vertices;
    int vexnum;
    int arcnum;
} ALGraph;

//深度优先
void DFS_AL(ALGraph G, int v);
//广度优先
void BFS_AL(ALGraph G, int v);
// 在图中查找顶点的函数
int LocateVex2(ALGraph G, char v);
//创建
int CreateUDG(ALGraph &G);
//打印输出邻接表
void printf_tables(ALGraph &G);
//创建 深度优先
void table_deep();
//创建 广度优先
void table_wide();
