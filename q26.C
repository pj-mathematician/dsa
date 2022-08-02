// program to implement heap sort in an array
#include <stdio.h>
#include <stdlib.h>

void heapify(int *arr, int size, int i);
void print_array(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void heap_sort(int *arr, int size)
{
    int i, temp;
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
    for (i = size - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void heapify(int *arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, size, largest);
    }
}

int main()
{
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    print_array(arr, size);
    heap_sort(arr, size);
    print_array(arr, size);
    return 0;
}
