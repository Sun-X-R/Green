/*******
����������
������ʵ��ͼ�����   ��Ϣ���ݰ�����ISBN���������۸�
��Ҫ���ܣ�˳����������롢ɾ�������ҵȹ��ܵ�ʵ��

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

//*******�ṹ����******
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

//*********���ʼ��*******
int InitList(SqList &L)
{
    L.elem=new Book[MAXSIZE];   //��ռ����
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    return OK;
}

//*************�����*****
int SelcList(SqList L,double e)
{
    for(int i=0;i<L.length;i++)
        if(L.elem[i].price==e)
            return i+1;     //��ŵ��ڴ洢�ż�һ
    return 0;       //����ʧ��
}

//************�����******
int InsertList(SqList &L,int i,Book e)
{
    
    if((i<1)||(i>L.length+1))   return ERROR;   //input i error
    if(L.length==MAXSIZE)   return ERROR;   //list full

    for(int j=L.length-1;j>=i-1;j--)
        L.elem[j+1]=L.elem[j];        //����λ�ú��Ԫ�������
    L.elem[i-1]=e;      //eֵ�����iλ
    ++L.length;
    return OK;
}

//*************��ɾ��***********
int DeleteList(SqList &L,int i)
{ 
    if ((i < 1) || (i > L.length))
        return ERROR;    //iֵ���Ϸ�
    for (int j = i; j <= L.length; j++)
        L.elem[j - 1] = L.elem[j];      //ɾ��Ԫ��  Ԫ��ǰ��
    --L.length; 
    return OK;
}

//*************�����*********
void CountList(SqList &L)
{
    printf("��Ϊ��%d",L.length);
}

//**********������*******
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

//**********���ļ�����*******
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
       printf("����δ�ҵ��ļ���");
         exit(ERROR);
    }
    file >> head_1 >> head_2 >> head_3;
    while (!file.eof()) 
    {
    file >> L.elem[i].id >> L.elem[i].name >> L.elem[i].price;
        i++;
    }
    printf("���� book.txt ��Ϣ���\n");
		L.length = i;
		file.close();
}


int main()
{
    SqList L;
    int i = 0, temp, a, c;
    double price;
    Book e;
//����
    InitList(L);        
    if(InitList(L))
    printf("�����ɹ�");

    ListInto(L);    //�ļ����� 
//�����
	cout << "��ǰͼ��ϵͳ��Ϣ��˳������:\n";
	for (i = 0; i < L.length; i++)
		cout << left << setw(15) << L.elem[i].id << "\t" << left
				<< setw(50) << L.elem[i].name << "\t" << left
				<< setw(5) << L.elem[i].price << endl;
	cout << endl;    
//�����
    printf("����룺\n��������λ�á�ISBN���������۸��м��ÿո����\n");
    cin>>a;
    cin>>e.id>>e.name>>e.price;
    if (InsertList(L, a, e))
		printf("����ɹ�.\n");
	else
		printf("����ʧ��.\n");
//�����
	cout << "��ǰͼ��ϵͳ��Ϣ��˳������:\n";
	for (i = 0; i < L.length; i++)
		cout << left << setw(15) << L.elem[i].id << "\t" << left
				<< setw(50) << L.elem[i].name << "\t" << left
				<< setw(5) << L.elem[i].price << endl;
	cout << endl;  
//��ɾ��
	printf("��������Ҫɾ�����鼮��λ��:");
	cin >> c;
	if (DeleteList(L, c))
		printf("ɾ���ɹ�.\n");
	else
		printf("ɾ��ʧ��.\n");
//�����
	cout << "��ǰͼ��ϵͳ��Ϣ��˳������:\n";
	for (i = 0; i < L.length; i++)
		cout << left << setw(15) << L.elem[i].id << "\t" << left
				<< setw(50) << L.elem[i].name << "\t" << left
				<< setw(5) << L.elem[i].price << endl;
	cout << endl;  
//���ѯ
 	printf("��������Ҫ���Ҽ۸�:");
	cin >> price;
	temp = SelcList(L, price);
	if (temp != 0)
    {
		printf("���ҳɹ�\n");
		cout << "�ü۸��Ӧ������Ϊ��" << L.elem[temp - 1].name << endl << endl;
    }
    else
		printf("����ʧ�ܣ�\n") ; 
}
