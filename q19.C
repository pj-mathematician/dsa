// program to implement traversal search insertion and deletion in a singly linked list 
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert_at_beginning(struct node **head, int *new_element)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = *new_element;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_end(struct node **head, int *new_element)
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

void insert_at_position(struct node **head, int *new_element, int position)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = *new_element;
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = *head;
        int i;
        for (i = 0; i < position - 2; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void delete_at_beginning(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void delete_at_end(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = *head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        struct node *temp1 = temp->next;
        temp->next = NULL;
        free(temp1);
    }
}

void delete_at_position(struct node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp = *head;
        int i;
        for (i = 0; i < position - 2; i++)
        {
            temp = temp->next;
        }
        struct node *temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
    }
}

void traverse_list(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
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
    int choice, element, position;
    struct node *head = NULL;
    while (1)
    {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Traverse list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                insert_at_beginning(&head, &element);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                insert_at_end(&head, &element);
                break;
            case 3:
                printf("Enter the element to be inserted: ");
                scanf("%d", &element);
                printf("Enter the position: ");
                scanf("%d", &position);
                insert_at_position(&head, &element, position);
                break;
            case 4:
                delete_at_beginning(&head);
                break;
            case 5:
                delete_at_end(&head);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                delete_at_position(&head, position);
                break;
            case 7:
                traverse_list(head);
                break;
            case 8:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}