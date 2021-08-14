#include<stdio.h>

int main(void)
{
    int arr[20];
    printf("Input 20 whole numbers:\n");
    for(int i=0;i<20;i++)
    {
        scanf("%d",&arr[i]);
    }
    int num=0;
    for(int i=0;i<20;i++)
    {
        if(arr[i]%2==0)
            num=num+1;
    }
    printf("Number of even numbers in the array: %d\n", num);
}

