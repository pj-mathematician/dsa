#include <stdio.h>
#include <stdlib.h>

// implementation of a double linked list and its operations

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

// insert a node at the beginning of the list
void insert_at_beginning(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    new_node->prev = NULL;
    if (head != NULL) {
        head->prev = new_node;
    }
    head = new_node;
}

// insert a node at the end of the list
void insert_at_end(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

// insert a node at a given position
void insert_at_position(int data, int position) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        int i = 0;
        while (i < position - 1) {
            temp = temp->next;
            i++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        if (new_node->next != NULL) {
            new_node->next->prev = new_node;
        }
    }
}

// delete a node from the beginning of the list
void delete_from_beginning() {
    if (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

// delete a node from the end of the list
void delete_from_end() {
    if (head != NULL) {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

// delete a node from a given position
void delete_from_position(int position) {
    if (head != NULL) {
        struct node *temp = head;
        int i = 0;
        while (i < position - 1) {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
        if (temp->next != NULL) {
            temp->next->prev = temp;
        }
        free(temp->next);
    }
}

// print the list
void print_list() {
    if (head != NULL) {
        struct node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// search for a node with a given data
int search(int data) {
    if (head != NULL) {
        struct node *temp = head;
        int i = 0;
        while (temp != NULL) {
            if (temp->data == data) {
                return i;
            }
            temp = temp->next;
            i++;
        }
    }
    return -1;
}

// menu for the double linked list
int main () {
    int choice;
    int data;
    int position;
    while (1) {
        printf("\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Print list\n");
        printf("8. Search\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_at_beginning(data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insert_at_position(data, position);
                break;
            case 4:
                delete_from_beginning();
                break;
            case 5:
                delete_from_end();
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                delete_from_position(position);
                break;
            case 7:
                print_list();
                break;
            case 8:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("%d\n", search(data));
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
