#include<stdio.h>
#include <iostream>

typedef int Status;
typedef char TElemType;
#define OK 1
#define error 0
#define MaxSize 100

/*******��������ʽ�洢�ṹ********/
typedef struct BiTNode
{
    TElemType data; //���������
    struct BiTNode *lchild,*rchild; //���Һ���ָ��
}BiTNode,*BiTree;

void InitBiTree(BiTree T);
void CreateBiTree(BiTree &T);
void DestroyBiTree(BiTree &T);
int PrLeaf(BiTree T);
int Depth(BiTree T);
int NodeCount(BiTree T);
int LeafCount(BiTree T);
Status PreOrderTraverse(BiTree T);
Status InOrderTraverse(BiTree T);
Status PostOrderTraverse(BiTree T);


/********����ն�����T*******/
void InitBiTree(BiTree T)
{
    T = NULL;
} 

/********����������*********/
void CreateBiTree(BiTree &T) 
{
    char ch;
	std::cin>>ch;	
//    scanf("%c",ch); 
    if (ch=='#') T=NULL; //�ݹ������������
    else
    {
        T=new BiTNode; T->data=ch; //���ɸ����
        CreateBiTree(T->lchild); //�ݹ鴴��������
        CreateBiTree(T->rchild); //�ݹ鴴��������
    }
}
/*********���ٶ�����**********/
void DestroyBiTree(BiTree &T)
{
    if (T==NULL) return ;
    else
    { 
        DestroyBiTree (T->lchild);
        DestroyBiTree (T->rchild);
        delete(T); //ʣ��һ�����*T��ֱ���ͷ�
    }
}
/*********����������ܽ����**********/
int NodeCount(BiTree T)
{
    if(T == NULL ) return 0;
    else
    return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}
/*********���������Ҷ�ӽ����********/
int LeafCount(BiTree T)
{
    if(T==NULL) //����ǿ�������0
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return 1; //�����Ҷ�ӽ�㷵��1
    else return LeafCount(T->lchild) + LeafCount(T->rchild);
}
/*******���Ҷ�ӽ��*********/
int PrLeaf(BiTree T)
{
    if(T==NULL) //����ǿ�������0
        return 0;
    else
    {
	PrLeaf(T->lchild); //�ݹ����������
    PrLeaf(T->rchild); //�ݹ����������	
    if (T->lchild == NULL && T->rchild == NULL)
		printf("%c ",T->data);
	}
} 
/*******����������߶�**********/
int Depth(BiTree T)
{
	char m,n;
	if(T==NULL) return 0;
	else
	{
		m=Depth(T->lchild);	//�ݹ��������������ȼ�Ϊm
		n=Depth(T->rchild);	//�ݹ��������������ȼ�Ϊn
		if(m>n) return(m+1); 
		else return(n+1); 
	}
		
}
/******�������������*******/
Status PreOrderTraverse(BiTree T)
{
    if(T==NULL) return OK; //�ն�����
    else
    {
        printf("%c ",T->data); //���ʸ����cout<<T->data;
        PreOrderTraverse(T->lchild); //�ݹ����������
        PreOrderTraverse(T->rchild); //�ݹ����������
    }
}
/*****�������������********/
Status InOrderTraverse(BiTree T)
{
    if(T==NULL) return OK; //�ն�����
    else
    {
        InOrderTraverse(T->lchild); //�ݹ����������
        printf("%c ",T->data); //���ʸ����cout<<T->data;
        InOrderTraverse(T->rchild); //�ݹ����������
    }
}
/*****�������������*********/
Status PostOrderTraverse(BiTree T)
{
    if(T==NULL) return OK; //�ն�����
    else
    {
        PostOrderTraverse(T->lchild); //�ݹ����������
        PostOrderTraverse(T->rchild); //�ݹ����������
        printf("%c ",T->data); //���ʸ����cout<<T->data;
    }
}

int main()
{
    BiTree T;
    TElemType data;
    TElemType t=1;
    printf("���������˳���������������������ַ���˳��Ϊ��abd#e##fg###c##\n");
    InitBiTree(T);
    CreateBiTree(T);
	printf("\n");
    printf("�������Ϊ��");
	PreOrderTraverse(T); 
	printf("\n");
	printf("�������Ϊ��");
	InOrderTraverse(T); 
	printf("\n");
	printf("�������Ϊ��");
	PostOrderTraverse(T);
	printf("\n");
	printf("�ö������Ľ������Ϊ��%d\n",NodeCount(T));
	printf("�ö�������Ҷ�ӽ������Ϊ��%d\n",LeafCount(T));
	printf("�ö������ĸ߶�Ϊ��%d\n",Depth(T));

	printf("����������");
	DestroyBiTree(T); 
}

