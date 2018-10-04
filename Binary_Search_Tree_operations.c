#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

struct BST
{
    int data;
    struct BST* left;
    struct BST* right;
};

struct queue
{
    struct BST *pointer;
    struct queue *next;
};

struct queue *front = NULL, *rear = NULL;

struct queue* createqueuenode()
{
    struct queue* temp = (struct queue*)malloc(sizeof(struct queue));
    temp -> pointer = NULL;
    temp -> next = NULL;
    return temp;
}

void push(struct BST* ptr)
{
    if(rear == NULL)
    {
        rear = createqueuenode();
        rear -> pointer = ptr;
        front = rear;
        return;
    }
    rear -> next = createqueuenode();
    rear = rear -> next;
    rear -> pointer = ptr;
}

struct BST* pop()
{
    if(front == NULL) return NULL;
    struct queue* temp = front;
    front = front -> next;
    if(front == NULL) rear = front;
    return temp -> pointer;
}

int isqueueempty()
{
    if(front == NULL && rear == NULL) return 1;
    else return 0;
}

struct BST* createnode()
{
    struct BST* temp = (struct BST*)malloc(sizeof(struct BST));
    temp -> data = 0;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

struct BST* insert(struct BST* root, int value)
{
    if(root == NULL)
    {
        root = createnode();
        root -> data = value;
    }
    else if(value <= root -> data) root -> left = insert(root -> left, value);
    else root -> right = insert(root -> right, value);
    return root;
}

struct BST* find_min(struct BST* root)
{
    if(root -> left == NULL) return root;
    return find_min(root -> left);
}

struct BST* find_max(struct BST* root)
{
    if(root -> right == NULL) return root;
    return find_max(root -> right);
}

int find_height(struct BST* root)
{
    if(root == NULL) return -1;
    int left = find_height(root -> left);
    int right = find_height(root -> right);
    return (left > right ? left + 1 : right + 1);
}

void pre_order_print(struct BST* root)
{
    if(root == NULL) return;
    printf("%d\t", root -> data);
    pre_order_print(root -> left);
    pre_order_print(root -> right);
}

void in_order_print(struct BST* root)
{
    if(root == NULL) return;
    in_order_print(root -> left);
    printf("%d\t", root -> data);
    in_order_print(root -> right);
}

void post_order_print(struct BST* root)
{
    if(root == NULL) return;
    post_order_print(root -> left);
    post_order_print
    (root -> right);
    printf("%d\t", root -> data);
}

void level_order_print(struct BST* root)
{
    struct BST* temp = (struct BST*)malloc(sizeof(struct BST));
    push(root);
    while(!isqueueempty())
    {
        temp = pop();
        printf("%d\t", temp -> data);
        if(temp -> left != NULL) push(temp -> left);
        if(temp -> right != NULL) push(temp -> right);
    }
    free(temp);
}

bool isBST(struct BST* root, int min, int max)
{
    if(root == NULL) return true;
    if(root -> data < min || root -> data > max) return false;
    return(isBST(root -> left, min, root -> data) && isBST(root -> right, root -> data, max));
}

struct BST* find_node(struct BST* root, int value_to_find)
{
    if(root == NULL) return root;
    if(value_to_find < root -> data) return(find_node(root -> left, value_to_find));
    else if(value_to_find > root -> data) return(find_node(root -> right, value_to_find));
    else return root;
}

struct BST* delete_node(struct BST* root, int value_to_delete)
{
    if(root == NULL) return root;
//    if(value_to_delete < root -> data) root -> left = delete_node(root -> left, value_to_delete);
//    else if(value_to_delete > root -> data) root -> right = delete_node(root -> right, value_to_delete);
    if(find_node(root,value_to_delete) != NULL)
    {
//        Handing case where node to be deleted is a Leaf node
        if(root -> left == NULL && root -> right == NULL)
        {
            free(root);
            root = NULL;
        }
//        Handing case where node to be deleted only has RIGHT node
        else if(root -> left == NULL)
        {
            struct BST* temp = root;
            root = root -> right;
            free(temp);
        }
//        Handing case where node to be deleted only has LEFT node
        else if(root -> right == NULL)
        {
            struct BST* temp = root;
            root = root -> left;
            free(temp);
        }
//        Handing case where node to be deleted has both left and right nodes
        else
        {
            struct BST* temp = find_max(root -> left);
            root -> data = temp -> data;
            root -> left = delete_node(root -> left, temp -> data);
        }
    }
    return root;
}

struct BST* in_order_successor(struct BST* root, int value)
{
    struct BST* current = find_node(root, value);
    if(current == NULL) return NULL;

//If current node has right subtree, then the left-most node in the right subtree is the successor
    if(current -> right != NULL)
        return find_min(current -> right);
    else
    {
        struct BST* successor = NULL;
        struct BST* ancestor = root;
        while(ancestor != current)
        {
            if(current -> data < ancestor -> data)
            {
                successor = ancestor;
                ancestor = ancestor -> left;
            }
            else ancestor = ancestor -> right;
        }
        return successor;
    }
}

struct BST* in_order_predecessor(struct BST* root, int value)
{
    struct BST* current = find_node(root, value);
    if(current == NULL) return NULL;

//If current node has left subtree, then the right-most node in the left subtree is the predecessor
    if(current -> left != NULL)
        return find_max(current -> left);
    else
    {
        struct BST* predecessor = NULL;
        struct BST* ancestor = root;
        while(ancestor != current)
        {
            if(current -> data > ancestor -> data)
            {
                predecessor = ancestor;
                ancestor = ancestor -> right;
            }
            else ancestor = ancestor -> left;
        }
        return predecessor;
    }
}

void main()
{
int option = 0, value = 0, find_successor = 0, find_predecessor = 0;

struct BST *root = NULL;

while(option != 13)
{
    printf("\nSelect an option:\n1. Insert into the Binary Search Tree\n2. Find Minimum Value\n3. Find Maximum Value\n");
    printf("4. Find Height of BST\n5. Print Binary Search Tree - Pre-Order\n6. Print Binary Search Tree - In-Order\n");
    printf("7. Print Binary Search Tree - Post-Order\n8. Print Binary Search Tree - Level-Order\n9. Delete a node\n");
    printf("10. Check if BST is valid\n11. In-order Successor\n12. In-order Predecessor\n13. Exit\n");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        printf("\nEnter value to insert:");
        scanf("%d", &value);
        root = insert(root,value);
        break;
    case 2:
        if(root == NULL)
        {
            printf("\nBST is empty!!\n");
        }
        else printf("%s\t%d\n","\nMinimum value is:",find_min(root) -> data);
        break;
    case 3:
        if(root == NULL)
        {
            printf("\nBST is empty!!\n");
        }
        else printf("%s\t%d\n","\nMaximum value is:",find_max(root) -> data);
        break;
    case 4:
        if(root == NULL)
        {
            printf("\nBST is empty!!\n");
        }
        else printf("%s\t%d\n","\nHeight of BST is:",find_height(root));
        break;
    case 5:
        pre_order_print(root);
        break;
    case 6:
        in_order_print(root);
        break;
    case 7:
        post_order_print(root);
        break;
    case 8:
        level_order_print(root);
        break;
    case 9:
        if(root == NULL)
        {
            printf("\nBST is empty!!\n");
        }
        else
        {
            int delete_value = 0;
            printf("\nEnter value to delete:\n");
            scanf("%d",&delete_value);
            root = delete_node(root,delete_value);
        }
        break;
    case 10:
        if(isBST(root, INT_MIN, INT_MAX)) printf("\nBST is valid\n");
        else printf("\nBST is invalid\n");
        break;
    case 11:
        printf("\nEnter value to find successor for :\n");
        scanf("%d",&find_successor);
        struct BST *successor = in_order_successor(root, find_successor);
        successor == NULL ? printf("\nSuccessor not found\n") : printf("%s\t%d\n","\nSuccessor is :",successor -> data);
        break;
    case 12:
        printf("\nEnter value to find predecessor for :\n");
        scanf("%d",&find_predecessor);
        struct BST *predecessor = in_order_predecessor(root, find_predecessor);
        predecessor == NULL ? printf("\nPredecessor not found\n") : printf("%s\t%d\n","\nPredecessor is :",predecessor -> data);
        break;
    case 13:
        printf("Exiting!!");
        exit(0);
    default:
        printf("Incorrect option");
        break;
    }
}
}
