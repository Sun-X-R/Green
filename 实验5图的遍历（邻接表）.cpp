
#include<iostream>
#include<queue>
using namespace std;
 
struct ArcNode
{
	int adjvex;               //�û���ָ��Ķ����λ��
	ArcNode * next;           //ָ����һ������ָ��8
	                          //int weight;�����Ƿ���Ȩ
};

typedef struct VNode
{
	char vertex;              //������Ϣ
	ArcNode * firstarc;       //ָ���һ�������ö���Ļ���ָ�� 
}AdjList[20];
 
struct ALGraph
{
	AdjList adjList;
	int vexNum;               //ͼ�Ķ�����
	int arcNum;               //ͼ�Ļ���
};
 
bool visited[20];//���ñ�־����
 
void CreateGraph(ALGraph & graph);
void PrintGraph(ALGraph & graph);
void DFSTraverse(ALGraph & graph);
void BFSTraverse(ALGraph & graph);
 
int main()
{ 
	ALGraph graph;
 
	//1.�����ڽӱ�
	CreateGraph(graph);
 
	//2.��ӡ�ڽӱ�
	cout << "\n�ڽӱ��ӡΪ: \n";
	PrintGraph(graph);
 
	//3.�����������DFS
	cout << "\n�����������DFS: ";
	DFSTraverse(graph);
	cout << endl;
 
	//4.�����������BFS
	cout << "\n�����������BFS: ";
	BFSTraverse(graph);
	cout << endl<<endl;
 
	return 0;
}
void CreateGraph(ALGraph & graph)
{
//	1.���붥�����ͻ���
	cout << "������ͼ�Ķ������ͻ���: ";
	cin >> graph.vexNum >> graph.arcNum;
 
//2.���붥����Ϣ
	cout << "������" << graph.vexNum << "��������Ϣ: ";
	for (int i = 0; i < graph.vexNum; i++)
	{
		cin >> graph.adjList[i].vertex;
		graph.adjList[i].firstarc = NULL;
	}
 
//3.��������Ļ�����Ϣ�����ڽӱ�
	cout << "������" << graph.arcNum << "��������Ϣ:��ȡ��ʼ��Ϊ0�� \n";
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
	for (int i = 0; i < graph.vexNum; i++)//��ʼ�����ʱ�־����
		visited[i] = false;
 
	for (int i = 0; i < graph.vexNum; i++)
	{
		if (!visited[i])//���û�з���
			DFS(graph, i);
	}
}

void BFSTraverse(ALGraph & graph)
{
	for (int i = 0; i < graph.vexNum; i++)//��ʼ�����ʱ�־���� 
		visited[i] = false;
 
	queue<int> q;
 
	for (int i = 0; i < graph.vexNum; i++)
	{
		if (!visited[i])//���û�з��ʹ�
		{
			visited[i] = true;
			q.push(i);//���ʹ��������
			cout << graph.adjList[i].vertex << " ";
 
			while (!q.empty())//���в�Ϊ��ʱ
			{
				int x = q.front();
				q.pop();//��ȡ�����׵�һ��Ԫ�أ�Ȼ�󽫵�һ��Ԫ��ɾ��
				ArcNode * p = graph.adjList[x].firstarc;
				while (p)//����δ�����ʹ����ڽӶ���
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
