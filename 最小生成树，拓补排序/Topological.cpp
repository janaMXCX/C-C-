#include "Set.h"
#define MAXSIZE 100
//求各顶点的入度
void FindInDegree(ALGraph G, int indegree[MAXSIZE]) {
    // 初始化入度数组
    for (int i = 0; i < G.vexnum; ++i) {
        indegree[i] = 0;
    }

    // 遍历每个顶点的邻接边
    for (int i = 0; i < G.vexnum; ++i) {
        ArcNode* p = G.vertices[i].firstarc;
        while (p != nullptr) {
            int k = p->adjvex;
            indegree[k]++; // 增加顶点 k 的入度
            p = p->nextarc;
        }
    }
    // 打印各个顶点的入度
    for (int i = 0; i < G.vexnum; ++i) {
        printf("顶点 %d 的入度为 %d\n", i, indegree[i]);
    }
}
//打印输出拓补序列
void PrintTopoOrder(int topo[], int n) {
    printf("拓扑排序结果为: ");
    for (int i = 0; i < n; ++i) {
        printf("%d", topo[i] + 1);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("\n");
}

//拓补排序
int TopologicalSort(ALGraph G, int topo[]) {
    int indegree[MAXSIZE];
    FindInDegree(G, indegree);

    // 初始化栈
    Sq_Stack S;
    InitStack(S);

    for (int i = 0; i < G.vexnum; ++i) {
        if (!indegree[i]) {
            Push(S, i);
        }
    }

    int m = 0;
    while (!StackEmpty(S)) {
        int i;
        Pop(S, i);
        topo[m] = i;
        ++m;

        ArcNode* p = G.vertices[i].firstarc;
        while (p != nullptr) {
            int k = p->adjvex;
            --indegree[k];
            if (indegree[k] == 0) {
                Push(S, k);
            }
            p = p->nextarc;
        }
    }

    if (m < G.vexnum) {
        return ERROR; // 图中存在环路，拓扑排序失败
    } else {
        return OK; // 拓扑排序成功
    }
}

void run2()
{
    int topo[MAXSIZE];
    ALGraph G;
    CreateUDG(G);

    TopologicalSort(G, topo);
    PrintTopoOrder(topo, G.vexnum);
}
