// program to implement merge sort in C
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

void sort_array(int *arr, int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void merge_arrays(int *arr1, int *arr2, int size1, int size2)
{
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < size1 && j < size2; k++)
    {
        if (arr1[i] < arr2[j])
        {
            arr1[k] = arr1[i];
            i++;
        }
        else
        {
            arr1[k] = arr2[j];
            j++;
        }
    }
    while (i < size1)
    {
        arr1[k] = arr1[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        arr1[k] = arr2[j];
        j++;
        k++;
    }
}

int main()
{
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr1 = (int *)malloc(sizeof(int) * size);
    int *arr2 = (int *)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < size; i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr2[i]);
    }
    print_array(arr1, size);
    print_array(arr2, size);
    sort_array(arr1, size);
    sort_array(arr2, size);
    print_array(arr1, size);
    print_array(arr2, size);
    merge_arrays(arr1, arr2, size, size);
    print_array(arr1, size);
    return 0;
}
