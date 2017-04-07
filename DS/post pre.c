#include<stdio.h>
char process(char pre[])
{
    int exp,top=-1;
    char tempc[200];
    char tempo[200];
    for(exp=0;pre[exp]!='\0';exp++)
    {
        if(pre[exp]=='a'||pre[exp]=='b'||pre[exp]=='b'||pre[exp]==')'||pre[exp]=='(')
        {
            push(tempc);
        }
        else if(pre[exp]=='*'||pre[exp]=='/'||pre[exp]=='+'||pre[exp]=='-')
        {
            push(tempo);
        }
    }
}
void push(int *top,int stk[],char elem)
{
    ++(*top);
    stk[*top]=elem;
    // return stk[*top];
}

int pop(int *top,int stk[])
{
    *top=*top-1;
    return stk[*top+1];

}



void display(int top,int stk[])
{
    int c;
    for(c=3; c>=0; c--)
    {
        printf("%d   %d",c,stk[c]);
        if(c==top)
        {
            printf("    %d is the top\n",top);
        }
        else
        {
            printf("\n");
        }
    }
}

void main()
{
    int i,top=-1,val;
    int var[20];
    char post[200],pre[200,]ch;
    printf("\nenter the expression\n");
    scanf("%s",&pre);
    post=process(pre);
    for(i=0; post[i]!='\0'; i++)
    {
        display(top,var);
        printf("\n");
        ch=post[i];
        if(ch=='a'|| ch=='b'|| ch=='c')
        {
            printf("enter the value of%c",ch);
            scanf("%d",&val);
            push(&top,var,val);

        }
        if(ch=='*'||ch=='+'||ch=='/'||ch=='-')
        {
            int a,b,d;
            b=pop(&top,var);
            a=pop(&top,var);
            if(ch=='+')
            {
                d=a+b;
                printf("sum of %d and %dis %d",a,b,d);
            }
            else if(ch=='*')
            {
                d=a*b;
                printf("product of %d and %d is%d",a,b,d);
            }
            else if(ch=='/')
            {
                if(b!=0)
                {
                d=a/b;
                printf("quotient of %d and %d is%d",a,b,d);
                }
                else
                {
                    printf("0 divsion error");
                    break;
                }
            }
            else if(ch=='-')
            {
                d=a-b;
                printf("difference of %d and %d is%d",a,b,d);
            }
            push(&top,var,d);
            printf("\n%d%c%d=%d\n",a,ch,b,d);
            getch();
        }
    }
    display(top,var);
    printf("\n\nthe value of the exprrsson is%d\n\n",var[top]);
}
