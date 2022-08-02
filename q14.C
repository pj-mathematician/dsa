// menu driven program to perform enqueue dequeue and display operations on a queue using array
# include <stdio.h>
# include <stdlib.h>

    void enqueue(int *arr, int *front, int *rear, int *new_element)
    {
        if (*rear == 9)
        {
            printf("Queue is full\n");
        }
        else
        {
            if (*front == -1)
            {
                *front = 0;
            }
            *rear = *rear + 1;
            arr[*rear] = *new_element;
        }
    }
    
    void dequeue(int *arr, int *front, int *rear)
    {
        if (*front == -1)
        {
            printf("Queue is empty\n");
        }
        else
        {
            *front = *front + 1;
        }
    }
    
    void display(int *arr, int *front, int *rear)
    {
        int i;
        if (*front == -1)
        {
            printf("Queue is empty\n");
        }
        else
        {
            for (i = *front; i <= *rear; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
    
    int main()
    {
        int front = -1, rear = -1, choice, new_element;
        int *arr = (int *)malloc(sizeof(int) * 10);
        while (1)
        {
            printf("1. Enqueue\n");
            printf("2. Dequeue\n");
            printf("3. Display\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                    printf("Enter the element to be enqueued: ");
                    scanf("%d", &new_element);
                    enqueue(arr, &front, &rear, &new_element);
                    break;
                case 2:
                    dequeue(arr, &front, &rear);
                    break;
                case 3:
                    display(arr, &front, &rear);
                    break;
                case 4:
                    exit(0);
                    break;      
            }
        }
        return 0;
    }