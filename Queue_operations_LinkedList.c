#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

void enqueue();
void dequeue();
void print();

struct node
{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue()
{
    int enqueue_val = 0;
    printf("\nEnter value to enqueue :");
    scanf("%d",&enqueue_val);
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = enqueue_val;
    newNode -> next = NULL;
    if(rear == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear -> next = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if(front == NULL)
    {
        printf("\nQueue is empty!!\n");
        return;
    }
    struct node* temp = front;
    front = front -> next;
    free(temp);
}

void print()
{
    if(front == NULL)
    {
        printf("\nQueue is empty!!\n");
        return;
    }
    struct node* temp = front;
    printf("\nPrinting Queue :\n");
    while(temp != NULL)
    {
        printf("%d\t",temp -> data);
        temp = temp -> next;
    }
}

void main()
{
    int option = 0;
    while(option != 4)
    {
        printf("\nSelect an option:\n1. Enqueue\n2. Dequeue\n3. Print\n4. Exit\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                enqueue();
                break;Previously on my setup, I had seen this crash happen at End Call.
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


