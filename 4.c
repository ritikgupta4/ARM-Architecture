#include<stdio.h>

int main(void)
{
    int arr[20];
    printf("Enter 20 numbers in the array: \n");
    for(int i=0;i<20;i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<19;i++)
    {
        int t=0;
        for(int j=0;j<20-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=t;
            }
        }
    }
    printf("Array in sorted order:\n");
    for(int i=0;i<20;i++)
        printf("%d ", arr[i]);
}