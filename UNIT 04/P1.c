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
struct node* insert(struct Node *root,int value)
{
    if(root==NULL)
    {
        return createNode(value);
    }
    else if(value< root->data)
    {
        root->left= insert(root->left,value);
    }
    else if(value > root->data)
    {
        root->right=insert(root->right,value);
    }
    return root;
}
void preorder(struct Node *root)
{
    if(root != NULL)
    {
        printf("\n %d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Node *root)
{
    if(root != NULL)
    {

        inorder(root->left);
        printf("\n %d", root->data);
        inorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if(root != NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("\n %d", root->data);
    }
}
void main()
{
    struct Node *root=NULL;

    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,70);
    root=insert(root,60);

    printf("preorder traversal: ");
    preorder(root);

    printf("\n inorder traversal:");
    inorder(root);

     printf("\n postorder traversal:");
     postorder(root);
}
