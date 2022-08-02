// program to implement stack using linked list in C
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **head, int *new_element)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = *new_element;
    new_node->next = *head;
    *head = new_node;
}

void pop(struct node **head)
{
    if (*head == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// menu driven
int main()
{
    int choice, new_element;
    struct node *head = NULL;
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
                printf("Enter new element: ");
                scanf("%d", &new_element);
                push(&head, &new_element);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                display(head);
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
