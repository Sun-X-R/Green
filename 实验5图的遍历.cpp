#include<iostream>


typedef int Status


//*********ͼ���ڽӱ�洢��ʾ*****
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

//************�ڽӱ�������ͼ******
Status CreateUDG(ALGraph &G)
{
    cout<<"�������ܶ��������ܱ�����\n";
    cin>>G.verxnum>>G.arcnum;
    cout<<"�����붥���ֵ��\n";
    for(i=0;i<G.vertices[i];i++)
    {
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    cout<<"����������ϡ�";
    for(k=0;k<G.arcnum;++k)
    {
        cout<<"����һ�����������������㣺\n";
        cin>>v1>>v2;
        i=LocateVex(G,v1);j=LocateVex(G,v2);
        p1=new ArcNode;
        p1->adjvex=j;

    }
}