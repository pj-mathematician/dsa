// program to add two polynomials using linked list in C
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
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct node *temp = *head;
        int i = 0;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
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
        free(temp->next);
        temp->next = NULL;
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
        int i = 0;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        struct node *temp1 = temp->next;
        temp->next = temp->next->next;
        free(temp1);
    }
}

void print_list(struct node *head)
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

void add_polynomials(struct node **head1, struct node **head2)
{
    if (*head1 == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct node *temp1 = *head1;
        struct node *temp2 = *head2;
        int sum = 0;
        while (temp1 != NULL && temp2 != NULL)
        {
            sum = temp1->data + temp2->data;
            insert_at_end(head1, &sum);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1 == NULL)
        {
            while (temp2 != NULL)
            {
                sum = temp2->data;
                insert_at_end(head1, &sum);
                temp2 = temp2->next;
            }
        }
        else
        {
            while (temp1 != NULL)
            {
                sum = temp1->data;
                insert_at_end(head1, &sum);
                temp1 = temp1->next;
            }
        }
    }
}

// take polynomials as input and add them
int main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    int n, i, element;
    printf("Enter the number of elements in first polynomial: ");
    scanf("%d", &n);
    printf("Enter the elements of first polynomial: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &element);
        insert_at_end(&head1, &element);
    }
    printf("Enter the number of elements in second polynomial: ");
    scanf("%d", &n);
    printf("Enter the elements of second polynomial: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &element);
        insert_at_end(&head2, &element);
    }
    printf("First polynomial: ");
    print_list(head1);
    printf("Second polynomial: ");
    print_list(head2);
    add_polynomials(&head1, &head2);
    printf("Sum of polynomials: ");
    print_list(head1);
    return 0;
}

