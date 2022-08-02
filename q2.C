// program in C to find the sum and mean of all elements in an array
#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sum_array(int *arr, int size, int *sum)
{
    int i;
    for (i = 0; i < size; i++)
    {
        *sum += arr[i];
    }
}

void mean_array(int *arr, int size, int *mean)
{
    int i;
    for (i = 0; i < size; i++)
    {
        *mean += arr[i];
    }
    *mean /= size;
}

int main()
{
    int size, i, sum = 0, mean = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    print_array(arr, size);
    sum_array(arr, size, &sum);
    printf("Sum of all elements in the array: %d\n", sum);
    mean_array(arr, size, &mean);
    printf("Mean of all elements in the array: %d\n", mean);
    return 0;
}