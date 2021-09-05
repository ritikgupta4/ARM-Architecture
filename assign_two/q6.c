//Circular queue
#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int front, rear;
    int arr[10];
    int size;
};
void add_to_queue(struct Queue*, int data);
int remove_from_Queue(struct Queue*);
void print(struct Queue*);
int main(void)
{
    struct Queue* qu =  (struct Queue*)malloc(sizeof(struct Queue));
    qu->size=10;
    qu->front=-1;
    qu->rear = -1;
    for(int i=0;i<qu->size;i++)
    {
        qu->arr[i]=0;
    }
   int t=1;
    while(t)
    {
        int n;
        printf("1 - Enqueue \n2 - Dequeue \n3 - Print the queue\n4 - Exit\nEnter a number:");
        scanf("%d",&n);
        if(n==1)
        {
            int element;
            printf("Enter element:");
            scanf("%d",&element);
            add_to_queue(qu,element);
        }
        else if(n==2)
        {
            int element = remove_from_Queue(qu);
        }
        else if(n==3)
        {
            print(qu);
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
void add_to_queue(struct Queue* qu, int data)
{
    if((qu->front == 0 && qu->rear == qu->size-1)||qu->rear == (qu->front-1)%(qu->size-1))
    {
        printf("Cannot add element. Queue is full\n");
        return;
    }
    if(qu->front==-1 && qu->rear==-1)
    {
        qu->front = 0;
        qu->rear = 0;
        qu->arr[qu->rear] = data;
        return;
    }
    if(qu->rear == qu->size-1 && qu->front!=0)
    {
        qu->rear = 0;
        qu->arr[qu->rear]=data;
        return;
    }
    qu->rear+=1;
    qu->arr[qu->rear] = data;
}
int remove_from_Queue(struct Queue* qu)
{
    if(qu->front==-1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int element = qu->arr[qu->front];
    if(qu->front == qu->rear)
    {
        qu->front = -1;
        qu->rear = -1;
    }
    else if(qu->front==qu->size-1)
    {
        qu->front = 0;
    }
    else
        qu->front+=1;
    return element;
}
void print(struct Queue* qu)
{
    if(qu->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    if(qu->front<=qu->rear)
    {
        for(int i=qu->front;i<=qu->rear;i++)
        {
            printf("%d\n",qu->arr[i]);
        }
    }
    else
    {
        for(int i = qu->front;i<qu->size;i++)
        {
            printf("%d\n", qu->arr[i]);
        }
        for(int i=0;i<=qu->rear;i++)
        {
            printf("%d\n", qu->arr[i]);
        }
    }
}