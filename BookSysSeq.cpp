/*******
问题描述：
建立表，实现图书管理   信息内容包括：ISBN、书名、价格
主要功能：顺序表创建、插入、删除、查找等功能的实现

*********/

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100

//*******结构定义******
struct Book
{
    string id;  // ISBN
    string name;    //bookname
    double price;   //bookprice
};
typedef struct
{
    Book *elem; 
    int length;
}SqList;

//*********表初始化*******
int InitList(SqList &L)
{
    L.elem=new Book[MAXSIZE];   //表空间分配
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    return OK;
}

//*************表查找*****
int SelcList(SqList L,double e)
{
    for(int i=0;i<L.length;i++)
        if(L.elem[i].price==e)
            return i+1;     //序号等于存储号加一
    return 0;       //查找失败
}

//************表插入******
int InsertList(SqList &L,int i,Book e)
{
    
    if((i<1)||(i>L.length+1))   return ERROR;   //input i error
    if(L.length==MAXSIZE)   return ERROR;   //list full

    for(int j=L.length-1;j>=i-1;j--)
        L.elem[j+1]=L.elem[j];        //插入位置后的元素需后移
    L.elem[i-1]=e;      //e值放入第i位
    ++L.length;
    return OK;
}

//*************表删除***********
int DeleteList(SqList &L,int i)
{ 
    if ((i < 1) || (i > L.length))
        return ERROR;    //i值不合法
    for (int j = i; j <= L.length; j++)
        L.elem[j - 1] = L.elem[j];      //删除元素  元素前移
    --L.length; 
    return OK;
}

//*************表计数*********
void CountList(SqList &L)
{
    printf("表长为：%d",L.length);
}

//**********表排序*******
void ListPaixu(SqList &L)
{
    int m=L.length-1;
    int flag=1;
    while((m>0)&&(flag==1))
    {
        flag=0;
        for(int j=1;j<=m;j++)
            if(L.elem[j].price<L.elem[j+1].price)
            {
                flag=1;
                L.elem[99]=L.elem[j]; L.elem[j]=L.elem[j+1]; L.elem[j+1]=L.elem[99];
            }
            --m;
    }
}

//**********表文件输入*******
void ListInto(SqList &L)
{
    string head_1, head_2, head_3;
    int i = 0;
    L.elem = new Book[MAXSIZE];
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    fstream file;
    file.open("book.txt");
    if (!file) 
    {
       printf("错误！未找到文件！");
         exit(ERROR);
    }
    file >> head_1 >> head_2 >> head_3;
    while (!file.eof()) 
    {
    file >> L.elem[i].id >> L.elem[i].name >> L.elem[i].price;
        i++;
    }
    printf("导入 book.txt 信息完毕\n");
		L.length = i;
		file.close();
}


int main()
{
    SqList L;
    int i = 0, temp, a, c;
    double price;
    Book e;
//表建立
    InitList(L);        
    if(InitList(L))
    printf("表建立成功");

    ListInto(L);    //文件导入 
//表输出
	cout << "当前图书系统信息（顺序表）输出:\n";
	for (i = 0; i < L.length; i++)
		cout << left << setw(15) << L.elem[i].id << "\t" << left
				<< setw(50) << L.elem[i].name << "\t" << left
				<< setw(5) << L.elem[i].price << endl;
	cout << endl;    
//表插入
    printf("表插入：\n输入插入的位置、ISBN、书名、价格，中间用空格隔开\n");
    cin>>a;
    cin>>e.id>>e.name>>e.price;
    if (InsertList(L, a, e))
		printf("插入成功.\n");
	else
		printf("插入失败.\n");
//表输出
	cout << "当前图书系统信息（顺序表）输出:\n";
	for (i = 0; i < L.length; i++)
		cout << left << setw(15) << L.elem[i].id << "\t" << left
				<< setw(50) << L.elem[i].name << "\t" << left
				<< setw(5) << L.elem[i].price << endl;
	cout << endl;  
//表删除
	printf("请输入所要删除的书籍的位置:");
	cin >> c;
	if (DeleteList(L, c))
		printf("删除成功.\n");
	else
		printf("删除失败.\n");
//表输出
	cout << "当前图书系统信息（顺序表）输出:\n";
	for (i = 0; i < L.length; i++)
		cout << left << setw(15) << L.elem[i].id << "\t" << left
				<< setw(50) << L.elem[i].name << "\t" << left
				<< setw(5) << L.elem[i].price << endl;
	cout << endl;  
//表查询
 	printf("请输入所要查找价格:");
	cin >> price;
	temp = SelcList(L, price);
	if (temp != 0)
    {
		printf("查找成功\n");
		cout << "该价格对应的书名为：" << L.elem[temp - 1].name << endl << endl;
    }
    else
		printf("查找失败！\n") ; 
}
