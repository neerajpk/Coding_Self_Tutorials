#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>

void print(int *array, int arr_size)
{
    int i = 0;
    while(i < arr_size)
        printf("%d\t",array[i++]);
}

int find_min(int *array, int arr_size, int index)
{
    int temp_min = INT_MAX, return_index = index;
    for(int i = index; i < arr_size; i++)
    {
        if(array[i] < temp_min)
        {
            temp_min = array[i];
            return_index = i;
        }
    }
    return return_index;
}

void selection_sort(int *orig_array, int arr_size)
{
    int *array = (int*)calloc(arr_size, sizeof(int));
    memcpy(array, orig_array, arr_size * sizeof(int));
    int temp = 0, ret_ind = 0;
    for(int i = 0; i < arr_size - 1; i++)
    {
        ret_ind = find_min(array,arr_size,i);
        if(i == ret_ind) continue;
        else
        {
            temp = array[ret_ind];
            array[ret_ind] = array[i];
            array[i] = temp;
        }
    }
    print(array, arr_size);
    free(array);
}

void bubble_sort(int *orig_array, int arr_size)
{
    int *array = (int*)calloc(arr_size, sizeof(int));
    memcpy(array, orig_array, arr_size * sizeof(int));
    int temp = 0, flag = 0;
    for(int k = 0; k < arr_size; k++)
    {
        flag = 0;
        for(int i = 0; i < arr_size - k; i++)
        {
            if(array[i + 1] < array[i])
            {
                temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
    print(array, arr_size);
    free(array);
}

void insertion_sort(int *orig_array, int arr_size)
{
    int *array = (int*)calloc(arr_size, sizeof(int));
    memcpy(array, orig_array, arr_size * sizeof(int));
    int temp = 0;
    for(int i = 1; i < arr_size; i++)
    {
        temp = array[i];
        for(int j = i - 1; j >= 0; j--)
        {
            if(temp < array[j])
            {
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
    print(array, arr_size);
    free(array);
}

void merge_sort_util(int *array, int *temp_array, int left_start, int right_end)
{
    int left_end = (left_start + right_end)/2;
    int right_start = left_end + 1;
    int i = left_start, j = right_start, k = left_start;
    while(i <= left_end && j <= right_end)
    {
        if(array[i] <= array[j])
            temp_array[k++] = array[i++];
        else
            temp_array[k++] = array[j++];
    }
    while(i <= left_end) temp_array[k++] = array[i++];
    while(j <= right_end) temp_array[k++] = array[j++];
    k = left_start;
    while(k <= right_end)
        array[k] = temp_array[k++];
}

void merge_sort(int *array, int *temp_array, int left_start, int right_end)
{
    if(left_start >= right_end) return;
    int mid = (left_start + right_end)/2;
    merge_sort(array, temp_array, left_start, mid);
    merge_sort(array, temp_array, mid + 1, right_end);
    merge_sort_util(array, temp_array, left_start, right_end);
}

int quick_sort_util(int *array, int low, int high)
{
    int i = low - 1, temp = 0, pivot = array[high];
    for(int j = low; j <= high - 1; j++)
    {
        if(array[j] <= pivot)
        {
            temp = array[++i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[++i];
    array[i] = array[high];
    array[high] = temp;
    return i;
}

void quick_sort(int *array, int low, int high)
{
    if(low > high) return;
    int partition = quick_sort_util(array, low, high);
    quick_sort(array, low, partition - 1);
    quick_sort(array, partition + 1, high);
}

void main()
{
    int arr_size = 0, option = 0, *temp_array;
    printf("\nEnter the size of the array to sort :\t");
    scanf("%d",&arr_size);
    int array[arr_size];
    for(int i = 0; i < arr_size; i++)
    {
        printf("\nEnter array element:\t");
        scanf("%d",&array[i]);
    }
    while(option != 6)
    {
        printf("\nArray entered! On to the sorting bit.\n\n");
        printf("1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Merge Sort\n5. Quick Sort\n6. Exit\n");
        printf("\nSelect a option :\t");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("\nThe original array is :\n");
            print(array, arr_size);
            printf("\nThe sorted array is :\n");
            selection_sort(array, arr_size);
            break;
        case 2:
            printf("\nThe original array is :\n");
            print(array, arr_size);
            printf("\nThe sorted array is :\n");
            bubble_sort(array, arr_size);
            break;
        case 3:
            printf("\nThe original array is :\n");
            print(array, arr_size);
            printf("\nThe sorted array is :\n");
            insertion_sort(array, arr_size);
            break;
        case 4:
            printf("\nThe original array is :\n");
            print(array, arr_size);
            printf("\nThe sorted array is :\n");
            int *copy_array = (int*)calloc(arr_size, sizeof(int));
            temp_array = (int*)calloc(arr_size, sizeof(int));
            memcpy(copy_array, array, arr_size * sizeof(int));
            memcpy(temp_array, array, arr_size * sizeof(int));
            merge_sort(copy_array, temp_array, 0, arr_size - 1);
            print(copy_array, arr_size);
            free(copy_array);
            free(temp_array);
            break;
        case 5:
            printf("\nThe original array is :\n");
            print(array, arr_size);
            printf("\nThe sorted array is :\n");
            temp_array = (int*)calloc(arr_size, sizeof(int));
            memcpy(temp_array, array, arr_size * sizeof(int));
            quick_sort(temp_array, 0, arr_size - 1);
            print(temp_array, arr_size);
            free(temp_array);
            break;
        case 6:
            printf("\nExiting!!\n");
            exit(0);
        default:
            break;
        }
    }
}
