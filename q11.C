// menu driven program in C for push pop display in a stack
#include <stdio.h>
#include <stdlib.h>

void push_stack(int *arr, int *top, int *new_element)
{
    if (*top == -1)
    {
        *top = 0;
    }
    else
    {
        *top = *top + 1;
    }
    arr[*top] = *new_element;
}

void pop_stack(int *arr, int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        *top = *top - 1;
    }
}

void display_stack(int *arr, int *top)
{
    int i;
    if (*top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (i = *top; i >= 0; i--)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}   

int main()
{
    int top = -1, choice, new_element;
    int *arr = (int *)malloc(sizeof(int) * 10);
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &new_element);
                push_stack(arr, &top, &new_element);
                break;
            case 2:
                pop_stack(arr, &top);
                break;
            case 3:
                display_stack(arr, &top);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}