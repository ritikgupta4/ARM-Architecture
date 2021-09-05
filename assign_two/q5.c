//Simple queue
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
    if(qu->rear == qu->size)
    {
        printf("Cannot add element. Queue is full\n");
        return;
    }
    if(qu->front==-1 && qu->rear==-1)
    {
        qu->front = 0;
        qu->rear = 0;
    }
    qu->arr[qu->rear] = data;
    qu->rear+=1;
}
int remove_from_Queue(struct Queue* qu)
{
    if(qu->front>=qu->rear || qu->front==-1)
    {
        printf("Queue is empty\n");
    }
    int element = qu->arr[qu->front];
    for(int i=qu->front;i<qu->rear-1;i++)
    {
        qu->arr[i] = qu->arr[i+1];
    }
    qu->rear-=1;
}
void print(struct Queue* qu)
{
    if(qu->front==qu->rear)
    {
        printf("Queue is empty\n");
        exit(0);
    }
    for(int i=qu->front;i<qu->rear;i++)
    {
        printf("%d\n",qu->arr[i]);
    }
}