#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;
int num1[10000];    //存原始随机数
int num2[10000];    //存排序后的数组
#define random(n) rand()%n
/*******
要取得[0,n)  就是rand（）%n     表示 从0到n-1的数
要取得[a,b)的随机整数，使用(rand() % (b-a))+ a; 
要取得[a,b]的随机整数，使用(rand() % (b-a+1))+ a; 
要取得(a,b]的随机整数，使用(rand() % (b-a))+ a + 1; 
通用公式:a + rand() % n；其中的a是起始值，n是整数的范围。 
要取得a到b之间的随机整数，另一种表示：a + (int)b * rand() / (RAND_MAX + 1)。 
要取得0～1之间的浮点数，可以使用rand() / double(RAND_MAX)。
*******/

//***********随机数产生*******
void RandNum(){
//******随机数产生
    srand((int)time(0));  // 产生随机种子 
    for (int i = 1; i <= 10000; i++) //为直接插入排序留num[0]做监视哨
    {
        num1[i] = random(10000);
        num2[i]=num1[i];
//        cout<<num1[i]<<" ";          //测试
    }
    cout<<endl;
}

//********直接插入排序*****
void InsertSort(int *num){
    int i,j;
    for(i=2;i<=10000;++i)
        if(num[i]<num[i-1]){                //大小比较
            num[0]=num[i];
            num[i]=num[i-1];                //数据后移
            for(j=i-2;num[0]<num[j];--j){   //在前部分找插入位置
                num[j+1]=num[j];
            }
            num[j+1]=num[0];

        }
}

//*********折半插入排序******
void BInsertSort(int *num){
    int i,j,low,high,mid;
    for(i=2;i<=10000;++i){
        num[0]=num[i];
		low=1; high=i-1;        					//置查找区间初值
		while(low<=high)
		{											//在num[low..high]中折半查找插入的位置
			mid=(low+high)/2;             			//折半
			if(num[0]<num[mid])  high=mid-1;	        //插入点在前一子表
			else  low=mid+1;					   		//插入点在后一子表
		}
		for(j=i-1;j>=high+1;--j)  num[j+1]=num[j];	//记录后移
		num[high+1]=num[0];							//将num[0]即原num[i]，插入到正确位置        
    }
}

//***********希尔排序*******
void ShellInsert(int *num,int dk)
{
	//对数组做一趟增量是dk的希尔插入排序
	int i,j;
	for(i=dk+1;i<=10000;++i)
		if(num[i]<num[i-dk])
		{										//需将num[i]插入有序增量子表
			num[0]=num[i];						//暂存在num[0]
			for(j=i-dk;j>0&& num[0]<num[j];j-=dk)
				num[j+dk]=num[j];				//记录后移，直到找到插入位置
			num[j+dk]=num[0];					//将r[0]即原r[i]，插入到正确位置
		}										//for
}
void ShellSort(int *num,int dt[ ],int t){
   //按增量序列dt[0..t-1]对数组作t趟希尔排序
	int k;
    for(k=0;k<t;++k)
        ShellInsert(num,dt[k]);			 		//一趟增量为dt[t]的希尔插入排序
}

//*********冒泡排序********
void BubbleSort(int *num)
{
	//对数组做冒泡排序
	int m,j,flag;
	int t;
    m=10000-1; flag=1; 				//flag用来标记某一趟排序是否发生交换
    while((m>0)&&(flag==1))
	{
		flag=0;           				//flag置为0，如果本趟排序没有发生交换，则不会执行下一趟排序
        for(j=1;j<=m;j++)
			if(num[j]>num[j+1]) 
			{
				flag=1;					//flag置为1，表示本趟排序发生了交换
				t=num[j];num[j]=num[j+1];num[j+1]=t;	//交换前后两个记录
			}							
		--m;
    }									
}

//**********快速排序*******
int Partition(int *num,int low,int high)
{ 
	//对数组中num[low..high]进行一趟排序，返回枢轴位置
	int pivotkey;
	num[0]=num[low];                    	//用子表的第一个记录做枢轴记录
	pivotkey=num[low];		   			//枢轴记录关键字保存在pivotkey中
	while(low<high)
	{										//从表的两端交替地向中间扫描
		while(low<high&&num[high]>=pivotkey) --high;
		num[low]=num[high];					//将比枢轴记录小的记录移到低端
		while(low<high&&num[low]<=pivotkey) ++low;
		num[high]=num[low];					//将比枢轴记录大的记录移到高端
	}//while
	num[low]=num[0];						//枢轴记录到位
	return  low;							//返回枢轴位置
}//Partition
void QSort(int *num,int low,int high)
{	//调用前置初值：low=1; high=10000;
    //对数组中的子序列num[low..high]做快速排序
	int pivotloc;
    if(low<high)
	{										//长度大于1
       pivotloc=Partition(num,low,high); 		//将num[low..high]一分为二，pivotloc是枢轴位置
       QSort(num,low,pivotloc-1);				//对左子表递归排序
       QSort(num,pivotloc+1,high);        	//对右子表递归排序
	}
}											//QSort
void QuickSort(int *num)
{
   //对数组做快速排序
   QSort(num,1,10000);
}											//QuickSort

//**********简单选择排序****
void SelectSort(int *num) 
{ 
   //对顺序表L做简单选择排序
	int i,j,k;
	int t;
    for(i=1;i<10000;++i) 
	{  												//在num[i..10000] 中选择关键字最小的记录
		k=i;                 
        for(j=i+1;j<=10000;++j)
			if(num[j]<num[k])  k=j;			//k指向此趟排序中关键字最小的记录
		if(k!=i) {t=num[i];num[i]=num[k];num[k]=t;} //交换r[i]与r[k]        
     }												//for  
}													// SelectSort

//**********二路归并排序******
void Merge(int R[],int T[],int low,int mid,int high)
{ 
   //将数组R[low..mid]和R[mid+1..high]归并为数组T[low..high] 
	int i,j,k;
	i=low; j=mid+1;k=low; 
    while(i<=mid&&j<=high)
	{                 	
		//将R中记录由小到大地并入T中 
		if(R[i]<=R[j]) T[k++]=R[i++]; 
        else T[k++]=R[j++]; 
	} 
	while(i<=mid)                            		//将剩余的R[low..mid]复制到T中 
		T[k++]=R[i++];                 
	while(j<=high)                           		//将剩余的R[j.high]复制到T中 
		T[k++]=R[j++];                       
}//Merge 
void MSort(int R[],int T[],int low,int high)
{ 
	//R[low..high]归并排序后放入T[low..high]中 
	int mid;
	int *S=new int[10000];
    if(low==high) T[low]=R[low]; 
    else
	{ 
		mid=(low+high)/2;       					//将当前序列一分为二，求出分裂点mid 
        MSort(R,S,low,mid);							//对子序列R[low..mid] 递归归并排序，结果放入S[low..mid] 
        MSort(R,S,mid+1,high);						//对子序列R[mid+1..high] 递归归并排序，结果放入S[mid+1..high] 
        Merge(S,T,low,mid,high);					//将S[low..mid]和S [mid+1..high]归并到T[low..high]  
    }//else 
}// MSort 
void MergeSort(int *num)
{ 
	//对顺序表L做归并排序 
    MSort(num,num,1,10000); 
}//MergeSort 

//**********直接插入排序用时******
void InsertSortTime(){
    clock_t start=clock();
    InsertSort(num2);
    clock_t ends=clock();
    cout <<"直接插入排序用时 : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2重新赋值为num1
}

//**********折半插入排序用时******
void BInsertSortTime(){
    clock_t start=clock();
    BInsertSort(num2);
    clock_t ends=clock();
    cout <<"折半插入排序用时 : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2重新赋值为num1
}

//*********希尔排序用时******
void ShellSortTime(){
	int t=10;//增量数组的长度
	int dt[10]={1023,511,255,127,63,31,15,7,3,1};//Hibbard增量序列
    clock_t start=clock();
	ShellSort(num2,dt,t);
    clock_t ends=clock();
    cout <<"希尔插入排序用时 : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2重新赋值为num1
}

//********冒泡排序用时******
void BubbleSortTime(){
    clock_t start=clock();
    BubbleSort(num2);
    clock_t ends=clock();
    cout <<"冒泡排序用时 : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2重新赋值为num1
}

//*********快速排序用时*****
void QuickSortTime(){
    clock_t start=clock();
    QuickSort(num2);
    clock_t ends=clock();
    cout <<"快速排序用时 : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2重新赋值为num1    
}

//*********简单选择排序用时******
void SelectSortTime(){
    clock_t start=clock();
    SelectSort(num2);
    clock_t ends=clock();
    cout <<"简单选择排序用时 : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2重新赋值为num1     
}

//*********二路归并排序用时******
void MergeSortTime(){
    clock_t start=clock();
    MergeSort(num2);
    clock_t ends=clock();
    cout <<"二路归并排序用时 : "<<(double)(ends - start)/ CLOCKS_PER_SEC*1000 << " ms"<<endl;
    memcpy(num2,num1,sizeof(num1));         //num2重新赋值为num1     
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