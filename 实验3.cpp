#include <iostream>
#include<string>

/******˳��ջ�Ľṹ����******/
#define MAXSIZE 100
typedef int SElemType;
typedef struct
{
    SElemType *base; //ջ��ָ��
    SElemType *top; //ջ��ָ��
    int stacksize; //ջ��С
}SqStack;
/********ջ�ĳ�ʼ��*********/
int InitStack( SqStack &S )
{
    S.base =new SElemType[MAXSIZE]; //����ռ�
    if( !S.base ) 
        return 0; //����ʧ�ܷ���
    S.top = S.base; //��ʼʱջ����ջ����ͬ
    S.stacksize = MAXSIZE; //����ջ������
    return 1;
}
/********ջ���ж�*********/
bool StackEmpty( SqStack S )
{
    if(S.top == S.base) 
        return 1;
    else 
        return 0;
}
/********��ջ***********/
int Push( SqStack &S, char ch)
{
    if( S.top - S.base== S.stacksize )  // ջ��
        return 0;
    *S.top++=ch;
    return 1;
}
/*********��ջ*********/
char Pop( SqStack &S)
{
    if( S.top == S.base ) // ջ��
        return 0;
    S.top--;
    return *S.top;
}
/*********����˳��ջ*******/
bool DestroyStack( SqStack &S )
{
    if( S.base )
    {
        delete S.base ;//ɾ������ָ��
        S.stacksize = 0;
        S.base = S.top = NULL;
    }
    return 1;
}

int main()
{
    SqStack S;
    SElemType e;
    InitStack(S);
    char ch[100]={'\0'};
    printf("������Ҫ�жϵ��ַ���\n");
    scanf("%s",ch);
    int flag=1; 
    int i;
    for(i=0; ch[i]!='\0'; i++)
    {
        if((ch[i] == '{' )|| (ch[i] =='[') || (ch[i] =='('))
        {
            Push(S, ch[i]);        
        }
        else if((ch[i] == '}') || (ch[i] ==']') || (ch[i] ==')'))
        { 
            char a;
            a = Pop(S);
                
            if((a == '{' && ch[i] == '}') || (a == '(' && ch[i] == ')') || (a == '[' && ch[i] == ']'))
            {
                continue;
            }
            else flag = 0;      
        } 
    }
    if(!(S.top == S.base))
    {    //�������Ŷ��û����������ƥ���ʱ���磺" {() "��
    flag = 0;
    } 
    if(flag == 0) printf("NO");
    else printf("YES");  

    return 0;
}
