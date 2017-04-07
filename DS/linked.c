#include <stdio.h>
struct node
{
    int num;
    struct node *next;
};

void display(struct node *start)
{
    int content;
    printf("Contents of the linked list is\n");
    while (start!=NULL)
    {
        content=start->num;
        printf("%4d", content);
        start=start->next;
    }
}

struct node* addatbeg(struct node *start)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node*));
    int elem;
    printf("\nEnter element to insert to beg of linked list\n");
    scanf("%d", &elem);
    newnode->num=elem;
    newnode->next=start;
    start=newnode;
    return (start);


}

struct node* addatend(struct node *end)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node*));
    int elem;
    printf("\nEnter element to insert to end of linked list\n");
    scanf("%d", &elem);
    newnode->num=elem;
    newnode->next=NULL;
    end->next=newnode;
    end=newnode;
    return (end);
}

struct node* findpos(struct node *rider, int elem)
{
    while (rider->num!=elem)
    {
        rider=rider->next;
    }
    return (rider);
}

int isthere(struct node *rider, int elem)
{
    int flag=0;
    while (rider!=NULL)
    {
        if (rider->num==elem)
            flag=1;
        rider=rider->next;
    }

    if (flag==1)
        return 1;
    else
        return 0;
}

struct node* delatbeg(struct node *start)
{
   int elem;
   elem=start->num;
   printf("\nDeleted element is %d", elem);
   start=start->next;
   return(start);
}

struct node* delatend(struct node *start)
{
   int elem;
   while (start->next->next!=NULL)
   {
       start=start->next;
   }
   elem=start->num;
   printf("\nDeleted element is %d", elem);
   start->next=NULL;
   return(start);
}

struct node* insertafter(struct node *start, int el)
{
    int data;
    printf("Enter num");
    while (start->num!=el)
    {
        start=start->next;
    }
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("\nEnter element to insert to linked list\n");
    scanf("%d", &data);
    newnode->num=data;
    newnode->next=start->next;
    start->next=newnode;
}

struct node* insertbefore(struct node *start, int el)
{
    int data;
    printf("Enter num");
    while (start->next->num!=el)
    {
        start=start->next;
    }
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("\nEnter element to insert to linked list\n");
    scanf("%d", &data);
    newnode->num=data;
    newnode->next=start->next;
    start->next=newnode;
}

struct node* del(struct node *start, int el)
{
    while (start->next->num!=el)
    {
        start=start->next;
    }
    int temp;
    temp=start->num;
    printf("Deleted element is %d", temp);
    start->next=start->next->next;
}

void main()
{
    struct node *start=NULL, *newnode, *end=NULL, *pos;
    display(start);
    //Initialising first node
    newnode=(struct node*)malloc(sizeof(struct node*));
    int elem, ch;

    display(start);

    for(;;)
    {
        printf("\nSelect an option\n");
        printf("1) Add to beginnig \n2) Add to end \n3) Display \n4) Find Position \n5) Delete from start \n6) Delete from end \n7) Insert after \n8) Insert before \n9) Delete node \n10)Exit\n");
        scanf("%d", &ch);

        if (ch==1)
        {
            start=addatbeg(start);
            display(start);
        }

        else if (ch==2)
        {
            end=addatend(end);
            display(start);
        }

        else if (ch==3)
        {

            display(start);
        }

        else if (ch==4)
        {
            int val, check1;
            printf("Enter element to search\n");
            scanf("%d", &check1);
            val=isthere(start, check1);
            printf("%d \n", val);
            display(start);
            if (val==1)
            {
                pos=findpos(start, check1);
                printf("\nPosition: %u", pos);
            }


            else
                printf("\nElement not found\n");
        }

        else if (ch==5)
        {
            start=delatbeg(start);
            display(start);
        }

        else if (ch==6)
        {
            end=delatend(start);
            display(start);
        }

        else if (ch==7)
        {
            int el;
            printf("Which element must the node be entered before\n");
            scanf("%d", &el);
            if (isthere(start, el)==1)
            {
                insertafter(start, el);
                display(start);
            }
            else
                printf("Element not found");

        }

        else if (ch==8)
        {
            int el;
            printf("Which element must the node be entered after\n");
            scanf("%d", &el);
            if (isthere(start, el)==1)
            {
                insertbefore(start, el);
                display(start);
            }
            else
                printf("Element not found");

        }

        else if (ch==9)
        {
            int el;
            printf("Which node must be deleted? \n");
            scanf("%d", &el);
            if (isthere(start, el)==1)
            {
                del(start, el);
                display(start);
            }
            else
                printf("Element not found");

        }
        else
            exit(0);
    }

}
