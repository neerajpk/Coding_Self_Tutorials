#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int add_one(int num)
{
    int i = 1;
    while(num & i)
    {
        num = num ^ i;
        i <<= 1;
    }
    num = num ^ i;
    return num;
}

int mult_by_fraction(int num)
{
    return ((num << 1) + num + (num >> 1));
}

int turn_off_rightmost_setbit(int num)
{
    int i = 0, n = -1;
    while(i == 0)
    {
        i = num & (1 << ++n);
    }
    num = num ^ (1 << n);
    return num;
}

void check_machine_endianness()
{
    unsigned int i = 1;
    char *c = (char*)&i;
    if(*c) printf("\nMachine is Little Endian\n");
    else printf("\nMachine is Big Endian\n");
}

int count_set_bits(int num)
{
    int i = 0, count = 0;
    while(num)
    {
        num = num & (num - 1);
        count++;
    }
    return count;
}

int count_bits_to_convert(int A, int B)
{
    int count = 0, temp = A ^ B;
    while(temp)
    {
        temp = temp & (temp - 1);
        count++;
    }
    return count;
}

int mult_by_seven(int num)
{
    return ((num << 2) + (num << 1) + num);
}

void power_of_two(int num)
{
    if(num && (num - 1) == 0) printf("\nPower of 2\n");
    else printf("NOT power of 2\n");
}

int position_of_rightmost_setbit(int num)
{
    int pos = -1, temp = 0;
    while(temp == 0)
    {
        temp = num & (1 << ++pos);
    }
    return pos;
}

void binary_representation(int n)
{
    if(n == 0) return;
    binary_representation(n/2);
    printf("%d",n % 2);
}

int equalize(char *a, char *b, int size_a, int size_b)
{
    int size = (size_a > size_b) ? size_a : size_b, j = 0;
    char *temp = (char*)malloc(size * sizeof(char));
    if(size_a > size_b)
    {
        j  = size_b - 1;
        for(int i = size_a - 1; i >=0; i--)
        {
            if(j >=0)
            {
                temp[i] = b[j--];
                continue;
            }
            else temp[i] = '0';
        }
        memcpy(b,temp,size * sizeof(int));
    }
    else
    {
        j  = size_a - 1;
        for(int i = size_b - 1; i >=0; i--)
        {
            if(j >=0)
            {
                temp[i] = a[j--];
                continue;
            }
            else temp[i] = '0';
        }
        memcpy(a,temp,size * sizeof(char));
    }
    free(temp);
    return size;
}

void add_two_bit_strings(char *a, char *b, int size)
{
    char *temp = (char*)malloc((size) * sizeof(char));
    int carry = 0;
    for(int i = size - 1; i >= 0; i--)
    {
        temp[i] = ((a[i] - '0') ^ (b[i] - '0') ^ carry) + '0';
        carry = ((a[i] - '0') & (b[i] - '0')) | ((b[i] - '0') & carry) | (carry & (a[i] - '0'));
    }
    if(carry == 1)
    {
        temp = (char*)realloc(temp,(size + 1) * sizeof(char));
        temp[0] = carry + '0';
    }
    while(*temp != '\0') printf("%c\t",*(temp++));
    free(temp);
}

void flip_bit_to_win(char *s, int length)
{
    int i = length - 1, flip_bit = 0, array_index = 0, count = 0, temp = 0;
    int *count_array = (int*)calloc(1,sizeof(int));
    printf("%d\n",length);
    while(i >= 0)
    {
        if(s[i] == '1')
        {
            if(flip_bit == 1)
            {
                count_array = (int*)realloc(count_array, (++array_index + 1) * sizeof(int));
                count_array[array_index] = 0;
            }
            count_array[array_index]+=1;
            flip_bit = 0;
        }
        else
        {
            if(flip_bit == 1)
            {
                count_array = (int*)realloc(count_array, (++array_index + 1) * sizeof(int));
                count_array[array_index] = 0;
            }
            flip_bit = 1;
        }
        i--;
    }
    i = 0;
    while(i < array_index)
    {
        if(count_array[i] != 0 && count_array[i + 1] != 0 && (count_array[i] + count_array[i + 1] > temp))
        {
            count = count_array[i] + count_array[i + 1];
            temp = count;
        }
        i++;
    }
    printf("\nCount is : %d", count);
    free(count_array);
}

void main()
{
    int option = 0, num1, num2;
    char a[20], b[20];
    printf("\nSelect option:\n");
    printf("1. Add 1 to a number without the use of arithmetic operators\n");
    printf("2. Multiply number by 3.5 without using mult/div operators\n");
    printf("3. Turn off rightmost set bit\n");
    printf("4. Check machine endianness\n");
    printf("5. Count set bits\n");
    printf("6. Count bits to flip to convert A to B\n");
    printf("7. Multiply by 7\n");
    printf("8. Find whether power of 2\n");
    printf("9. Find position of rightmost set-bit\n");
    printf("10. Binary representation of integer\n");
    printf("11. Add two bit strings\n");
    printf("12. Flip Bit to Win\n");
    printf("Option : \t");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        printf("\nEnter number:\t");
        scanf("%d",&num1);
        printf("\nResult = %d\n",add_one(num1));
        break;
    case 2:
        printf("\nEnter number:\t");
        scanf("%d",&num1);
        printf("\nResult = %d\n",mult_by_fraction(num1));
        break;
    case 3:
        printf("\nEnter number:\t");
        scanf("%d",&num1);
        printf("\nResult = %d\n",turn_off_rightmost_setbit(num1));
        break;
    case 4:
        check_machine_endianness();
        break;
    case 5:
        printf("\nEnter number:\t");
        scanf("%d",&num1);
        printf("\nResult = %d\n",count_set_bits(num1));
        break;
    case 6:
        printf("\nEnter A:\t");
        scanf("%d",&num1);
        printf("\nEnter B:\t");
        scanf("%d",&num2);
        printf("\nResult = %d\n",count_bits_to_convert(num1,num2));
        break;
    case 7:
        printf("\nEnter number:\t");
        scanf("%d",&num1);
        printf("\nResult = %d\n",mult_by_seven(num1));
        break;
    case 8:
        printf("\nEnter number:\t");
        scanf("%d",&num1);
        power_of_two(num1);
        break;
    case 9:
        printf("\nEnter number:\t");
        scanf("%d",&num1);
        printf("\nResult = %d\n",position_of_rightmost_setbit(num1));
        break;
    case 10:
        printf("\nEnter number:\t");
        scanf("%d",&num1);
        binary_representation(num1);
        break;
    case 11:
        printf("\nEnter first string:\t");
        scanf("%s",&a);
        printf("\nEnter second string:\t");
        scanf("%s",&b);
        add_two_bit_strings(a, b, equalize(a, b, strlen(a), strlen(b)));
        break;
    case 12:
        printf("Enter binary sequence:\t");
        scanf("%s",&a);
        flip_bit_to_win(a, strlen(a));
    default:
        break;
    }
}
