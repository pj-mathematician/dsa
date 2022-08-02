// program to implement quick sort in an array 
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

void quick_sort(int *arr, int size)
{
    int i, j, pivot, temp;
    if (size <= 1)
    {
        return;
    }
    pivot = arr[0];
    for (i = 1, j = size - 1; i <= j;)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(arr, i);
    quick_sort(arr + i, size - i);
}

int main()
{
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * (size+1));
    // int arr[200 * size];
    for (i = 0; i < size; i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    print_array(arr, size);
    quick_sort(arr, size);
    print_array(arr, size);
    return 0;
}

