#include <stdio.h>
#include <stdlib.h>

// Structure of a binary search tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Preorder traversal: Root, Left, Right
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal: Left, Root, Right
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Postorder traversal: Left, Right, Root
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to free allocated memory
void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function
int main(void) {
    struct Node *root = NULL;
    int n, value, i;

    printf("Enter the number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);

        if (scanf("%d", &value) != 1) {
            printf("Invalid input!\n");
            freeTree(root);
            return 1;
        }

        root = insert(root, value);
    }

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");

    freeTree(root);
    return 0;
}
