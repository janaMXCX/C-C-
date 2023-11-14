#include "Set.h"
int CriticalPath(ALGraph G)
{
    int topo[MAXSIZE];
    if (!TopologicalSort(G, topo)) {
        cout << "��������ʧ�ܣ�ͼ�д��ڻ�·��" << endl;
    }
    int n=G.vexnum;
    int ve[MAXSIZE],vl[MAXSIZE];
    for(int i=0;i<n;i++)
    {
        ve[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int k;
        k=topo[i];
        ArcNode* p=G.vertices[k].firstarc;
        while(p!=NULL)
        {
            int j=0;
            j=p->adjvex;
            if(ve[j]<ve[k]+p->weight)
               ve[j]=ve[k]+p->weight;
            p=p->nextarc;
        }
    }
    for(int i=0;i<n;i++)
        vl[i]=ve[n-1];

    for(int i=n-1;i>=0;i--)
    {
        int k;
        k=topo[i];
        ArcNode* p=G.vertices[k].firstarc;
        while(p!=NULL)
        {

            int j;
            j=p->adjvex;
            if(vl[k]>vl[j]-p->weight)
                vl[k]=vl[j]-p->weight;
            p=p->nextarc;
        }
    }
    cout<<"�ؼ��"<<endl;
    for(int i=0;i<n;i++)
    {

        ArcNode* p=G.vertices[i].firstarc;
        while(p!=nullptr)
        {
            int j,e,l;
            j=p->adjvex;

            e=ve[i];
            l=vl[j]-p->weight;
            if(e == l)
                cout<<G.vertices[i].data<<"->"<<G.vertices[j].data <<endl;
            p=p->nextarc;
        }
    }
    int max_time = 0;
    for (int i = 0; i < n; i++) {
        if (ve[i] > max_time) {
            max_time = ve[i];
        }
    }
    cout << "����������Ŀ��Ҫ��ʱ�䣺" << max_time << endl;
}

void run1()
{
    ALGraph G;
    CreateUDG(G);
    printf("�����ɹ�\n");
    CriticalPath(G);
}
