#include "Set.h"


int CreateUDN(AMGraph &G)
{
    cout<< "����������ͼ�Ķ������ͱ������ÿո������:";
    cin>>G.vexnum>>G.arcnum;
    if(G.arcnum<=0||G.arcnum>380||G.vexnum<0||G.vexnum>20)
    {
        return ERROR;
    }
    cout<< "����������ͼ�Ķ����ţ��ÿո������:";
    for(int i=0;i<G.vexnum;++i)
    {
        cin>>G.vexs[i];
    }
    //��ʼ��
    for(int i=0;i<G.vexnum;++i)
    {
        for(int j=0;j<G.vexnum;++j)
        {
            G.arcs[i][j]=MaxInt;
        }
    }
    cout<< "������ÿ�������˵ı�ţ��ÿո������ÿ���߻������룩:"<< endl;
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
//���Ҷ�Ӧ�±�
int LocateVex(AMGraph &G, char a)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (a == G.vexs[i])
        {
            return i;
        }
    }
    return ERROR; // ���ѭ��������û���ҵ�ƥ���Ԫ�أ����� ERROR
}
void printf_matrix(AMGraph &G)
{
    printf("**�ڽӾ���**\n");
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            if(G.arcs[i][j]==MaxInt){
                printf("0 ");
            }else{
                printf("%d ", G.arcs[i][j]); // ��Ԫ��֮����ӿո�
            }
        }
        printf("\n"); // ��ÿ��ĩβ��ӻ��з�
    }
}
//������ȱ���
void DFS_AM(AMGraph &G, int v)
{
    int visited[MVNum] = {0}; // ��ʼ��visited���飬����Ԫ������Ϊ0
    std::cout << "������ȱ������: ";
    DFS_recursive(G, v, visited);
    std::cout << std::endl;
}

// �ݹ麯��������������ȱ���
void DFS_recursive(AMGraph &G, int v, int visited[])
{
    visited[v] = 1;
    std::cout << G.vexs[v] << " "; // ����ڵ�v
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
    return -1; // ���û���ҵ��ڽӶ��㣬����-1
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
    return -1; // ���û���ҵ���һ���ڽӶ��㣬����-1
}
//��ͨ
void DFS(AMGraph &G,int v)
{
    cout<<v;
    visited[v]=true;
    for(int w=FirstAdjVex(G,v);w>=0;w=NexAdjVex(G,v,w))
    {
        if(!visited[w]) DFS(G,w);
    }
}
//����ͨ
void DFSTraverse(AMGraph &G)
{
    for(int v=0;v<G.vexnum;++v) visited[v]=false;
    for(int v=0;v<G.vexnum;++v)
        if(!visited[v]) DFS(G,v);
}
//���
void BFS(AMGraph &G,int v)
{
    SqQueue Q;
    int visited[MVNum] = {0};
    std::cout << G.vexs[v] << " "; // ����ڵ�v
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
                std::cout << G.vexs[w] << " "; // ����ڵ�v
                visited[w]=1;
                EnQueue(Q,w);
            }
        }
    }
}


//������
void matrix_deep()
{
    int v;
    AMGraph G;
    CreateUDN(G);
    printf("�����ɹ�\n");
    printf_matrix(G);
    printf("��������ʼ�ڵ��ţ�");
    cin >> v;
    v=v-1;
    DFS_AM(G,v);
}

void matrix_wide()
{
    int v;
    AMGraph G;
    CreateUDN(G);
    printf("�����ɹ�\n");
    printf_matrix(G);
    printf("��������ʼ�ڵ��ţ�");
    cin >> v;
    v=v-1;
    BFS(G,v);
}
