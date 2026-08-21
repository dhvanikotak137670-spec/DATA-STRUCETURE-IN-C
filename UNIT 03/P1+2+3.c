#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Create Linked List */
void create()
{
    int n, i, value;
    struct Node *newNode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

/* Display Linked List */
void display()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Insert at Starting */
void insertBeginning()
{
    int value;
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at beginning.\n");
}

/* Insert at End */
void insertEnd()
{
    int value;
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted at end.\n");
}

/* Insert After Specific Node */
void insertAfter()
{
    int key, value;
    struct Node *temp, *newNode;

    printf("Enter node after which you want to insert: ");
    scanf("%d", &key);

    temp = head;

    while(temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Node not found.\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted after %d.\n", key);
}

/* Insert Before Specific Node */
void insertBefore()
{
    int key, value;
    struct Node *temp, *prev, *newNode;

    printf("Enter node before which you want to insert: ");
    scanf("%d", &key);

    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    /* If inserting before first node */
    if(head->data == key)
    {
        insertBeginning();
        return;
    }

    prev = NULL;
    temp = head;

    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Node not found.\n");
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = temp;
    prev->next = newNode;

    printf("Node inserted before %d.\n", key);
}

/* Main Function */
int main()
{
    int choice;

    while(1)
    {
        printf("\n----- SINGLY LINKED LIST -----\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert After Specific Node\n");
        printf("6. Insert Before Specific Node\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
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
                insertBefore();
                break;

            case 7:
                printf("Program ended.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
