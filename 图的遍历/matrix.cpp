#include "Set.h"


int CreateUDN(AMGraph &G)
{
    cout<< "请输入无向图的顶点数和边数（用空格隔开）:";
    cin>>G.vexnum>>G.arcnum;
    if(G.arcnum<=0||G.arcnum>380||G.vexnum<0||G.vexnum>20)
    {
        return ERROR;
    }
    cout<< "请输入无向图的顶点编号（用空格隔开）:";
    for(int i=0;i<G.vexnum;++i)
    {
        cin>>G.vexs[i];
    }
    //初始化
    for(int i=0;i<G.vexnum;++i)
    {
        for(int j=0;j<G.vexnum;++j)
        {
            G.arcs[i][j]=MaxInt;
        }
    }
    cout<< "请输入每条边两端的编号（用空格隔开，每条边换行输入）:"<< endl;
    for(int k=0;k<G.arcnum;++k)
    {
        char v1,v2;
        int w,i,j;
        cin>>v1>>v2;
        //cin>>v1>>v2>>w;
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        G.arcs[i][j]=1;
        G.arcs[j][i]=G.arcs[i][j];
    }
    return OK;
}
//查找对应下标
int LocateVex(AMGraph &G, char a)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (a == G.vexs[i])
        {
            return i;
        }
    }
    return ERROR; // 如果循环结束都没有找到匹配的元素，返回 ERROR
}
void printf_matrix(AMGraph &G)
{
    printf("**邻接矩阵**\n");
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            if(G.arcs[i][j]==MaxInt){
                printf("0 ");
            }else{
                printf("%d ", G.arcs[i][j]); // 在元素之间添加空格
            }
        }
        printf("\n"); // 在每行末尾添加换行符
    }
}
//深度优先遍历
void DFS_AM(AMGraph &G, int v)
{
    int visited[MVNum] = {0}; // 初始化visited数组，所有元素设置为0
    std::cout << "深度优先遍历结果: ";
    DFS_recursive(G, v, visited);
    std::cout << std::endl;
}

// 递归函数，用于深度优先遍历
void DFS_recursive(AMGraph &G, int v, int visited[])
{
    visited[v] = 1;
    std::cout << G.vexs[v] << " "; // 输出节点v
    for (int w = 0; w < G.vexnum; w++)
    {
        if (G.arcs[v][w] == 1 && visited[w] == 0)
        {
            DFS_recursive(G, w, visited);
        }
    }
}
bool visited[MVNum];
int FirstAdjVex(AMGraph &G, int v)
{
    for (int w = 0; w < G.vexnum; ++w)
    {
        if (G.arcs[v][w] == 1)
        {
            return w;
        }
    }
    return -1; // 如果没有找到邻接顶点，返回-1
}
int NexAdjVex(AMGraph &G, int v, int w)
{
    for (int nextW = w + 1; nextW < G.vexnum; ++nextW)
    {
        if (G.arcs[v][nextW] == 1)
        {
            return nextW;
        }
    }
    return -1; // 如果没有找到下一个邻接顶点，返回-1
}
//连通
void DFS(AMGraph &G,int v)
{
    cout<<v;
    visited[v]=true;
    for(int w=FirstAdjVex(G,v);w>=0;w=NexAdjVex(G,v,w))
    {
        if(!visited[w]) DFS(G,w);
    }
}
//非连通
void DFSTraverse(AMGraph &G)
{
    for(int v=0;v<G.vexnum;++v) visited[v]=false;
    for(int v=0;v<G.vexnum;++v)
        if(!visited[v]) DFS(G,v);
}
//广度
void BFS(AMGraph &G,int v)
{
    SqQueue Q;
    int visited[MVNum] = {0};
    std::cout << G.vexs[v] << " "; // 输出节点v
    visited[v]=1;
    InitQueue(Q);
    EnQueue(Q,v);
    while(!QueueEmpty(Q))
    {
        int u;
        DeQueue(Q,u);
        for(int w=FirstAdjVex(G,u);w>=0;w=NexAdjVex(G,u,w))
        {
            if(visited[w]!=1)
            {
                std::cout << G.vexs[w] << " "; // 输出节点v
                visited[w]=1;
                EnQueue(Q,w);
            }
        }
    }
}


//主创建
void matrix_deep()
{
    int v;
    AMGraph G;
    CreateUDN(G);
    printf("创建成功\n");
    printf_matrix(G);
    printf("请输入起始节点编号：");
    cin >> v;
    v=v-1;
    DFS_AM(G,v);
}

void matrix_wide()
{
    int v;
    AMGraph G;
    CreateUDN(G);
    printf("创建成功\n");
    printf_matrix(G);
    printf("请输入起始节点编号：");
    cin >> v;
    v=v-1;
    BFS(G,v);
}
