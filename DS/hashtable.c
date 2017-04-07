#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
    int num;
    struct node *next;
};
void traverse(struct node *htable[])
{
    int p;
    struct node *racer;
    printf("\nThe table is: \n");//vertical movement
    for(p=0; p<5; p++)
    {
        racer=htable[p];
        printf("\n %5d",p);
        while(racer!=NULL)//horizontal movement
        {
            printf("%5d",racer->num);
            racer=racer->next;
        }
    }
}
void search(struct node *htable[],int elem)
{
    struct node *racer;
    int count=0,p=elem%5;
    racer=htable[p];
    while(racer!=NULL)
    {
        count++;
        if(racer->num==elem)
        {
            printf("\nthe elem found at pos %d and count %d",p,count);
            return;
        }
        racer=racer->next;
    }
    printf("\nelement not found\n");
}
int findpos(int elem)
{
    int num,index;
    index=elem%5;
    return index;
}
void addelem(struct node *htable[])
{
    int elem,pos;
    struct node *nnode=(struct node*)malloc(sizeof(struct node));
    nnode->next=NULL;
    printf("\nenter the elem to be added\n");
    scanf("%d",&elem);
    nnode->num=elem;
    pos=findpos(elem);
    if(htable[pos]==NULL)   //when no element present
        htable[pos]=nnode;
    else                 //general case
    {
        nnode->next=htable[pos];
        htable[pos]=nnode;
    }

}
void main()
{
    struct node *htable[5]= {NULL};
    int ch,chtable;
    traverse(htable);
    while(1)
    {
        printf("\nEnter ur choice\n1)Add elem\n2) search table\n");
        scanf("%d",&ch);
        if(ch==1)
            addelem(htable);
            traverse(htable);
        if(ch==2)
        {
            int find;
            printf("\nenter the element to be found\n");
            scanf("%d",&find);
            search(htable,find);
            traverse(htable);
        }


    }
}
