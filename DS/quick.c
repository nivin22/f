#include<stdio.h>
void print(int *arr)
{
    int p;
    printf("\nThe array is  \n");
    for (p=0; p<7; p++)
        printf("%5d",arr[p]);
}
void swap(int *arr, int l, int r)
{
    int temp;
    temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}
void findpos(int *arr, int left, int right)
{
    int pivot = arr[left],l,r;
    l = left;
    r = right;
    while (l<r)
    {
        while (arr[r]>pivot)
            r--;
        swap(arr,l,r);

        print(arr);
        while (arr[l] < pivot)
            l++;
        swap(arr,l,r);
    }

    if (l-left >1 )
        findpos(arr,left,l-1);
    if (right -r >1)
        findpos(arr,r+1, right);

}

void main()
{
    int arr[7] = {3,14,27,37,32,22,10};
    printf("\nBefore locating:\t\n");
    print(arr);
    findpos(arr,0,6);
}
