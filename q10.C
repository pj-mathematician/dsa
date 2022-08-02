// program to make a 2d array of 10 rows of students and 5 columns of marks and store the marks of each student and then print it
#include <stdio.h>
#include <stdlib.h>

void print_array(int **arr, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows, cols, i, j;
    rows = 10; cols = 5;
    int **arr = (int **)malloc(sizeof(int *) * rows);
    for (i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * cols);
    }
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter the element at index %d, %d: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    print_array(arr, rows, cols);
    return 0;
}