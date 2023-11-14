#include "Set.h"
//求各顶点的入度
void FindInDegree(ALGraph G, int indegree[MAXSIZE]);
//拓补排序
int TopologicalSort(ALGraph G, int topo[]);
//打印输出拓补序列
void PrintTopoOrder(int topo[], int n);

//void run2();
