#include "Set.h"

bool visited2[MVNum];

// 创建有向图的邻接表
int CreateUDG(ALGraph &G) {
    char v1, v2;
    int i, j; // 定义索引变量
    ArcNode* p1; // 定义邻接节点指针

    cout << "请输入顶点数和有向边数，以空格分隔：";
    cin >> G.vexnum >> G.arcnum;

    cout << "依次输入顶点的编号，以空格分隔：";
    for (i = 0; i < G.vexnum; ++i) {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = nullptr;
    }

    cout << "依次输入有向边的起点和终点，以空格分隔：" << endl;
    for (int k = 0; k < G.arcnum; ++k) {
        cin >> v1 >> v2; // 读取有向边的起点和终点
        i = LocateVex2(G, v1);
        j = LocateVex2(G, v2);

        // 创建一个新的邻接节点，并将其指向 j
        p1 = new ArcNode;
        p1->adjvex = j;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
    }

    return OK; // 表示创建成功
}


// 在图中查找顶点的函数
int LocateVex2(ALGraph G, char v) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (G.vertices[i].data == v) {
            return i; // 返回具有匹配数据的顶点的索引
        }
    }
    return -1; // 未找到顶点
}

// 深度优先搜索的函数
void DFS_AL(ALGraph G, int v) {
    cout << v << " ";
    visited2[v] = true;
    ArcNode* p = G.vertices[v].firstarc;
    while (p != nullptr) {
        int w = p->adjvex;
        if (!visited2[w]) {
            DFS_AL(G, w); // 递归访问未访问的邻接顶点
        }
        p = p->nextarc;
    }
}

void BFS_AL(ALGraph G, int v)
{
    cout << "广度优先遍历结果: ";
    queue<int> q;
    cout << v << " ";
    visited2[v] = true;
    q.push(v);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        ArcNode* p = G.vertices[current].firstarc;

        while (p != nullptr) {
            int neighbor = p->adjvex;

            if (!visited2[neighbor]) {
                cout << neighbor << " ";
                visited2[neighbor] = true;
                q.push(neighbor);
            }

            p = p->nextarc;
        }
    }
    cout << endl;
}
//打印输出邻接表
void printf_tables(ALGraph &G)
{
    cout << "邻接表为：" << endl;
    for (int i = 0; i < G.vexnum; i++) {
        cout << i << ":";
        ArcNode* p = G.vertices[i].firstarc;
        while (p != nullptr) {
            cout << " " << p->adjvex;
            p = p->nextarc;
        }
        cout << endl;
    }
}


//创建 深度优先
/*void table_deep()
{
    int v;
    ALGraph G;
    CreateUDG(G);
    printf("创建成功\n");
    printf_tables(G);
    printf("请输入起始节点编号：");
    cin >> v;
    DFS_AL(G,v);
}

void table_wide()
{
    int v;
    ALGraph G;
    CreateUDG(G);
    printf("创建成功\n");
    printf_tables(G);
    printf("请输入起始节点编号：");
    cin >> v;
    BFS_AL(G,v);
}*/
