// implement priority queue in C using array
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

int front = -1;
int rear = -1;
int priority_queue[MAX_SIZE];

void insert_queue(int *arr, int *new_element)
{
    if (rear == -1)
    {
        front = 0;
    }
    else
    {
        rear = rear + 1;
    }
    arr[rear] = *new_element;
    // check if the queue is full
    if (rear == MAX_SIZE - 1)
    {
        rear = -1;
        printf("Queue is full\n");
    }
}

void check_priority(int *arr, int *new_element)
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (arr[i] > *new_element)
        {
            break;
        }
    }
    if (i == MAX_SIZE)
    {
        insert_queue(arr, new_element);
    }
    else
    {
        int temp = arr[i];
        arr[i] = *new_element;
        insert_queue(arr, &temp);
    }
}

void delete_queue(int *arr)
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        front = front + 1;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
}

void traverse_queue(int *arr)
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

// menu driven program
int main()
{
    int choice;
    int new_element;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &new_element);
            check_priority(priority_queue, &new_element);
            break;
        case 2:
            delete_queue(priority_queue);
            break;
        case 3:
            traverse_queue(priority_queue);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

