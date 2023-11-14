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
    /*--------��ʼ����������ʼ��ѭ����ÿ�����v0��ĳ������v�����·������v�ӵ�s��---------*/
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

            // ������·��
            int pathVertex = i;
            int path[MAXSIZE];
            int pathSize = 0;
            while (pathVertex != v0)
            {
                path[pathSize++] = pathVertex;
                pathVertex = Path[pathVertex];
            }
            path[pathSize++] = v0;

            // �������·��
            for (int j = pathSize - 1; j > 0; --j)
            {
                printf("%d->", path[j]);
            }

            // �����̾���
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
    printf("�����ɹ�\n");
    printf("��������ʼ�Ķ���ţ�");
    scanf("%d", &v);
    ShortestPath_DIJ(G,v);
    printPath(G, v);
}
