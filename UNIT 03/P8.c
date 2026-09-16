#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *start = NULL;


void create()
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("ENTER THE VALUE: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = start;

    if (start != NULL)
    {
        start->prev = newnode;
    }

    start = newnode;

    printf("Node created successfully.\n");
}


void insertBeginning()
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("ENTER THE VALUE: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = start;

    if (start != NULL)
    {
        start->prev = newnode;
    }

    start = newnode;

    printf("Node inserted at the beginning.\n");
}


void insertEnd()
{
    struct Node *newnode;
    struct Node *ptr;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("ENTER THE VALUE: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;


    if (start == NULL)
    {
        newnode->prev = NULL;
        start = newnode;
        printf("Node inserted at the end.\n");
        return;
    }

    ptr = start;


    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newnode;
    newnode->prev = ptr;

    printf("Node inserted at the end.\n");
}


void insertAfter()
{
    struct Node *newnode;
    struct Node *ptr;
    int value;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("ENTER THE VALUE AFTER WHICH YOU WANT TO INSERT: ");
    scanf("%d", &value);

    ptr = start;


    while (ptr != NULL && ptr->data != value)
    {
        ptr = ptr->next;
    }


    if (ptr == NULL)
    {
        printf("Node not found.\n");
        return;
    }

    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("ENTER THE VALUE TO INSERT: ");
    scanf("%d", &newnode->data);

    newnode->prev = ptr;
    newnode->next = ptr->next;

    if (ptr->next != NULL)
    {
        ptr->next->prev = newnode;
    }

    ptr->next = newnode;

    printf("Node inserted successfully.\n");
}


void display()
{
    struct Node *ptr;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");

    for (ptr = start; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->data);
    }

    printf("\n");
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n----- DOUBLY LINKED LIST -----\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert at beginning\n");
        printf("4. Insert at end\n");
        printf("5. Insert after specific node\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                insertBeginning();
                break;

            case 4:
                insertEnd();
                break;

            case 5:
                insertAfter();
                break;

            case 6:
                exit(0);

            default:
                printf("Wrong choice!\n");
        }
    }

    return 0;
}
