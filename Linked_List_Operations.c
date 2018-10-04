#include<stdio.h>
#include<stdlib.h>

struct Node* insert_at_head(struct Node*);
struct Node* insert_at_tail(struct Node*);
struct Node* delete(struct Node*);
void print(struct Node*);
struct Node* reverse_iterative(struct Node*);
struct Node* reverse_recursion(struct Node*);

struct Node
{
    int data;
    struct Node* next;
};

//Insert at head of a singly linked list
struct Node* insert_at_head(struct Node* head)
{
    int n, x;
    printf("How many numbers?\n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter the number:\n");
        scanf("%d",&x);
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp -> data = x;
        temp -> next = head;
        head = temp;
    }
    return head;
}

//Insert at tail of a singly linked list
struct Node* insert_at_tail(struct Node* head)
{
    int n, x;
    printf("How many numbers?\n");
    scanf("%d",&n);
    struct Node* tail = head;
    for(int i = 0; i < n; i++)
    {
        printf("Enter the number:\n");
        scanf("%d",&x);
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp -> data = x;
        temp -> next = NULL;
        if(i == 0) head = temp;
        if(i != 0) tail -> next = temp;
        tail = temp;
    }
    return head;
}

struct Node* delete(struct Node* head)
{
    int pos;
    printf("Enter the position of element to delete:\n");
    scanf("%d",&pos);
    struct Node* temp = head;
    if(pos == 1)
    {
        head = temp -> next;
        free(temp);
        return(head);
    }
    for(int i = 1; i < pos - 1; i++)
        temp = temp -> next;
    struct Node* temp1 = temp -> next;
    temp -> next = temp1 -> next;
    free(temp1);
    return head;
}

struct Node* reverse_iterative(struct Node* head)
{
    struct Node* prev = NULL, *current, *after;
    current = head;
    while(current != NULL)
    {
        after = current -> next;
        current -> next = prev;
        prev = current;
        current = after;
    }
    head = prev;
    return head;
}

struct Node* reverse_recursion(struct Node* head)
{
    if(head -> next == NULL) return head;
    struct Node* p = reverse_recursion(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return p;
}

//Print elements of Linked List
void print(struct Node* head)
{
    struct Node* temp = head;
    printf("\nThe Linked List is:\n");
    while(temp != NULL)
    {
        printf("%d\t", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void main()
{
    struct Node* head = NULL;
    int option = 0;
    while(option != 7)
    {
        printf("\nLinked List operations:\n");
        printf("1. Insert at head of Singly Linked List\n");
        printf("2. Insert at tail of Singly Linked List\n");
        printf("3. Delete from Singly Linked List\n");
        printf("4. Reverse the Singly Linked List using iteration\n");
        printf("5. Reverse the Singly Linked List using recursion\n");
        printf("6. Print the Linked List\n");
        printf("7. Exit\n");
        printf("\nEnter your option:\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            head = insert_at_head(head);
            print(head);
            break;
        case 2:
            head = insert_at_tail(head);
            print(head);
            break;
        case 3:
            head = delete(head);
            print(head);
            break;
        case 4:
            head = reverse_iterative(head);
            print(head);
            break;
        case 5:
            head = reverse_recursion(head);
            print(head);
            break;
        case 6:
            print(head);
            break;
        case 7:
            printf("\nExiting!!!\n");
            break;
        default:
            printf("\nInvalid option\n");
        }
    }
}
