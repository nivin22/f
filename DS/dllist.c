#include<stdio.h>
#include<malloc.h>
struct node
{
    int num;
    struct node *next,*prev;
};
void displayfront(struct node *startptrptr)
{
    int content;
    printf("Contents of the linked list from front are:\n");
    while (startptrptr!=NULL)
    {
        content=startptrptr->num;
        printf("%4d ", content);
        startptrptr=startptrptr->next;
    }
}

void displayrev(struct node *endptrptr)
{
    printf("\nContents of the linked list from back are:\n");
    while (endptrptr!=NULL)
    {
        printf("%4d ",endptrptr->num);
        endptrptr=endptrptr->prev;
    }
}
struct node* addatbeg(struct node **startptrptr,struct node **endptrptr)
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int elem;
    printf("\nEnter the element to be inserted at beginning");
    scanf("%d",&elem);
    newnode->num=elem;
    newnode->next=*startptrptr;
    newnode->prev=NULL;
    if(*startptrptr!=NULL)
    {
        (*startptrptr)->prev=newnode;
    }
    (*startptrptr)=newnode;
    if(*endptrptr==NULL)
        *endptrptr=newnode;
}
struct node* addatend(struct node **startptrptr,struct node**endptrptr)
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int elem;
    printf("\nEnter the element to be inserted at end: ");
    scanf("%d",&elem);
    newnode->num=elem;
    newnode->next=NULL;
    newnode->prev=*endptrptr;
    if(*endptrptr!=NULL)
    {
        (*endptrptr)->next=newnode;
    }
    (*endptrptr)=newnode;
    if((*endptrptr)==NULL)
        (*startptrptr)=newnode;
}
struct node* addafter(struct node **startptrptr,struct node **endptrptr)
{
    struct node* nnodeptr;
    nnodeptr=(struct node*)malloc(sizeof(struct node));
    struct node *rider;
    rider=*startptrptr;
    int ele;
    printf("Enter the value of node after which number is to be added");
    scanf("%d",&ele);
    printf("\nEnter the element to be added: ");
    scanf("%d",&nnodeptr->num);
    while(rider!=NULL)
    {
        if(rider->num==ele && rider!=*endptrptr)
        {
            nnodeptr->next=rider->next;
            nnodeptr->prev=rider;
            nnodeptr->next->prev=nnodeptr;
            nnodeptr->prev->next=nnodeptr;
            if(nnodeptr->next==NULL)
                *endptrptr=nnodeptr;
            break;
        }
        rider=rider->next;
    }

}
void deleteend(struct node **startptrptr,struct node **endptrptr)
{
    struct node *temp=(*endptrptr);
    if((*endptrptr)==(*startptrptr))
    {
        (*startptrptr)=(*endptrptr)=NULL;
    }
    else
    {
        (*endptrptr)=(*endptrptr)->prev;
        (*endptrptr)->next=NULL;
    }
}
void deletefront(struct node **startptrptr,struct node **endptrptr)
{
    struct node *temp=(*startptrptr);
    if((*startptrptr)==(*endptrptr))
    {
        (*startptrptr)=(*endptrptr)=NULL;
    }
    else
    {
        (*startptrptr)=(*startptrptr)->next;
        (*startptrptr)->prev=NULL;
    }
}
void addbefore(struct node **startptrptr,struct node **endptrptr)
{
    struct node *nnodeptr=(struct node*)malloc(sizeof(struct node));
    int ele;
    printf("Before which element be added?");
    scanf("%d",&ele);
    printf("Enter the value to be Added");
    scanf("%d",&nnodeptr->num);

    struct node *rider=*startptrptr;

    if((*startptrptr)->num==ele)
    {
        nnodeptr->prev=NULL;
        nnodeptr->next=(*startptrptr);
        (*startptrptr)->prev=nnodeptr;
        (*startptrptr)=nnodeptr;
    }
    else
    {
        while(rider!=NULL)
        {
            if(rider->num==ele)
            {
                nnodeptr->prev=rider->prev;
                nnodeptr->next=rider;
                rider->prev=nnodeptr;
                nnodeptr->prev->next=nnodeptr;
            }
            rider=rider->next;
        }
    }

}
void main()
{
    struct node *start=NULL, *newnode, *end=NULL, *pos;
    newnode=(struct node*)malloc(sizeof(struct node));
    int c;
    for(;;)
    {
        printf("\n1.Add at beginning  \n2.Add at end   \n3.Delete from end \n4.Delete from Beginning\n5.Add after \n6.Add before \n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&c);
        if(c==1)
        {
            addatbeg(&start,&end);
            displayfront(start);
            displayrev(end);
        }
        if(c==2)
        {
            addatend(&start,&end);
            displayfront(start);
            displayrev(end);
        }
        if(c==3)
        {
            deleteend(&start,&end);
            displayfront(start);
            displayrev(end);

        }
        if(c==4)
        {
            deletefront(&start,&end);
            displayfront(start);
            displayrev(end);

        }
        if(c==5)
        {
            addafter(&start,&end);
            displayfront(start);
            displayrev(end);
        }
        if(c==6)
        {
            addbefore(&start,&end);
            displayfront(start);
            displayrev(end);
        }
        if(c==7)
        {
            break;
        }

    }
}
