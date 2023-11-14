#include "Set.h"

bool visited2[MVNum];

// ��������ͼ���ڽӱ�
int CreateUDG(ALGraph &G) {
    char v1, v2;
    int i, j; // ������������
    ArcNode* p1; // �����ڽӽڵ�ָ��

    cout << "�����붥����������������Կո�ָ���";
    cin >> G.vexnum >> G.arcnum;

    cout << "�������붥��ı�ţ��Կո�ָ���";
    for (i = 0; i < G.vexnum; ++i) {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = nullptr;
    }

    cout << "������������ߵ������յ㣬�Կո�ָ���" << endl;
    for (int k = 0; k < G.arcnum; ++k) {
        cin >> v1 >> v2; // ��ȡ����ߵ������յ�
        i = LocateVex2(G, v1);
        j = LocateVex2(G, v2);

        // ����һ���µ��ڽӽڵ㣬������ָ�� j
        p1 = new ArcNode;
        p1->adjvex = j;
        p1->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc = p1;
    }

    return OK; // ��ʾ�����ɹ�
}


// ��ͼ�в��Ҷ���ĺ���
int LocateVex2(ALGraph G, char v) {
    for (int i = 0; i < G.vexnum; ++i) {
        if (G.vertices[i].data == v) {
            return i; // ���ؾ���ƥ�����ݵĶ��������
        }
    }
    return -1; // δ�ҵ�����
}

// ������������ĺ���
void DFS_AL(ALGraph G, int v) {
    cout << v << " ";
    visited2[v] = true;
    ArcNode* p = G.vertices[v].firstarc;
    while (p != nullptr) {
        int w = p->adjvex;
        if (!visited2[w]) {
            DFS_AL(G, w); // �ݹ����δ���ʵ��ڽӶ���
        }
        p = p->nextarc;
    }
}

void BFS_AL(ALGraph G, int v)
{
    cout << "������ȱ������: ";
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
//��ӡ����ڽӱ�
void printf_tables(ALGraph &G)
{
    cout << "�ڽӱ�Ϊ��" << endl;
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


//���� �������
/*void table_deep()
{
    int v;
    ALGraph G;
    CreateUDG(G);
    printf("�����ɹ�\n");
    printf_tables(G);
    printf("��������ʼ�ڵ��ţ�");
    cin >> v;
    DFS_AL(G,v);
}

void table_wide()
{
    int v;
    ALGraph G;
    CreateUDG(G);
    printf("�����ɹ�\n");
    printf_tables(G);
    printf("��������ʼ�ڵ��ţ�");
    cin >> v;
    BFS_AL(G,v);
}*/
