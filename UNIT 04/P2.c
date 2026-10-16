
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// a. Insert operation
struct Node* insert(struct Node *root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }
    else if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Find minimum node
struct Node* findMin(struct Node *root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

// b. Delete operation
struct Node* deleteNode(struct Node *root, int value)
{
    struct Node *temp;

    if(root == NULL)
    {
        return root;
    }
    else if(value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if(root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// c. Height of the tree
int height(struct Node *root)
{
    int leftHeight, rightHeight;

    if(root == NULL)
    {
        return 0;
    }

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if(leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}

// d. Total number of nodes
int countNodes(struct Node *root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

// Inorder traversal
void inorder(struct Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("\n %d", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value;

    do
    {
        printf("\n\n--- Binary Search Tree ---");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Height of the tree");
        printf("\n4. Total number of nodes");
        printf("\n5. Inorder traversal");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);

                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                root = deleteNode(root, value);
                break;

            case 3:
                printf("Height of the tree: %d", height(root));
                break;

            case 4:
                printf("Total number of nodes: %d",
                       countNodes(root));
                break;

            case 5:
                printf("Inorder traversal:");
                inorder(root);
                break;

            case 6:
                printf("Exiting...");
                break;

            default:
                printf("Invalid choice!");
        }

    } while(choice != 6);

    return 0;
}
