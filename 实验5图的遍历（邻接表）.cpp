
#include<iostream>
#include<queue>
using namespace std;
 
struct ArcNode
{
	int adjvex;               //该弧所指向的顶点的位置
	ArcNode * next;           //指向下一条弧的指针8
	                          //int weight;边上是否有权
};

typedef struct VNode
{
	char vertex;              //顶点信息
	ArcNode * firstarc;       //指向第一条依附该顶点的弧的指针 
}AdjList[20];
 
struct ALGraph
{
	AdjList adjList;
	int vexNum;               //图的顶点数
	int arcNum;               //图的弧数
};
 
bool visited[20];//设置标志数组
 
void CreateGraph(ALGraph & graph);
void PrintGraph(ALGraph & graph);
void DFSTraverse(ALGraph & graph);
void BFSTraverse(ALGraph & graph);
 
int main()
{ 
	ALGraph graph;
 
	//1.创建邻接表
	CreateGraph(graph);
 
	//2.打印邻接表
	cout << "\n邻接表打印为: \n";
	PrintGraph(graph);
 
	//3.深度优先搜索DFS
	cout << "\n深度优先搜索DFS: ";
	DFSTraverse(graph);
	cout << endl;
 
	//4.广度优先搜索BFS
	cout << "\n广度优先搜索BFS: ";
	BFSTraverse(graph);
	cout << endl<<endl;
 
	return 0;
}
void CreateGraph(ALGraph & graph)
{
//	1.输入顶点数和弧数
	cout << "请输入图的顶点数和弧数: ";
	cin >> graph.vexNum >> graph.arcNum;
 
//2.输入顶点信息
	cout << "请输入" << graph.vexNum << "个顶点信息: ";
	for (int i = 0; i < graph.vexNum; i++)
	{
		cin >> graph.adjList[i].vertex;
		graph.adjList[i].firstarc = NULL;
	}
 
//3.根据输入的弧的信息构造邻接表
	cout << "请输入" << graph.arcNum << "个弧的信息:（取起始点为0） \n";
	int h1, h2;
	ArcNode * temp;
	for (int i = 0; i < graph.arcNum; i++)
	{
		cin >> h1 >> h2;
 
		temp = new ArcNode;
		temp->adjvex = h1;
		temp->next = graph.adjList[h2].firstarc;
		graph.adjList[h2].firstarc = temp;

		temp = new ArcNode;
		temp->adjvex = h2;
		temp->next = graph.adjList[h1].firstarc;
		graph.adjList[h1].firstarc = temp;
 

	}
}
void PrintGraph(ALGraph & graph)
{
	for (int i = 0; i < graph.vexNum; i++)
	{
		cout << graph.adjList[i].vertex << "------>";
		ArcNode * p = graph.adjList[i].firstarc;
		while (p)
		{
			cout << graph.adjList[p->adjvex].vertex << "  ";
			p = p->next;
		}
		cout << endl;
	}
}

void DFS(ALGraph & graph, int v)
{
	visited[v] = true;
	cout << graph.adjList[v].vertex << " ";
 
	ArcNode * p = graph.adjList[v].firstarc;
 
	while (p)
	{
		if (!visited[p->adjvex])
			DFS(graph, p->adjvex);
 
		p = p->next;
	}
}
 
void DFSTraverse(ALGraph & graph)
{
	for (int i = 0; i < graph.vexNum; i++)//初始化访问标志数组
		visited[i] = false;
 
	for (int i = 0; i < graph.vexNum; i++)
	{
		if (!visited[i])//如果没有访问
			DFS(graph, i);
	}
}

void BFSTraverse(ALGraph & graph)
{
	for (int i = 0; i < graph.vexNum; i++)//初始化访问标志数组 
		visited[i] = false;
 
	queue<int> q;
 
	for (int i = 0; i < graph.vexNum; i++)
	{
		if (!visited[i])//如果没有访问过
		{
			visited[i] = true;
			q.push(i);//访问过的入队列
			cout << graph.adjList[i].vertex << " ";
 
			while (!q.empty())//队列不为空时
			{
				int x = q.front();
				q.pop();//先取出队首第一个元素，然后将第一个元素删除
				ArcNode * p = graph.adjList[x].firstarc;
				while (p)//访问未被访问过的邻接顶点
				{
					if (!visited[p->adjvex])
					{
						visited[p->adjvex] = true;
						cout << graph.adjList[p->adjvex].vertex << " ";
						q.push(p->adjvex);
					}
 
					p = p->next;
				}
			}
		}
	}
}
