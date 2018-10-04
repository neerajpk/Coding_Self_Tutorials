#include<stdio.h>

void swap_value(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_reference(int **a, int **b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main()
{
    int a = 1, b = 2;
    swap_value(a,b);
    printf("a = %d\tb = %d",a,b);
    swap_reference(&a,&b);
    printf("a = %d\tb = %d",a,b);
}
