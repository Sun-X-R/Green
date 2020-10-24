#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status; //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType; //ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

#define MAXSIZE 100			//˳�����ܴﵽ����󳤶�
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
	Student *elem; //�洢�ռ�Ļ���ַ
	int length; //��ǰ����
} SqList;

//***********˳���Ľ���*********
Status InitList_Sq(SqList &L) 
{ 
	//����һ���յ�˳���L
	L.elem = new Student[MAXSIZE]; //Ϊ˳������һ����СΪMAXSIZE������ռ�
	if (!L.elem)
		exit(OVERFLOW); //�洢����ʧ���˳�
	L.length = 0; //�ձ���Ϊ0
	return OK;
}

//**************˳�����**********
int Search_Seq(SqList L, int key)
{
    //��˳���ST��˳�������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ
    //��Ԫ���ڱ��е�λ�ã�����Ϊ0
     for (int i=L.length; i>=0; --i)  
             if (L.elem[i].id==key) return i;		//�Ӻ���ǰ��        
     return -1;
   }// Search_Seq

//**************�۰����************
int Search_Bin(SqList L,int key) 
{
   // �������ST���۰������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ
   // ��Ԫ���ڱ��е�λ�ã�����Ϊ0
   int low=0,high=L.length;							//�ò��������ֵ
   int  mid;
   while(low<=high) 
   {
	   mid=(low+high) / 2;
      if (key==L.elem[mid].id)  return mid;      		//�ҵ�����Ԫ��
      else if (key<L.elem[mid].id)  high = mid -1;		//������ǰһ�ӱ���в���
            else  low =mid +1;                       			//�����ں�һ�ӱ���в���
   }//while
   return -1;										//���в����ڴ���Ԫ��
}// Search_Bin

void Show_End(int result,int testkey)
{
	if(result==-1)
		cout<<"δ�ҵ�"<<testkey<<endl;
	else
	{
		cout<<"�ҵ�"<<testkey<<"λ��Ϊ"<<result<<endl;
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
//*********���ļ�������********
	i = 0;
	L.elem = new Student[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	fstream file;
	file.open("Student.txt");
	if (!file) 
    {
		cout << "����δ�ҵ��ļ���" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3>> head_4 >> head_5;
	while (!file.eof()) 
    {
		file >> L.elem[i].id >> L.elem[i].name >> L.elem[i].age>>L.elem[i].score>>L.elem[i].rank;
		i++;
	}
	cout << "���� Student.txt ��Ϣ���\n\n";
	L.length = i;
	file.close();
//*******��ӡ��********
	cout << "ѧ����Ϣ��˳�������:\n";
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
	cout<<"����Ҫ���ҵ�ID��"<<endl;
	cin>>testkey;
	int result;

    printf("˳����ҽ����\n");
	result=Search_Seq(L, testkey);
	Show_End(result,testkey);
		cout<<"Name:"<<L.elem[result].name<<endl;
		cout<<"Age:"<<L.elem[result].age<<endl;
		cout<<"Score:"<<L.elem[result].score<<endl;
		cout<<"Rank:"<<L.elem[result].rank<<endl;
		cout<<endl;

    printf("�۰���ҽ����\n");
	result=Search_Bin(L, testkey);
	Show_End(result,testkey);  
		cout<<"Name:"<<L.elem[result].name<<endl;
		cout<<"Age:"<<L.elem[result].age<<endl;
		cout<<"Score:"<<L.elem[result].score<<endl;
		cout<<"Rank:"<<L.elem[result].rank<<endl; 
}