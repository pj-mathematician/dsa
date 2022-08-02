#include <stdio.h>
#include <stdlib.h>

// program to implement insertion deletion and traversal of an array
void print_array(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert_element(int *arr, int size, int index, int element)
{
    int i;
    for (i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
}

void delete_element(int *arr, int size, int index)
{
    int i;
    for (i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

// menu driven program to implement insertion deletion and traversal of an array and check at each step if the array is full or not and update size accordingly
int main()
{
    int size, i, element, index, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int size_max = size;
    int *arr = (int *)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    print_array(arr, size);
    while (1)
    {
        printf("\n1. Insert element\n2. Delete element\n3. Traverse array\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (size == size_max)
            {
                printf("Array is full\n");
                break;
            }
            printf("Enter the index at which you want to insert: ");
            scanf("%d", &index);
            printf("Enter the element to be inserted: ");
            scanf("%d", &element);
            insert_element(arr, size, index, element);
            size++;
            print_array(arr, size);
            break;
        case 2:
            if (size == 0)
            {
                printf("Array is empty\n");
                break;
            }
            printf("Enter the index at which you want to delete: ");
            scanf("%d", &index);
            delete_element(arr, size, index);
            size--;
            print_array(arr, size);
            break;
        case 3:
            print_array(arr, size);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}