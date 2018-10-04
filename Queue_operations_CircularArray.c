#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

void enqueue();
void dequeue();
void print();

struct queue_array
{
    int circular_array[MAX_SIZE];
    int front;
    int rear;
};

struct queue_array queue_a;

void enqueue()
{
    int rear_index = (queue_a.rear + 1) % MAX_SIZE, enqueue_element = 0;
    if( rear_index == queue_a.front )
    {
        printf("\nArray full!!\n");
        return;
    }
    printf("\nEnter element to enqueue :\n");
    scanf("%d",&enqueue_element);
    queue_a.circular_array[rear_index] = enqueue_element;
    queue_a.rear = rear_index;
    if(queue_a.front == -1) queue_a.front = rear_index;
}

void dequeue()
{

    if(queue_a.front == -1)
    {
        printf("\nQueue empty!!\n");
        return;
    }
    if(queue_a.front == 0 && queue_a.rear == 0)
    {
        queue_a.front = -1;
        queue_a.rear = -1;
    }
    else queue_a.front++;
}

void print()
{
    if(queue_a.front == -1)
    {
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nQueue is :\n");
    for(int i = queue_a.front; i <=queue_a.rear; i++)
        printf("%d\t",queue_a.circular_array[i]);
}

void main()
{
    queue_a.front = -1;
    queue_a.rear = -1;
    int option = 0;
    while(option != 4)
    {
        printf("\nSelect an option:\n1. Enqueue\n2. Dequeue\n3. Print\n4. Exit\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                print();
                break;
            case 4:
                printf("Exiting!!");
                exit(0);
        }
    }
}


