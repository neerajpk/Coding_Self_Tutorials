#include<stdio.h>
#include<stdlib.h>

struct Node* insert(struct Node*, int);
void print(struct Node*);

struct Node
{
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = head;
    head = temp;
    return head;
}

void print(struct Node* head)
{
    struct Node* temp = head;
    printf("The Linked List is:\n");
    while(temp != NULL)
    {
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }
}

void main()
{
    struct Node* head = NULL;
    int n, x;
    printf("How many numbers?\n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter the number:\n");
        scanf("%d",&x);
        head = insert(head, x);
    }
    print(head);
}
