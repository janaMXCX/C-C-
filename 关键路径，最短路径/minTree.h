#include "Set.h"

typedef struct
{
    VerTexType adjvex;
    ArcType lowcost;
}EdgeType;

int Min(EdgeType closedge[], int n);
void MiniSpanTree_Prim(AMGraph G,VerTexType u);
//void run1();
