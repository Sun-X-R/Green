#include <iostream>
#include<string>

/******顺序栈的结构定义******/
#define MAXSIZE 100
typedef int SElemType;
typedef struct
{
    SElemType *base; //栈底指针
    SElemType *top; //栈顶指针
    int stacksize; //栈大小
}SqStack;
/********栈的初始化*********/
int InitStack( SqStack &S )
{
    S.base =new SElemType[MAXSIZE]; //分配空间
    if( !S.base ) 
        return 0; //分配失败返回
    S.top = S.base; //初始时栈顶和栈底相同
    S.stacksize = MAXSIZE; //设置栈的容量
    return 1;
}
/********栈空判断*********/
bool StackEmpty( SqStack S )
{
    if(S.top == S.base) 
        return 1;
    else 
        return 0;
}
/********入栈***********/
int Push( SqStack &S, char ch)
{
    if( S.top - S.base== S.stacksize )  // 栈满
        return 0;
    *S.top++=ch;
    return 1;
}
/*********出栈*********/
char Pop( SqStack &S)
{
    if( S.top == S.base ) // 栈空
        return 0;
    S.top--;
    return *S.top;
}
/*********销毁顺序栈*******/
bool DestroyStack( SqStack &S )
{
    if( S.base )
    {
        delete S.base ;//删除基地指针
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
    printf("请输入要判断的字符串\n");
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
    {    //当左括号多出没有与右括号匹配的时候（如：" {() "）
    flag = 0;
    } 
    if(flag == 0) printf("NO");
    else printf("YES");  

    return 0;
}
