#include<stdio.h>

int main(void)
{
    int a,b,c;
    printf("Enter 3 numbers:\n");
    scanf("%d %d %d", &a, &b, &c);
    int largest;
    if(a>b)
    {
        largest = a;
    }
    else
        largest = b;
    if(largest < c)
        largest = c;
    printf("The largest number is: %d\n", largest);
}