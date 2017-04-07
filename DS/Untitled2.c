#include<stdio.h>
#include<malloc.h>
struct node
{
    int num;
    struct node *lchild;
    struct node *rchild;
};
void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->lchild);
    printf("%5d",root->num);
    inorder(root->rchild);
}
struct node* add(struct node **rootptr)
{
    struct node *nnodeptr;
    int val;
    nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the number to beaddedatbeginning");
    scanf("%d",&val);
    nnodeptr->num=val;
    nnodeptr->lchild=NULL;
    nnodeptr->rchild=NULL;
    *rootptr=nnodeptr;
}
void main()
{
    struct node *root=NULL,*nnodeptr;
    nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("The traversal is");
    inorder(root);
    addatbeg(&root);
    inorder(root);
}
