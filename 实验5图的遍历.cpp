#include<iostream>


typedef int Status


//*********图的邻接表存储表示*****
#define MVNum 100
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode * nextarc;
    OtherInfo info;  
}ArcNode;
typedef struct VNode
{
    VerTexType data;
    ArcNode *firstarc;
}VNode,AdjList[MVNum];
typedef struct 
{
    AdjList vertices;
    int verxnum,arcnum;
}ALGraph;

//************邻接表创建无向图******
Status CreateUDG(ALGraph &G)
{
    cout<<"请输入总顶点数和总边数：\n";
    cin>>G.verxnum>>G.arcnum;
    cout<<"请输入顶点的值：\n";
    for(i=0;i<G.vertices[i];i++)
    {
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    cout<<"顶点输入完毕。";
    for(k=0;k<G.arcnum;++k)
    {
        cout<<"输入一条边依附的两个顶点：\n";
        cin>>v1>>v2;
        i=LocateVex(G,v1);j=LocateVex(G,v2);
        p1=new ArcNode;
        p1->adjvex=j;

    }
}