#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 5

void push(char);
char pop();
int operate(int, int, char);
void postfix(char*);
void prefix(char*, int);
void infix_to_postfix(char *);
int checkifprecedence(char);

struct stack
{
    char stck[MAX_SIZE];
    int top;
};

struct stack S;

void push(char operand)
{
    if(S.top == MAX_SIZE - 1)
    {
        printf("\nSTACK OVERFLOW\n");
        exit(0);
    }
    else
    {
        S.top++;
        S.stck[S.top] = operand;
    }
}

char pop()
{
    char return_val;
    if(S.top == -1)
    {
        printf("\nStack is empty\n");
        exit(0);
    }
    else
    {
        return_val = S.stck[S.top];
        S.top--;
    }
    return return_val;
}

void postfix(char *expression)
{
    printf("\nExpression is PostFix\n");
    int i = 0, operand = 0, OP1 = 0, OP2 = 0;
    while(expression[i] != '\0')
    {
        if(isdigit(expression[i]))
        {
            operand = expression[i++] - '0';
            push(operand);
        }
        else
        {
            OP2 = pop();
            OP1 = pop();
            push(operate(OP1, OP2, expression[i++]));
        }
    }
    printf("%s\t%d\n","The Result is :",pop());
}

void prefix(char *expression, int length)
{
    printf("\nExpression is Prefix\n");
    int i = length - 1, operand = 0, OP1 = 0, OP2 = 0;
    while(i != -1)
    {
        if(isdigit(expression[i]))
        {
            operand = expression[i--] - '0';
            push(operand);
        }
        else
        {
            OP1 = pop();
            OP2 = pop();
            push(operate(OP1, OP2, expression[i--]));
        }
    }
    printf("%s\t%d\n","The Result is :",pop());
}

int checkifprecedence(char oper)
{
    char precedence_chart[4] = {'*', '/', '+', '-'};
    char stck_top = S.stck[S.top];
    if(stck_top == '(' || stck_top == ')') return 1;
    int i = 0, j = 0;
    for(;i < 4; i++) if(S.stck[S.top] == precedence_chart[i]) break;
    for(;j < 4; j++) if(oper == precedence_chart[j]) break;
    if(j < i) return 1;
    else return 0;
}

void infix_to_postfix(char * expression)
{
    char * postfix = (char*)malloc(sizeof(char));
    int postfix_size = 0, i = 0;
    while(expression[i] != '\0')
    {
        if(isdigit(expression[i]))
        {
            postfix = (char*)realloc(postfix, sizeof(char) * ++postfix_size);
            postfix[postfix_size - 1] = expression[i];
        }
        else if(expression[i] == '(') push(expression[i]);
        else if(expression[i] == ')')
        {
            postfix = (char*)realloc(postfix, sizeof(char) * ++postfix_size);
            postfix[postfix_size - 1] = pop();
            pop();
        }
        else if(checkifprecedence(expression[i])) push(expression[i]);
        else
        {
            postfix = (char*)realloc(postfix, sizeof(char) * ++postfix_size);
            postfix[postfix_size - 1] = pop();
            push(expression[i]);
        }
        i++;
    }
    postfix = (char*)realloc(postfix, sizeof(char) * ++postfix_size);
    postfix[postfix_size - 1] = pop();

    i = 0;
    printf("Infix converted to postfix is :\n");
    while(i < postfix_size)
        printf("%c",postfix[i++]);

    free(postfix);
}

int operate(int OP1, int OP2, char operand)
{
    switch(operand)
    {
    case '+':
        return OP1 + OP2;
        break;
    case '-':
        return OP1 - OP2;
        break;
    case '*':
        return OP1 * OP2;
        break;
    case '/':
        return OP1/OP2;
        break;
    default:
        printf("\nUndefined operator\n");
        break;
    }
    return 0;
}

void main()
{
    int option = 0;
    while(option != 4)
    {
        S.top = -1;
        char expression[50];
        printf("\nChoose an option :\n1. Prefix evaluation\n2. Postfix evaluation\n3. Infix to Postfix\n4. Exit\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("\nEnter the expression : ");
                scanf("%s",&expression);
                postfix(expression);
                break;
            case 2:
                printf("\nEnter the expression : ");
                scanf("%s",&expression);
                prefix(expression, strlen(expression));
                break;
            case 3:
                printf("\nEnter the expression : ");
                scanf("%s",&expression);
                infix_to_postfix(expression);
                break;
            case 4:
                printf("\nExiting!!\n");
                exit(0);
        }
    }
}
