// program to implement insert search and deletion in a binary search tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void insert_tree(struct node **root, int *new_element)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = *new_element;
    new_node->left = NULL;
    new_node->right = NULL;
    if (*root == NULL)
    {
        *root = new_node;
    }
    else
    {
        struct node *temp = *root;
        while (temp->left != NULL || temp->right != NULL)
        {
            if (temp->data > *new_element)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (temp->data > *new_element)
        {
            temp->left = new_node;
        }
        else
        {
            temp->right = new_node;
        }
    }
}

void search_tree(struct node *root, int *element)
{
    if (root == NULL)
    {
        printf("Element not found\n");
    }
    else
    {
        struct node *temp = root;
        while (temp != NULL)
        {
            if (temp->data == *element)
            {
                printf("Element found\n");
                return;
            }
            else if (temp->data > *element)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        printf("Element not found\n");
    }
}

void delete_tree(struct node **root, int *element)
{
    if (*root == NULL)
    {
        printf("Element not found\n");
    }
    else
    {
        struct node *temp = *root;
        struct node *parent = NULL;
        while (temp != NULL)
        {
            if (temp->data == *element)
            {
                if (parent == NULL)
                {
                    *root = NULL;
                }
                else if (parent->left == temp)
                {
                    parent->left = NULL;
                }
                else
                {
                    parent->right = NULL;
                }
                free(temp);
                printf("Element deleted\n");
                return;
            }
            else if (temp->data > *element)
            {
                parent = temp;
                temp = temp->left;
            }
            else
            {
                parent = temp;
                temp = temp->right;
            }
        }
        printf("Element not found\n");
    }
}

// menu driven
int main()
{
    int choice, element, new_element, position;
    struct node *root = NULL;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &new_element);
            insert_tree(&root, &new_element);
            break;
        case 2:
            printf("Enter the element to be searched: ");
            scanf("%d", &element);
            search_tree(root, &element);
            break;
        case 3:
            printf("Enter the element to be deleted: ");
            scanf("%d", &element);
            delete_tree(&root, &element);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

