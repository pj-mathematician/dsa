// C program to split an array at the specified position and add the first second half in front
# include <stdio.h>
# include <stdlib.h>

void split_array(int *arr, int *arr_len, int split_pos)
{
    int i, j, k;
    for (i = 0; i < split_pos; i++)
    {
        for (j = 0; j < *arr_len - split_pos; j++)
        {
            arr[j] = arr[j + split_pos];
        }
        for (k = 0; k < split_pos; k++)
        {
            arr[*arr_len - split_pos + k] = arr[k];
        }
    }
}

void print_array(int *arr, int arr_len)
{
    int i;
    for (i = 0; i < arr_len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr_len, split_pos, i;
    printf("Enter the length of the array: ");
    scanf("%d", &arr_len);
    int *arr = (int *)malloc(sizeof(int) * arr_len);
    for (i = 0; i < arr_len; i++)
    {
        printf("Enter the element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter the position at which you want to split the array: ");
    scanf("%d", &split_pos);
    split_array(arr, &arr_len, split_pos);
    print_array(arr, arr_len);
    return 0;
}