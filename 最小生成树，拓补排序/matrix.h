#include "Set.h"
#define MaxInt 32767
#define MVNum 100

typedef char VerTexType;
typedef int ArcType;

//存储结构
typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum,arcnum;
}AMGraph;
//深度
void matrix_deep();
//广度
void matrix_wide();
//查找对应点的编码
int LocateVex(AMGraph &G, char a);
//创建邻接矩阵
int CreateUDN(AMGraph &G);
//打印输出邻接矩阵
void printf_matrix(AMGraph &G);
//深度优先遍历
void DFS_AM(AMGraph &G,int v);
void DFS_recursive(AMGraph &G, int v, int visited[]);
//广度优先
void BFS(AMGraph &G,int v);
