#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node*next;

};
void display(struct node *start)
{
    printf("The list is: \n");
    while(start!=NULL)
    {
        printf("%5d",start->num);
        start=start->next;
    }
}
struct node* addatend(struct node* start,struct node* end)
{
    int elem;
    struct node* nodeptr;
    nodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter a value to add at end");
    scanf("%d",&elem);
    nodeptr->num=elem;
    nodeptr->next=NULL;
    if(start==NULL)
    {
        start=nodeptr;
        end=nodeptr;
    }
    else
    {
        end->next=nodeptr;
    }
    return(end);
};
struct node* addatbeg(struct node*start,struct node*end)
{
    struct node *nnodeptr;
    int elem;
    nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value at beginning");
    scanf("%d",&elem);
    nnodeptr->num=elem;
    nnodeptr->next=NULL;
    if(start==NULL)
    {
        start=nnodeptr;
        end=nnodeptr;
    }
    else
    {
        nnodeptr->next=start;
        start=nnodeptr;
    }
    return(start);
}
struct node* deletebeg(struct node* start)
{
    struct node *temp=start;
    start=start->next;
    free(temp);
    return(start);
}
struct node* deletend(struct node *start)
{
    struct node*temp;
    while(start->next->next!=NULL)
    {
        start=start->next;
        temp=start->next;
        free(temp);
        start->next=NULL;
        return(start);
    }
};
void main()
{
    int elem,c;
    struct node *start=NULL,*end=NULL,*nnodeptr;
    nnodeptr=(struct node*)malloc(sizeof(struct node));
    display(start);
    end=addatend(start,end);
    display(start);
    start=deletebeg(start);
    display(start);
    start=deletend(start);
    display(start);



}
