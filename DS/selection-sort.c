#include<stdio.h>
void main()
{
    int a[5]={76,56,24,54,1},pos,temp,small;
    printf("The original array Is:\n ");
    for(pos=0;pos<5;pos++)
        printf("%4d",a[pos]);
    for(pos=0;pos<5;pos++)
    {
        small=a[0];
        if(a[pos]<small)
        {
            temp=small;
            a[0]=a[pos];
            a[pos]=temp;
        }

    }
    printf("The new array is: \n");
    for(pos=0;pos<5;pos++)
        printf("%4d",a[pos]);
}
