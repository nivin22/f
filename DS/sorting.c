#include<stdio.h>
void main()
{
    int a[5]={21,88,44,12,1},p,pos,temp,pass,swapcount;
    printf("The original array is:");
    for(p=0;p<5;p++)
    {
        printf("%4d",a[p]);
    }
    for(pass=0;pass<5;pass++)
    {

    for(p=0;p<5-1;p++)
        {
            if(a[p+1]<a[p])
            {
                temp=a[p];
                a[p]=a[p+1];
                a[p+1]=temp;

            }
        }
    }
    printf("\nThe array is:\n");
    for(p=0;p<5;p++)
        printf("%5d",a[p]);
}
