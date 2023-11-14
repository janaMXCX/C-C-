#include "Set.h"
#define MAXSIZE 100
//�����������
void FindInDegree(ALGraph G, int indegree[MAXSIZE]) {
    // ��ʼ���������
    for (int i = 0; i < G.vexnum; ++i) {
        indegree[i] = 0;
    }

    // ����ÿ��������ڽӱ�
    for (int i = 0; i < G.vexnum; ++i) {
        ArcNode* p = G.vertices[i].firstarc;
        while (p != nullptr) {
            int k = p->adjvex;
            indegree[k]++; // ���Ӷ��� k �����
            p = p->nextarc;
        }
    }
    // ��ӡ������������
    for (int i = 0; i < G.vexnum; ++i) {
        printf("���� %d �����Ϊ %d\n", i, indegree[i]);
    }
}
//��ӡ����ز�����
void PrintTopoOrder(int topo[], int n) {
    printf("����������Ϊ: ");
    for (int i = 0; i < n; ++i) {
        printf("%d", topo[i] + 1);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("\n");
}

//�ز�����
int TopologicalSort(ALGraph G, int topo[]) {
    int indegree[MAXSIZE];
    FindInDegree(G, indegree);

    // ��ʼ��ջ
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
        return ERROR; // ͼ�д��ڻ�·����������ʧ��
    } else {
        return OK; // ��������ɹ�
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
