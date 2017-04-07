#include<stdio.h>


void printstack(int *stack,int top)
{
    int i;
    printf("\nThe stack is:   ");
    for(i=-1;i<top;i++)
    {
        printf(" ");
        printf("%3d\n ",top);
        printf("%3c",stack[i]);
    }
    for(i=0;i!='\0';i++)
        printf("%3c",stack[i]);

}
void push(char stack[],int *top,char ch)
{
    *top=*top+1;
    stack[*top]=ch;
}
char pop(char stack[],int *top)
{
    char ch=stack[*top];
    *top=*top-1;
    return(ch);
}
int getpreced(char ch)
{
    if(ch=='*'||ch=='/')
        return 2;
    if(ch=='+'||ch=='-')
        return 1;
}
int getvalue(char ch)
{
    if(ch=='a')
        return 10;
    if(ch=='b')
        return 8;
    if(ch=='c')
        return 6;
    if(ch=='d')
        return 4;
}

int isempty(int top)
{
    if(top==-1)
        return 1;
    return 0;
}
int isfulli(int top)
{
    if(top==4)
        return 1;
    return 0;
}

int popi(int stki[5],int *top)
{
    int elem;
    elem=stki[*top];
    (*top)--;
    return elem;

}


void pushi(int stki[5],int *top,int elem)
{
    (*top)++;
    stki[*top]=elem;

}

void display(int stk[5],int top)
{
    int pos;
    printf("\nstack is\n");
    for(pos=top;pos>=0;pos--)
        printf("\n%7d\n",stk[pos]);
    printf("\ntop is %d",top);
}

int main()
{
    ///conversion
    char stack[10]= {'-','-','-','-','-','-','-','-','-','-'};
    char infix[15],postfix[15],ch,c;
    int top=-1,pos=0,i;
    printf("\nEnter infix expression:  ");
    gets(infix);
    for(i=0; (ch=infix[i])!='\0'; i++)
    {
        if(ch=='(')
            push(stack,&top,ch);
        else if(ch==')')
        {
            while(stack[top]!='(')
                postfix[pos++]=pop(stack,&top);
            pop(stack,&top);
        }
        else if(ch=='*'||ch=='/'||ch=='+'||ch=='-')
        {
            while(stack[top]=='*'||stack[top]=='/'||stack[top]=='-'||stack[top]=='+')
            {
                if(getpreced(stack[top])>=getpreced(ch))
                    postfix[pos++]=pop(stack,&top);
                else
                    break;

            }
            push(stack,&top,ch);
        }
        else
            postfix[pos++]=ch;

    }
    while(top>=0)
    {
        postfix[pos++]=stack[top];
        top=top-1;
    }
    postfix[pos]='\0';
    printf("\npostfix expression is:  ");
    puts(postfix);
    ///evaluation
    int stki[5],topi=-1,op1,op2,p;
    printf("the expression is %s \n",postfix);
    display(stki,topi);
    for(p=0;postfix[p]!='\0';p++)
    {
        char ch=postfix[p];
        printf("\nchar is %c\n",ch);
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        {
            op2=popi(stki,&topi);
            op1=popi(stki,&topi);
            if(ch=='+')
                pushi(stki,&topi,getvalue(op1)+getvalue(op2));
            if(ch=='-')
                pushi(stki,&topi,getvalue(op1)-getvalue(op2));
            if(ch=='*')
                pushi(stki,&topi,getvalue(op1)*getvalue(op2));
            if(ch=='/')
                pushi(stki,&topi,getvalue(op1)/getvalue(op2));
            display(stki,topi);
        }
        else
        {
            if(ch=='a'||ch=='b'||ch=='c'||ch=='d')
            {
                pushi(stki,&topi,getvalue(ch));
                display(stki,topi);
            }

        }
    }
    return 1;
}
