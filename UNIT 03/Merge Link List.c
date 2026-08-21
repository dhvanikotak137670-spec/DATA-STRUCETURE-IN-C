#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start1 = NULL;
struct Node *start2 = NULL;

/* CREATE LINKED LIST 1 */
void create_list1()
{
    int n, i;
    struct Node *newnode, *ptr;

    printf("\nEnter number of nodes for Link List 1: ");
    scanf("%d", &n);

    start1 = NULL;

    for (i = 1; i <= n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter value for node %d: ", i);
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (start1 == NULL)
        {
            start1 = newnode;
        }
        else
        {
            ptr = start1;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = newnode;
        }
    }

    printf("Link List 1 created successfully.\n");
}

/* CREATE LINKED LIST 2 */
void create_list2()
{
    int n, i;
    struct Node *newnode, *ptr;

    printf("\nEnter number of nodes for Link List 2: ");
    scanf("%d", &n);

    start2 = NULL;

    for (i = 1; i <= n; i++)
    {
        newnode = (struct Node *)malloc(sizeof(struct Node));

        if (newnode == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter value for node %d: ", i);
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (start2 == NULL)
        {
            start2 = newnode;
        }
        else
        {
            ptr = start2;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = newnode;
        }
    }

    printf("Link List 2 created successfully.\n");
}

/* MERGE TWO LINKED LISTS */
void merge()
{
    struct Node *ptr;

    if (start1 == NULL)
    {
        start1 = start2;
        start2 = NULL;

        printf("\nBoth lists merged successfully.\n");
        return;
    }

    if (start2 == NULL)
    {
        printf("\nLink List 2 is empty.\n");
        return;
    }

    ptr = start1;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = start2;

    start2 = NULL;

    printf("\nBoth lists merged successfully.\n");
}

/* DISPLAY LINKED LIST 1 */
void display_list1()
{
    struct Node *ptr;

    if (start1 == NULL)
    {
        printf("\nLink List 1 is empty.\n");
        return;
    }

    ptr = start1;

    printf("\nLink List 1: ");

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

/* DISPLAY LINKED LIST 2 */
void display_list2()
{
    struct Node *ptr;

    if (start2 == NULL)
    {
        printf("\nLink List 2 is empty.\n");
        return;
    }

    ptr = start2;

    printf("\nLink List 2: ");

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

/* MAIN FUNCTION */
int main()
{
    int ch;

    while (1)
    {
        printf("\n========== LINKED LIST MENU ==========\n");
        printf("1. Create Link List 1\n");
        printf("2. Create Link List 2\n");
        printf("3. Merge Both Link Lists\n");
        printf("4. Display Link List 1\n");
        printf("5. Display Link List 2\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                create_list1();
                break;

            case 2:
                create_list2();
                break;

            case 3:
                merge();
                break;

            case 4:
                display_list1();
                break;

            case 5:
                display_list2();
                break;

            case 6:
                exit(0);

            default:
                printf("\nWrong choice!\n");
        }
    }

    return 0;
}
