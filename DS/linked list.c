#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int num,*next;
};

// Add at Beginning
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
void display(struct node *start)
{
    printf("The list is");
    while(start!=NULL)
    {
        printf("%d",start->num);
        start=start->next;
    }
}
/*
struct node *addend(node *end)// Add at End
{
    node *nnodeptr;
    int elem;
    printf("Enter a value");
    scanf("d",&elem);
    nnodeptr->num=elem;
    nnodeptr->next=NULL;
    end->next=nnodeptr;
    end=nnodeptr;
    return (end);
}
struct node *delbeg(struct node **start,struct node **end)
{
    struct node *temp;
    temp=start;
    if(*start==*end)
    {
        *end=NULL;
    }
    *start=*start->next;
    free(temp);

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
*/
void main()//            Main Function
{
    int elem;
    struct node *start,*end,*nnodeptr;
    nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter a Value");
    scanf("%d",&elem);
    nnodeptr->num=elem;
    nnodeptr->next=NULL;
    start=nnodeptr;
    start=addatbeg(start,end);
    display(start);



}
