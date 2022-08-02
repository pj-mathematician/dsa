#include <stdio.h>
#include <stdlib.h>

// implementation of AVL tree in C with insertion, deletion, search and inorder traversal


struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *root = NULL;

void insert(int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 0;
    if (root == NULL) {
        root = new_node;
    } else {
        struct node *temp = root;
        struct node *parent;
        while (1) {
            parent = temp;
            if (data < temp->data) {
                temp = temp->left;
                if (temp == NULL) {
                    parent->left = new_node;
                    break;
                }
            } else {
                temp = temp->right;
                if (temp == NULL) {
                    parent->right = new_node;
                    break;
                }
            }
        }
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void print_tree(struct node *root) {
    int h = height(root);
    int i;
    for (i = 0; i < h; i++) {
        print_level(root, i);
        printf("\n");
    }
}

void print_level(struct node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 0)
        printf("%d ", root->data);
    else if (level > 0) {
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }
}

// menu driven program
int main()
{
    int choice;
    int data;
    while (1) {
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Print Tree\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                inorder(root);
                printf("\n");
                break;
            case 3:
                preorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter data: ");
                scanf("%d", &data);
                search(data);
                break;
            case 6:
                print_tree(root);
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
