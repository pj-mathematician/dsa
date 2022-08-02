// program to perform bubble sort and to find the median of an array
#include <stdio.h>
#include <stdlib.h>

int bubble_sort(int *arr, int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return 0;
}

int find_median(int *arr, int size)
{
    int i, median;
    bubble_sort(arr, size);
    if (size % 2 == 0)
    {
        median = (arr[size / 2] + arr[size / 2 - 1]) / 2;
    }
    else
    {
        median = arr[size / 2];
    }
    return median;
}

void print_array(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// main function with bubble sort and print the array and find median
int main()
{
    int size, i, median;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, size);
    print_array(arr, size);
    median = find_median(arr, size);
    printf("Median of the array: %d\n", median);
    return 0;
}
