
#include <stdio.h>
#include <malloc.h>

struct node
{
    struct node *lchild;
    int num;
    struct node *rchild;
};
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->lchild);
        printf("%5d",root->num);
        inorder(root->rchild);
    }
}

void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        printf("%5d",root->num);
        preorder(root->lchild);
        preorder(root->rchild);
    }

}
void postorder(struct node *root)
{
    if(root==NULL)
        return;
    else
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%5d",root->num);
    }
}

void addnode(struct node *root)
{
    int val;
    struct node *rider,*parent;
    printf("\nEnter the value to be added:\n");
    scanf("%d",&val);
//To create a node
    struct node *treeptr=(struct node *)malloc(sizeof(struct node));
    treeptr->num=val;
    treeptr->lchild=treeptr->rchild=NULL;

    rider=root;
    parent=NULL;
    while(rider!=NULL)
    {
        parent=rider;
        if(val<rider->num)
                    rider=rider->lchild;
        else
                    rider=rider->rchild;
    }
    if(val<parent->num)
    {
        parent->lchild=treeptr;
    }
    else
    {
        parent->rchild=treeptr;
    }

}



 struct node* findparentchild(struct node *root,int val,struct node **parentptr,struct node **childptr)
{
    struct node *parent=root;
    struct node *child;

    if(val<parent->num)
        child=parent->lchild;
    else
        child=parent->rchild;

    while(child->num!=val && child!=NULL)
    {
        printf("now parent is:  %d",parent->num);
        if(val<child->num)
        {
            parent=child;
            child=child->lchild;
        }
        else if(val>child->num)
        {
            parent=child;
            child=child->rchild;
        }
}
    printf("The parent is :%d and the child is %d",parent->num,child->num);
    (*parentptr)=parent;
    (*childptr)=child;


}

void deletenodezerochild(struct node *parent,struct node *child)
{


    if(child->rchild==NULL && child->lchild==NULL)
    {
        if(child->num<parent->num)
                parent->lchild=NULL;
        else
                parent->rchild=NULL;

    }
}

void deletenodeonechild(struct node *parent,struct node *child)
{
    struct node *gchild;


        if(child->lchild==NULL)
                gchild=child->rchild;
        else
                gchild=child->lchild;

        if(parent->lchild==child)
                        parent->lchild=gchild;
        else
                        parent->rchild=gchild;

        free(child);

}

void deletenodetwochild(struct node *parent,struct node *child)
{


    struct node *succ, *succpar;
    int temp;
    succ=child->rchild;
    succpar=child;
    while(succ->lchild!=NULL)
    {   succpar=succ;
        succ=succ->lchild;
    }
    temp=succ->num;
    if(succ->rchild!=NULL)
        deletenodeonechild(succpar,succ);
    else
        deletenodezerochild(succpar,succ);

    child->num=temp;
}


void main()
{
    struct node *root=NULL,*parent=NULL, *child=NULL;
    struct node *treeptr=(struct node *)malloc(sizeof(struct node));
    int opt,val;
    treeptr->num=10;
    treeptr->lchild=NULL;
    treeptr->rchild=NULL;
    root=treeptr;

    //struct node *treeptr1=(struct node *)malloc(sizeof(struct node));
    //treeptr1->num=100;
    //treeptr1->lchild=NULL;
    //treeptr1->rchild=NULL;
    //root->rchild=treeptr1;

    printf("The inorder traversal is:\n");
    inorder(root);      //to carry out the inorder traversal
    printf("\nThe preorder traversal is:\n");
    preorder(root);     //to carry out the preorder traversal
    printf("\nThe postorder traversal is:\n");
    postorder(root);     //to carry out the postorder traversal

    for(;;)
    {
        printf("\nEnter your option:\n1.Add a node\n2.Delete the node\n3.Exit\n");
        scanf("%d",&opt);
        if(opt==1)
        {
            addnode(root);
            printf("\nThe inorder traversal is:");
            inorder(root);
            printf("\nThe preorder traversal is:\n");
            preorder(root);
            printf("\nThe postorder traversal is:");
            postorder(root);
        }
        else if(opt==2)
        {

            printf("\nEnter the node to be deleted:");
            scanf("%d",&val);
            findparentchild(root,val,&parent,&child);
            printf("The parent is %d and \n the child is %d",parent->num,child->num);
            if(child->lchild==NULL && child->rchild==NULL)
            {
                deletenodezerochild(parent,child);
                printf("\nThe inorder traversal is:\n");
                inorder(root);
                printf("\nThe preorder traversal is:\n");
                preorder(root);
                printf("\nThe postorder traversal is:\n");
                postorder(root);
            }
            else if((child->lchild!=NULL && child->rchild==NULL)||(child->rchild!=NULL && child->lchild==NULL))
            {
                deletenodeonechild(parent,child);
                printf("\nThe inorder traversal is:\n");
                inorder(root);
                printf("\nThe preorder traversal is:\n");
                preorder(root);
                printf("\nThe postorder traversal is:\n");
                postorder(root);
            }
            else
            {
                deletenodetwochild(parent,child);
                printf("\nThe inorder traversal is:\n");
                inorder(root);
                printf("\nThe preorder traversal is:\n");
                preorder(root);
                printf("\nThe postorder traversal is:\n");
                postorder(root);
            }

        }
        else
        {
            break;
        }

    }

}
