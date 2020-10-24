#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType; //ElemType 为可定义的数据类型，此设为int类型

#define MAXSIZE 100			//顺序表可能达到的最大长度
struct Student 
{
	int id;//ID
	string name;//name
	int age;//Age
    int score;//Score
    int rank;//Rank
};
typedef struct 
{
	Student *elem; //存储空间的基地址
	int length; //当前长度
} SqList;

//***********顺序表的建立*********
Status InitList_Sq(SqList &L) 
{ 
	//构造一个空的顺序表L
	L.elem = new Student[MAXSIZE]; //为顺序表分配一个大小为MAXSIZE的数组空间
	if (!L.elem)
		exit(OVERFLOW); //存储分配失败退出
	L.length = 0; //空表长度为0
	return OK;
}

//**************顺序查找**********
int Search_Seq(SqList L, int key)
{
    //在顺序表ST中顺序查找其关键字等于key的数据元素。若找到，则函数值为
    //该元素在表中的位置，否则为0
     for (int i=L.length; i>=0; --i)  
             if (L.elem[i].id==key) return i;		//从后往前找        
     return -1;
   }// Search_Seq

//**************折半查找************
int Search_Bin(SqList L,int key) 
{
   // 在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为
   // 该元素在表中的位置，否则为0
   int low=0,high=L.length;							//置查找区间初值
   int  mid;
   while(low<=high) 
   {
	   mid=(low+high) / 2;
      if (key==L.elem[mid].id)  return mid;      		//找到待查元素
      else if (key<L.elem[mid].id)  high = mid -1;		//继续在前一子表进行查找
            else  low =mid +1;                       			//继续在后一子表进行查找
   }//while
   return -1;										//表中不存在待查元素
}// Search_Bin

void Show_End(int result,int testkey)
{
	if(result==-1)
		cout<<"未找到"<<testkey<<endl;
	else
	{
		cout<<"找到"<<testkey<<"位置为"<<result<<endl;
	}
	return;
}

int main()
{
	SqList L;
	int i = 0, temp, a, c, choose;
	double price;
	Student e;
	string head_1, head_2, head_3,head_4,head_5;
    InitList_Sq(L);
//*********用文件建立表********
	i = 0;
	L.elem = new Student[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	fstream file;
	file.open("Student.txt");
	if (!file) 
    {
		cout << "错误！未找到文件！" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3>> head_4 >> head_5;
	while (!file.eof()) 
    {
		file >> L.elem[i].id >> L.elem[i].name >> L.elem[i].age>>L.elem[i].score>>L.elem[i].rank;
		i++;
	}
	cout << "输入 Student.txt 信息完毕\n\n";
	L.length = i;
	file.close();
//*******打印表********
	cout << "学生信息（顺序表）如下:\n";
	cout<< left << setw(5)<<"ID"<< "\t" << left
				<< setw(21)<<"Name"<<"\t" << left
				<< setw(5)<<"Age"<<"\t" << left
				<< setw(5)<<"Rank"<<"\t" << left
				<< setw(5)<<"Score"<<endl;
	for (i = 0; i < L.length; i++)
		cout << left << setw(5) << L.elem[i].id << "\t" << left
				<< setw(20) << L.elem[i].name << "\t" << left
				<< setw(5) << L.elem[i].age <<"\t" << left
				<< setw(5) << L.elem[i].score<<"\t" << left
				<< setw(5) << L.elem[i].rank << endl;
	cout << endl;

	int testkey;
	cout<<"输入要查找的ID："<<endl;
	cin>>testkey;
	int result;

    printf("顺序查找结果：\n");
	result=Search_Seq(L, testkey);
	Show_End(result,testkey);
		cout<<"Name:"<<L.elem[result].name<<endl;
		cout<<"Age:"<<L.elem[result].age<<endl;
		cout<<"Score:"<<L.elem[result].score<<endl;
		cout<<"Rank:"<<L.elem[result].rank<<endl;
		cout<<endl;

    printf("折半查找结果：\n");
	result=Search_Bin(L, testkey);
	Show_End(result,testkey);  
		cout<<"Name:"<<L.elem[result].name<<endl;
		cout<<"Age:"<<L.elem[result].age<<endl;
		cout<<"Score:"<<L.elem[result].score<<endl;
		cout<<"Rank:"<<L.elem[result].rank<<endl; 
}