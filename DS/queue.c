#include<stdio.h>
void display(int q[4],int front,int back)
{
    int pos;
    printf("The value of front is %4d\n",front);
    printf("The value of back is %4d\n",back);
    printf("The queue is:\n");

    for(pos=0;pos<4;pos++)
    {
        printf("%8d",q[pos]);
    }
    printf("\n");

}
void push(int q[4],int *front,int *back)
{
    int ele,i;
    {
        if(*front==-1 && *back ==-1)
        {
          ++(*front);
          ++(*back);
          printf("Enter the element: \n");
          scanf("%d",&ele);
          q[*back]=ele;
        }
        else
        {
            for(i=0;i<4;i++)
            {
                display(q,*front,*back);
                ++(*back);
                printf("Enter the element: \n");
                scanf("%d",&ele);
                q[*back]=ele;
            }
            printf("The queue is full\n");


        }

    }


}
void pop(int q[4],int *front,int *back)
{
    int i;
    if(*front==4)
    {
        printf("queue is empty\n");
    }
    else
    {
        {
            printf("The element removed is %d\n",q[*front]);
            (*front)++;
            display(q,*front,*back);
        }


    }
}
void main()
{
    int q[4],c,ch,front=-1,back=-1;
    display(q,front,back);
    for(;;)
    {
        printf("1.Add\n2.Delete\n");
        scanf("%d",&c);
        if(c==1)
        {
            push(q,&front,&back);
        }
        else if(c==2)
        {
            pop(q,&front,&back);
        }
        else
            printf("Invalid entry enter 1/2");
    }


}
