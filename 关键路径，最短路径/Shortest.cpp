#include "Set.h"

int D[MAXSIZE];
int Path[MAXSIZE];

void ShortestPath_DIJ(AMGraph G,int v0)
{
    bool S[MAXSIZE];
    int n=G.vexnum;
    for(int v=0; v<n; ++v)
    {
        S[v]=false;
        D[v]=G.arcs[v0][v];
        if(D[v] < MaxInt)
            Path[v]=v0;
        else Path[v]=-1;
    }
    S[v0]=true;
    D[v0]=0;
    /*--------初始化结束，开始主循环，每次求得v0到某个顶点v的最短路径，将v加到s集---------*/
    for(int i=1; i<n; ++i)
    {
        int v;
        int min = MaxInt;
        for(int w=0; w<n; ++w)
            if(!S[w]&&D[w] < min)
            {
                v=w;
                min=D[w];
            }
        S[v]=true;
        for(int w=0; w<n; ++w)
            if(!S[w]&&(D[v]+G.arcs[v][w]<D[w]))
            {
                D[w]=D[v]+G.arcs[v][w];
                Path[w]=v;
            }
    }
}

void printPath(AMGraph G, int v0)
{
    int b=0;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (i == v0)
        {
            printf("%d->%d:0\n", v0, i);
        }
        else
        {

            // 输出最短路径
            int pathVertex = i;
            int path[MAXSIZE];
            int pathSize = 0;
            while (pathVertex != v0)
            {
                path[pathSize++] = pathVertex;
                pathVertex = Path[pathVertex];
            }
            path[pathSize++] = v0;

            // 逆序输出路径
            for (int j = pathSize - 1; j > 0; --j)
            {
                printf("%d->", path[j]);
            }

            // 输出最短距离
            printf("%d",i);
            printf(":%d\n", D[i]);
        }
    }
}

void run2()
{
    int v;
    AMGraph G;
    CreateUDN(G);
    printf("创建成功\n");
    printf("请输入起始的顶点号：");
    scanf("%d", &v);
    ShortestPath_DIJ(G,v);
    printPath(G, v);
}
