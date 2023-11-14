#include "Set.h"
#define MaxInt 32767
#define MVNum 100

typedef struct ArcNode {
    int adjvex;
    struct ArcNode* nextarc;
    int info;
} ArcNode;

// ���� VNode �ṹ
typedef struct VNode {
    VerTexType data;
    ArcNode* firstarc;
} VNode, AdjList[MVNum];

// ���� ALGraph �ṹ
typedef struct ALGraph {
    AdjList vertices;
    int vexnum;
    int arcnum;
} ALGraph;

//�������
void DFS_AL(ALGraph G, int v);
//�������
void BFS_AL(ALGraph G, int v);
// ��ͼ�в��Ҷ���ĺ���
int LocateVex2(ALGraph G, char v);
//����
int CreateUDG(ALGraph &G);
//��ӡ����ڽӱ�
void printf_tables(ALGraph &G);
//���� �������
void table_deep();
//���� �������
void table_wide();
