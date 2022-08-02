// program to implement simple queue using linked list in C
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert_queue(struct node **head, int *new_element)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = *new_element;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void delete_queue(struct node **head)
{
    if (*head == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void traverse_queue(struct node *head)
{
    if (head == NULL)
    {
        printf("Queue is empty\n");
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

int main()
{
    int size, i, element, choice;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    struct node *head = NULL;
    printf("Enter the elements of the queue: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &element);
        insert_queue(&head, &element);
    }
    printf("Enter the choice:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Traverse\n");
    printf("4. Exit\n");
    scanf("%d", &choice);
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &element);
            insert_queue(&head, &element);
            break;
        case 2:
            delete_queue(&head);
            break;
        case 3:
            traverse_queue(head);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        printf("Enter the choice:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
    }
    return 0;
}