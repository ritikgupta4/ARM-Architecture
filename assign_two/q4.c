//Empty ascending stack->pointer at arr[1](element present at arr[0]). Pointer points to the next free location

#include<stdio.h>
#include<stdlib.h>
struct Stack
{
    int sp;
    int size;
    int arr[10];
};
int Pop(struct Stack*);
void Push(struct Stack* ,int data);
void print(struct Stack*);

int main(void)
{
    struct Stack* stack =  (struct Stack*)malloc(sizeof(struct Stack));
    stack->size=10;
    stack->sp=1;
    for(int i=0;i<stack->size;i++)
    {
        stack->arr[i]=i;
    }
   int t=1;
    while(t)
    {
        int n;
        printf("1 - Push \n2 - Pop \n3 - Print the stack\n4 - Exit\nEnter a number:");
        scanf("%d",&n);
        if(n==1)
        {
            int element;
            printf("Enter element:");
            scanf("%d",&element);
            Push(stack,element);
        }
        else if(n==2)
        {
            int element = Pop(stack);
        }
        else if(n==3)
        {
            print(stack);
        }
        else if(n==4)
        {
            printf("Exiting\n");
            t=0;
            break;
        }
        else{
            printf("Wrong input. Try again\n");
        }
    }
}
int Pop(struct Stack* stack)
{
    if(stack->sp==0)
    {
        printf("Stack is empty\n");
    }
    else
    {
        int element = stack->arr[stack->sp-1];
        printf("Element at pointer: %d\n", element);
        stack->sp=stack->sp-1;
    }
}
void Push(struct Stack* stack, int data)
{
    if(stack->sp==stack->size)
    {
        printf("Stack is already full\n");
    }
    else
    {
        stack->sp=stack->sp+1;
        stack->arr[stack->sp-1] = data;
    }
}
void print(struct Stack* stack)
{
    if(stack->sp==-1)
    {
        printf("Stack is empty. No elements cant be printed\n");
        exit(0);
    }
    printf("Printing elements from bottom to top:\n");
    for(int i=0;i<=stack->sp-1;i++)
    {
        printf("%d\n",stack->arr[i]);
    }
}