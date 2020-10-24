#include<stdio.h>
#include <iostream>

typedef int Status;
typedef char TElemType;
#define OK 1
#define error 0
#define MaxSize 100

/*******二叉树链式存储结构********/
typedef struct BiTNode
{
    TElemType data; //结点数据域
    struct BiTNode *lchild,*rchild; //左右孩子指针
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


/********构造空二叉树T*******/
void InitBiTree(BiTree T)
{
    T = NULL;
} 

/********建立二叉树*********/
void CreateBiTree(BiTree &T) 
{
    char ch;
	std::cin>>ch;	
//    scanf("%c",ch); 
    if (ch=='#') T=NULL; //递归结束，建空树
    else
    {
        T=new BiTNode; T->data=ch; //生成根结点
        CreateBiTree(T->lchild); //递归创建左子树
        CreateBiTree(T->rchild); //递归创建右子树
    }
}
/*********销毁二叉树**********/
void DestroyBiTree(BiTree &T)
{
    if (T==NULL) return ;
    else
    { 
        DestroyBiTree (T->lchild);
        DestroyBiTree (T->rchild);
        delete(T); //剩下一个结点*T，直接释放
    }
}
/*********计算二叉树总结点数**********/
int NodeCount(BiTree T)
{
    if(T == NULL ) return 0;
    else
    return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}
/*********计算二叉树叶子结点数********/
int LeafCount(BiTree T)
{
    if(T==NULL) //如果是空树返回0
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return 1; //如果是叶子结点返回1
    else return LeafCount(T->lchild) + LeafCount(T->rchild);
}
/*******输出叶子结点*********/
int PrLeaf(BiTree T)
{
    if(T==NULL) //如果是空树返回0
        return 0;
    else
    {
	PrLeaf(T->lchild); //递归遍历左子树
    PrLeaf(T->rchild); //递归遍历右子树	
    if (T->lchild == NULL && T->rchild == NULL)
		printf("%c ",T->data);
	}
} 
/*******计算二叉树高度**********/
int Depth(BiTree T)
{
	char m,n;
	if(T==NULL) return 0;
	else
	{
		m=Depth(T->lchild);	//递归计算左子树的深度记为m
		n=Depth(T->rchild);	//递归计算右子树的深度记为n
		if(m>n) return(m+1); 
		else return(n+1); 
	}
		
}
/******先序遍历二叉树*******/
Status PreOrderTraverse(BiTree T)
{
    if(T==NULL) return OK; //空二叉树
    else
    {
        printf("%c ",T->data); //访问根结点cout<<T->data;
        PreOrderTraverse(T->lchild); //递归遍历左子树
        PreOrderTraverse(T->rchild); //递归遍历右子树
    }
}
/*****中序遍历二叉树********/
Status InOrderTraverse(BiTree T)
{
    if(T==NULL) return OK; //空二叉树
    else
    {
        InOrderTraverse(T->lchild); //递归遍历左子树
        printf("%c ",T->data); //访问根结点cout<<T->data;
        InOrderTraverse(T->rchild); //递归遍历右子树
    }
}
/*****后序遍历二叉树*********/
Status PostOrderTraverse(BiTree T)
{
    if(T==NULL) return OK; //空二叉树
    else
    {
        PostOrderTraverse(T->lchild); //递归遍历左子树
        PostOrderTraverse(T->rchild); //递归遍历右子树
        printf("%c ",T->data); //访问根结点cout<<T->data;
    }
}

int main()
{
    BiTree T;
    TElemType data;
    TElemType t=1;
    printf("先序遍历的顺序建立二叉链表，键盘输入字符的顺序为：abd#e##fg###c##\n");
    InitBiTree(T);
    CreateBiTree(T);
	printf("\n");
    printf("先序遍历为：");
	PreOrderTraverse(T); 
	printf("\n");
	printf("中序遍历为：");
	InOrderTraverse(T); 
	printf("\n");
	printf("后序遍历为：");
	PostOrderTraverse(T);
	printf("\n");
	printf("该二叉树的结点总数为：%d\n",NodeCount(T));
	printf("该二叉树的叶子结点总数为：%d\n",LeafCount(T));
	printf("该二叉树的高度为：%d\n",Depth(T));

	printf("交换二叉树");
	DestroyBiTree(T); 
}

