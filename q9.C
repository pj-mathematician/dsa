// merge two sorted arrays and print the result
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

void merge_arrays(int *arr1, int size1, int *arr2, int size2, int *arr3)
{
    int i, j, k;
    for (i = 0, j = 0, k = 0; i < size1 && j < size2;)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < size1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    print_array(arr3, size1 + size2);
}

int main()
{
    int size1, size2, i;
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    int *arr1 = (int *)malloc(sizeof(int) * size1);
    for (i = 0; i < size1; i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    int *arr2 = (int *)malloc(sizeof(int) * size2);
    for (i = 0; i < size2; i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr2[i]);
    }
    print_array(arr1, size1);
    print_array(arr2, size2);
    int *arr3 = (int *)malloc(sizeof(int) * (size1 + size2));
    merge_arrays(arr1, size1, arr2, size2, arr3);
    return 0;
}