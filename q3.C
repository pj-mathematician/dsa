// program in C to find the duplicate numbers in an array
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

void find_duplicate(int *arr, int size, int *duplicate)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                *duplicate = arr[i];
                break;
            }
        }
    }
}

int main()
{
    int size, i, duplicate = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    print_array(arr, size);
    find_duplicate(arr, size, &duplicate);
    printf("Duplicate element in the array: %d\n", duplicate);
    return 0;
}
