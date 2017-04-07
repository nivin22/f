#include<stdio.h>
void main()
{
    int a[100],i,s,l,ele,sl,sum=0,a1,j,e,pos,n;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("The array is ");
    for(i=0;i<n;i++)
        printf("%4d",a[i]);
    s=a[0];
    l=a[0];
     for(i=0;i<n;i++)
    {
        if(a[i]<s)
            s=a[i];
    }
    printf("\n");
    printf("The smallest is %d",s);
    printf("\n");
    for(i=0;i<n;i++)
    {

        if(a[i]>l)
            l=a[i];
    }
    printf("The largest number is %d",l);
    printf("\n");
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    printf("The sum of elements is %d ",sum);
    printf("\n");
    printf("Enter the search element");
    scanf("%d",&ele);
    a1=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==ele)
        {
            a1=1;
            j=i+1;
            if(a1==1)
            printf("%d found in position %d",ele,j);
            printf("\n");
        }
    }

        if(a1==0)
            printf("%d not found",ele);
    printf("Enter the position");
    scanf("%d",&pos);
    printf("Enter the element");
    scanf("%d",&e);
    for(i=pos-1;i<n+1;i++)
    {
        a[pos-1]=e;
        a[pos]=a[pos+1];



    }
    for(i=0;i<n+1;i++)
    printf("%4d",a[i]);




}
