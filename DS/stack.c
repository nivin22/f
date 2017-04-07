#include<stdio.h>
int isnull(int top)
{
    if(top>=0)
    {
        return 1;
    }
    else
    {
        printf("Stack is empty\n");
        return 0;
    }
}
int pop(int *top,int stk[])
{
    int el=stk[*top];
    (*top)--;
    return(el);
}
int push(int *top,int stk[])
{
    ++(*top);
    printf("Enter the element at top ");
    scanf("%d",&stk[*top]);
    return stk[*top];
}
int isfull(int top)
{
    if(top<3)
    {
        return 1;
    }
    else
    {
        printf("Stack is full");
        return 0;
    }
}
int display(int *top,int stk[4])
{
    int p;
    printf("\n the stack is:\n");
    printf("\n top value:\n");
    for(p=4;p>=0;p--)
    {
        if(p==top)
            printf("\n %4d %4d",top,stk[p]);
        else
            printf("\n %4d",stk[p]);
    }
    if(top==-1)
        printf("\n %4d",top);

}
void main()
{
    int top=-1,stk[4],cdn,c,i,el;
    printf("The junk values are\n");
    display(&top,stk);
    for(;;)
    {
        printf("\nSelect one \n1.push \n2.pop ");
        scanf(" %d",&c);
        if(c==1)
        {
            cdn=isfull(top);
            if(cdn==1)
            {
                el=push(&top,stk);
                printf("The element at top is: %d\n",el);
            }
            display(&top,stk);
        }
        else if(c==2)
        {
            cdn=isnull(top);
            if(cdn==1)
            {
                el=pop(&top,stk);
                printf("the element popped is: %d \n",el);
            }
            display(&top,stk);
        }
        else
        {
            i=1;
        }
    }
}
