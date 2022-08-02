// program in C to find the number of non-repeated elements in an array
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

// function to find all the non-repeated elements in an array
int find_non_repeated_element(int *arr, int size) {
    int i, j;
    int non_repeated_element = 0;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
            else {
                non_repeated_element = arr[i];
                goto end;
            }
        }
        if (j == size) {
            non_repeated_element = arr[i];
        }
    }
    end:
    return non_repeated_element;
}

int main() {
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++) {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    print_array(arr, size);
    int non_repeated_element = find_non_repeated_element(arr, size);
    printf("Non-repeated element in the array: %d\n", non_repeated_element);
    return 0;
}