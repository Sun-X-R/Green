#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
int num1[10000];    //��ԭʼ�����
int num2[10000];    //������������
#define random(n) rand()%n
/*******
Ҫȡ��[0,n)  ����rand����%n     ��ʾ ��0��n-1����
Ҫȡ��[a,b)�����������ʹ��(rand() % (b-a))+ a; 
Ҫȡ��[a,b]�����������ʹ��(rand() % (b-a+1))+ a; 
Ҫȡ��(a,b]�����������ʹ��(rand() % (b-a))+ a + 1; 
ͨ�ù�ʽ:a + rand() % n�����е�a����ʼֵ��n�������ķ�Χ�� 
Ҫȡ��a��b֮��������������һ�ֱ�ʾ��a + (int)b * rand() / (RAND_MAX + 1)�� 
Ҫȡ��0��1֮��ĸ�����������ʹ��rand() / double(RAND_MAX)��
*******/

//***********���������*******
void RandNum(){
//******���������
    srand((int)time(0));  // ����������� 
    for (int i = 1; i <= 10000; i++) //Ϊֱ�Ӳ���������num[0]��������
    {
        num1[i] = random(10000);
        num2[i]=num1[i];
//        cout<<num1[i]<<" ";          //����
    }
    cout<<endl;
}

//********ֱ�Ӳ�������*****
void InsertSort(int *num){
    int i,j;
    for(i=2;i<=10000;++i)
        if(num[i]<num[i-1]){                //��С�Ƚ�
            num[0]=num[i];
            num[i]=num[i-1];                //���ݺ���
            for(j=i-2;num[0]<num[j];--j){   //��ǰ�����Ҳ���λ��
                num[j+1]=num[j];
            }
            num[j+1]=num[0];

        }
}

//*********�۰��������******
void BInsertSort(int *num){
    int i,j,low,high,mid;
    for(i=2;i<=10000;++i){
        num[0]=num[i];
		low=1; high=i-1;        					//�ò��������ֵ
		while(low<=high)
		{											//��num[low..high]���۰���Ҳ����λ��
			mid=(low+high)/2;             			//�۰�
			if(num[0]<num[mid])  high=mid-1;	        //�������ǰһ�ӱ�
			else  low=mid+1;					   		//������ں�һ�ӱ�
		}
		for(j=i-1;j>=high+1;--j)  num[j+1]=num[j];	//��¼����
		num[high+1]=num[0];							//��num[0]��ԭnum[i]�����뵽��ȷλ��        
    }
}

//***********ϣ������*******
void ShellInsert(int *num,int dk)
{
	//��������һ��������dk��ϣ����������
	int i,j;
	for(i=dk+1;i<=10000;++i)
		if(num[i]<num[i-dk])
		{										//�轫num[i]�������������ӱ�
			num[0]=num[i];						//�ݴ���num[0]
			for(j=i-dk;j>0&& num[0]<num[j];j-=dk)
				num[j+dk]=num[j];				//��¼���ƣ�ֱ���ҵ�����λ��
			num[j+dk]=num[0];					//��r[0]��ԭr[i]�����뵽��ȷλ��
		}										//for
}
void ShellSort(int *num,int dt[ ],int t){
   //����������dt[0..t-1]��������t��ϣ������
	int k;
    for(k=0;k<t;++k)
        ShellInsert(num,dt[k]);			 		//һ������Ϊdt[t]��ϣ����������
}

//*********ð������********
void BubbleSort(int *num)
{
	//��������ð������
	int m,j,flag;
	int t;
    m=10000-1; flag=1; 				//flag�������ĳһ�������Ƿ�������
    while((m>0)&&(flag==1))
	{
		flag=0;           				//flag��Ϊ0�������������û�з����������򲻻�ִ����һ������
        for(j=1;j<=m;j++)
			if(num[j]>num[j+1]) 
			{
				flag=1;					//flag��Ϊ1����ʾ�����������˽���
				t=num[j];num[j]=num[j+1];num[j+1]=t;	//����ǰ��������¼
			}							
		--m;
    }									
}

//**********��������*******
int Partition(int *num,int low,int high)
{ 
	//��������num[low..high]����һ�����򣬷�������λ��
	int pivotkey;
	num[0]=num[low];                    	//���ӱ�ĵ�һ����¼�������¼
	pivotkey=num[low];		   			//�����¼�ؼ��ֱ�����pivotkey��
	while(low<high)
	{										//�ӱ�����˽�������м�ɨ��
		while(low<high&&num[high]>=pivotkey) --high;
		num[low]=num[high];					//���������¼С�ļ�¼�Ƶ��Ͷ�
		while(low<high&&num[low]<=pivotkey) ++low;
		num[high]=num[low];					//���������¼��ļ�¼�Ƶ��߶�
	}//while
	num[low]=num[0];						//�����¼��λ
	return  low;							//��������λ��
}//Partition
void QSort(int *num,int low,int high)
{	//����ǰ�ó�ֵ��low=1; high=10000;
    //�������е�������num[low..high]����������
	int pivotloc;
    if(low<high)
	{										//���ȴ���1
       pivotloc=Partition(num,low,high); 		//��num[low..high]һ��Ϊ����pivotloc������λ��
       QSort(num,low,pivotloc-1);				//�����ӱ�ݹ�����
       QSort(num,pivotloc+1,high);        	//�����ӱ�ݹ�����
	}
}											//QSort
void QuickSort(int *num)
{
   //����������������
   QSort(num,1,10000);
}											//QuickSort

//**********��ѡ������****
void SelectSort(int *num) 
{ 
   //��˳���L����ѡ������
	int i,j,k;
	int t;
    for(i=1;i<10000;++i) 
	{  												//��num[i..10000] ��ѡ��ؼ�����С�ļ�¼
		k=i;                 
        for(j=i+1;j<=10000;++j)
			if(num[j]<num[k])  k=j;			//kָ����������йؼ�����С�ļ�¼
		if(k!=i) {t=num[i];num[i]=num[k];num[k]=t;} //����r[i]��r[k]        
     }												//for  
}													// SelectSort

//**********��·�鲢����******
void Merge(int R[],int T[],int low,int mid,int high)
{ 
   //������R[low..mid]��R[mid+1..high]�鲢Ϊ����T[low..high] 
	int i,j,k;
	i=low; j=mid+1;k=low; 
    while(i<=mid&&j<=high)
	{                 	
		//��R�м�¼��С����ز���T�� 
		if(R[i]<=R[j]) T[k++]=R[i++]; 
        else T[k++]=R[j++]; 
	} 
	while(i<=mid)                            		//��ʣ���R[low..mid]���Ƶ�T�� 
		T[k++]=R[i++];                 
	while(j<=high)                           		//��ʣ���R[j.high]���Ƶ�T�� 
		T[k++]=R[j++];                       
}//Merge 
void MSort(int R[],int T[],int low,int high)
{ 
	//R[low..high]�鲢��������T[low..high]�� 
	int mid;
	int *S=new int[10000];
    if(low==high) T[low]=R[low]; 
    else
	{ 
		mid=(low+high)/2;       					//����ǰ����һ��Ϊ����������ѵ�mid 
        MSort(R,S,low,mid);							//��������R[low..mid] �ݹ�鲢���򣬽������S[low..mid] 
        MSort(R,S,mid+1,high);						//��������R[mid+1..high] �ݹ�鲢���򣬽������S[mid+1..high] 
        Merge(S,T,low,mid,high);					//��S[low..mid]��S [mid+1..high]�鲢��T[low..high]  
    }//else 
}// MSort 
void MergeSort(int *num)
{ 
	//��˳���L���鲢���� 
    MSort(num,num,1,10000); 
}//MergeSort 

//**********ֱ�Ӳ���������ʱ******
void InsertSortTime(){
    clock_t start=clock();
    InsertSort(num2);
    clock_t ends=clock();
    cout <<"ֱ�Ӳ���������ʱ : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2���¸�ֵΪnum1
}

//**********�۰����������ʱ******
void BInsertSortTime(){
    clock_t start=clock();
    BInsertSort(num2);
    clock_t ends=clock();
    cout <<"�۰����������ʱ : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2���¸�ֵΪnum1
}

//*********ϣ��������ʱ******
void ShellSortTime(){
	int t=10;//��������ĳ���
	int dt[10]={1023,511,255,127,63,31,15,7,3,1};//Hibbard��������
    clock_t start=clock();
	ShellSort(num2,dt,t);
    clock_t ends=clock();
    cout <<"ϣ������������ʱ : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2���¸�ֵΪnum1
}

//********ð��������ʱ******
void BubbleSortTime(){
    clock_t start=clock();
    BubbleSort(num2);
    clock_t ends=clock();
    cout <<"ð��������ʱ : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2���¸�ֵΪnum1
}

//*********����������ʱ*****
void QuickSortTime(){
    clock_t start=clock();
    QuickSort(num2);
    clock_t ends=clock();
    cout <<"����������ʱ : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2���¸�ֵΪnum1    
}

//*********��ѡ��������ʱ******
void SelectSortTime(){
    clock_t start=clock();
    SelectSort(num2);
    clock_t ends=clock();
    cout <<"��ѡ��������ʱ : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2���¸�ֵΪnum1     
}

//*********��·�鲢������ʱ******
void MergeSortTime(){
    clock_t start=clock();
    MergeSort(num2);
    clock_t ends=clock();
    cout <<"��·�鲢������ʱ : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2���¸�ֵΪnum1     
}

int main()
{
    RandNum();
    InsertSortTime();
    BInsertSortTime();
    ShellSortTime();
    BubbleSortTime();
    QuickSortTime();
    SelectSortTime();
    MergeSortTime();
    return 0;
}