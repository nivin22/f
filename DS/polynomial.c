#include<stdio.h>
#include<malloc.h>
struct node
{
    int coeff;
    int power;
    struct node *next;
};
void addatend(struct node **startptr,struct node **endptr, int coeff, int power)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->power=power;
    newnode->next=NULL;
    if(*startptr==NULL)
    {
        *startptr=*endptr=newnode;
    }

    else
    {
        (*endptr)->next=newnode;
        *endptr=newnode;
    }
}
void display(struct node *firstart)
{
    while(firstart!=NULL)
    {
        if(firstart->power==0)
        {
            printf("%d",firstart->coeff);
        }
        else if(firstart->power==1)
        {
            printf("%dx",firstart->coeff);
        }
        else
        {
             printf(" %dx%d+",firstart->coeff,firstart->power);
        }
        firstart=firstart->next;
    }
}
void addpolynomial(struct node *firstart,struct node *sstart,struct node **newstart,struct node **newend)
{

    struct node *newnode,*first,*second;
    first=firstart;
    second=sstart;
    while(firstart!=NULL && sstart!=NULL)
    {

            if(firstart->power==sstart->power)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                newnode->coeff=firstart->coeff+sstart->coeff;
                newnode->power=firstart->power;
                if(*newstart==NULL)
                {
                    (*newstart)=(*newend)=newnode;
                    newnode->next=NULL;
                }
                else
                {
                    (*newend)->next=newnode;
                    *newend=newnode;
                     newnode->next=NULL;
                }
                sstart=sstart->next;
                firstart=firstart->next;
            }
            else if(firstart->power>sstart->power)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                newnode->coeff=firstart->coeff;
                newnode->power=firstart->power;
                if(*newstart==NULL)
                {
                    (*newstart)=(*newend)=newnode;
                    newnode->next=NULL;
                }
                else
                {
                    (*newend)->next=newnode;
                    *newend=newnode;
                     newnode->next=NULL;
                }
              firstart=firstart->next;
            }

            else if (firstart->power<sstart->power)
            {
                newnode=(struct node*)malloc(sizeof(struct node));
                newnode->coeff=sstart->coeff;
                newnode->power=sstart->power;
                if(*newstart==NULL)
                {
                    (*newstart)=(*newend)=newnode;
                    newnode->next=NULL;
                }
                else
                {
                    (*newend)->next=newnode;
                    *newend=newnode;
                     newnode->next=NULL;
                }
                sstart=sstart->next;
            }
    }
    if(firstart==NULL && sstart!=NULL)
    {
        while(sstart!=NULL)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->coeff=sstart->coeff;
            newnode->power=sstart->power;
            if(*newstart==NULL)
                {
                    (*newstart)=(*newend)=newnode;
                    newnode->next=NULL;
                }
                else
                {
                    (*newend)->next=newnode;
                    *newend=newnode;
                     newnode->next=NULL;
                }
            sstart=sstart->next;
        }
    }
    if(firstart!=NULL && sstart==NULL)
    {
        while(firstart!=NULL)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->coeff=firstart->coeff;
            newnode->power=firstart->power;
            if(*newstart==NULL)
                {
                    (*newstart)=(*newend)=newnode;
                    newnode->next=NULL;
                }
                else
                {
                    (*newend)->next=newnode;
                    *newend=newnode;
                     newnode->next=NULL;
                }
            firstart=firstart->next;
        }
    }
}
void main()
{
    struct node *firstart=NULL,*firstend=NULL,*sstart=NULL,*send=NULL;
    struct node *newstart=NULL,*newend=NULL;
    //3x4+5x2
    //3x4+5x2+6
    //addatend(&firstart,&firstend,6,5);
    addatend(&firstart,&firstend,3,4);
    //addatend(&firstart,&firstend,3,3);
    addatend(&firstart,&firstend,5,2);
    addatend(&firstart,&firstend,5,1);
    //addatend(&firstart,&firstend,6,0);
    printf("\n\nThe first polynomial is:\n");
    display(firstart);
    printf("\n\nThe second polynomial is:\n ");
    addatend(&sstart,&send,3,4);
    addatend(&sstart,&send,5,2);
    addatend(&sstart,&send,6,0);
    display(sstart);
    addpolynomial(firstart,sstart,&newstart,&newend);
    printf("\n\nThe new polynomial is:\n");
    display(newstart);
    printf("\n");
}
