#include <stdio.h>
#include <stdlib.h>

// program to take an array as input and search an element using linear search
void print_array(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void linear_search(int *arr, int size, int key)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            printf("Element found at index %d\n", i);
            return;
        }
    }
    printf("Element not found\n");
}

int main()
{
    int size, i, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr [size];
    for (i = 0; i < size; i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    print_array(arr, size);
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    linear_search(arr, size, key);
    return 0;
}