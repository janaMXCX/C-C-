#include "Set.h"
EdgeType closedge[MVNum];

void MiniSpanTree_Prim(AMGraph G, VerTexType u) {
    int k, totalWeight = 0;
    k = LocateVex(G, u);
    for (int j = 0; j < G.vexnum; ++j) {
        if (j != k) {
            closedge[j] = {u, G.arcs[k][j]};
        }
    }
    closedge[k].lowcost = 0;
    for (int i = 1; i < G.vexnum; ++i) {
        char u0, v0;
        k = Min(closedge, G.vexnum);
        u0 = closedge[k].adjvex;
        v0 = G.vexs[k];
        std::cout << "(" << u0 << "," << v0 << ")";
        totalWeight += closedge[k].lowcost;
        closedge[k].lowcost = 0;
        for (int j = 0; j < G.vexnum; ++j) {
            if (G.arcs[k][j] < closedge[j].lowcost) {
                closedge[j] = {G.vexs[k], G.arcs[k][j]};
            }
        }
    }
    std::cout << "��Ȩ��=" << totalWeight << std::endl;
}

int Min(EdgeType closedge[], int n) {
    int minWeight = 100000;
    int minIndex = -1;

    for (int i = 0; i < n; ++i) {
        if (closedge[i].lowcost > 0 && closedge[i].lowcost < minWeight) {
            // ����ߵ�Ȩֵ����0��С�ڵ�ǰ��СȨֵ
            minWeight = closedge[i].lowcost;
            minIndex = i;
        }
    }

    return minIndex;
}
void run1(){
    char v;
    AMGraph G;
    CreateUDN(G);
    printf("�����ɹ�\n");
    cout<< "�����뿪ʼ�Ķ��㣺";
    cin>>v;
    MiniSpanTree_Prim(G,v);

}
