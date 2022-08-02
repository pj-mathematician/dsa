#include <stdio.h>
#include <stdlib.h>

// implementation of circular linked list and its operations

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// insert a node at the beginning of the list
void insert_at_beginning(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// print the list
void print_list() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// insert a node at the end of the list
void insert_at_end(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// insert a node at a given position in the list
void insert_at_position(int data, int position) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (position == 0) {
        new_node->next = head;
        head = new_node;
    } else {
        struct node *temp = head;
        int i;
        for (i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// delete a node from the beginning of the list
void delete_from_beginning() {
    struct node *temp = head;
    head = head->next;
    free(temp);
}

// delete a node from the end of the list
void delete_from_end() {
    struct node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// delete a node from a given position in the list
void delete_from_position(int position) {
    if (position == 0) {
        delete_from_beginning();
    } else {
        struct node *temp = head;
        int i;
        for (i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
    }
}

// search for a node in the list
int search(int data) {
    struct node *temp = head;
    int i = 0;
    while (temp != NULL) {
        if (temp->data == data) {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
}

// menu driven main 
int main() {
    int choice, data, position;
    while (1) {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Search\n");
        printf("8. Print list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
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
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("The position of %d is %d\n", data, search(data));
                break;
            case 8:
                print_list();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}