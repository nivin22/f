#include<stdio.h>
void insertheap(int *heap, int *pos)
{
    int temp, ch, elem;
    ch = (*pos);
    printf("\nEnter the element to be added:\t");
    scanf("%d",&elem);
    heap[*pos] = elem;
    (*pos)++;

    while (ch/2 != 0)
    {
        if (heap[ch] > heap[ch/2])
        {
            temp = heap[ch];
            heap[ch] = heap[ch/2];
            heap[ch/2] = temp;
        }
        ch = ch/2;
    }
}
void displayheap(int *heap, int pos)
{
    int r;
    printf("\nThe heap is: \n");
    for (r=1; r<pos; r++)
        printf("%5d",heap[r]);
}
void deleteheap(int *heap, int *pos)
{
    int ch=1, temp;
    (*pos)--;
    heap[1]= heap[*pos];
    while (2*ch+1 <= (*pos))
    {
        if (heap[2*ch+1] < heap[2*ch])
        {
            if (heap[ch] < heap[2*ch])
            {
                temp = heap[2*ch];
                heap[2*ch] = heap [ch];
                heap[ch] = temp;
                ch = 2*ch;
            }
            else
                break;
        }
        else if (heap[ch] < heap [2*ch+1])
        {
            temp = heap[2*ch+1];
            heap[2*ch+1] = heap [ch];
            heap[ch] = temp;
            ch = 2*ch+1;
        }
        else
            break;
    }

    if (2*ch == (*pos) && heap[ch] < heap[2*ch])
    {
        temp = heap[2*ch];
        heap[2*ch] = heap [ch];
        heap[ch] = temp;
    }
}

void main()
{

    int heap[7], pos =1,p;
    for (p=0; p<6; p++)
        insertheap(heap, &pos);
    displayheap(heap,pos--);
    printf("\nThe deletion process: \n");
    for (p=0; p<6; p++)
    {
        displayheap(heap,pos);
        deleteheap(heap,&pos);
    }
}
