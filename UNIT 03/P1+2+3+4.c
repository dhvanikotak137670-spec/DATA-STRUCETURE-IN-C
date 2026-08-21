#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;

/* CREATE LINKED LIST */
void create_list()
{
    int n, i;
    struct Node *newnode, *ptr;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of nodes.\n");
        return;
    }

    start = NULL;

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

        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            ptr = start;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = newnode;
        }
    }

    printf("Linked list created successfully.\n");
}

/* INSERT AT BEGINNING */
void insert_begin()
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->next = start;
    start = newnode;

    printf("Node inserted at beginning.\n");
}

/* INSERT AT END */
void insert_end()
{
    struct Node *newnode, *ptr;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        ptr = start;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = newnode;
    }

    printf("Node inserted at end.\n");
}

/* INSERT AFTER SPECIFIC NODE */
void insert_after()
{
    struct Node *newnode, *ptr;
    int value;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &newnode->data);

    printf("Enter the value after which you want to insert: ");
    scanf("%d", &value);

    ptr = start;

    while (ptr != NULL && ptr->data != value)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Node %d not found.\n", value);
        free(newnode);
        return;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;

    printf("Node inserted after %d.\n", value);
}

/* INSERT BEFORE SPECIFIC NODE */
void insert_before()
{
    struct Node *new_node, *ptr, *preptr;
    int val, num;

    new_node = (struct Node *)malloc(sizeof(struct Node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &val);

    new_node->data = val;

    printf("Enter the value before which you want to insert: ");
    scanf("%d", &num);

    ptr = start;

    if (ptr == NULL)
    {
        printf("List is empty.\n");
        free(new_node);
        return;
    }

    if (ptr->data == num)
    {
        new_node->next = ptr;
        start = new_node;

        printf("Node inserted before %d.\n", num);
        return;
    }

    preptr = ptr;

    while (ptr != NULL && ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Node %d not found.\n", num);
        free(new_node);
        return;
    }

    preptr->next = new_node;
    new_node->next = ptr;

    printf("Node inserted before %d.\n", num);
}

/* DELETE FIRST NODE */
void delete_first()
{
    struct Node *ptr;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    ptr = start;
    start = start->next;

    free(ptr);

    printf("First node deleted.\n");
}

/* DELETE LAST NODE */
void delete_last()
{
    struct Node *ptr, *preptr;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (start->next == NULL)
    {
        free(start);
        start = NULL;

        printf("Last node deleted.\n");
        return;
    }

    ptr = start;
    preptr = NULL;

    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;

    free(ptr);

    printf("Last node deleted.\n");
}

/* DELETE SPECIFIC NODE */
void delete_specific()
{
    struct Node *ptr, *preptr;
    int value;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter the value to delete: ");
    scanf("%d", &value);

    ptr = start;

    if (ptr->data == value)
    {
        start = ptr->next;
        free(ptr);

        printf("Node %d deleted.\n", value);
        return;
    }

    preptr = ptr;
    ptr = ptr->next;

    while (ptr != NULL && ptr->data != value)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Node %d not found.\n", value);
        return;
    }

    preptr->next = ptr->next;
    free(ptr);

    printf("Node %d deleted.\n", value);
}

/* DELETE NODE BEFORE SPECIFIC NODE */
void delete_before()
{
    struct Node *ptr, *preptr, *prepreptr;
    int value;

    if (start == NULL || start->next == NULL)
    {
        printf("Not enough nodes in the list.\n");
        return;
    }

    printf("Enter the value before which you want to delete: ");
    scanf("%d", &value);

    ptr = start;
    preptr = NULL;
    prepreptr = NULL;

    while (ptr != NULL && ptr->data != value)
    {
        prepreptr = preptr;
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Node %d not found.\n", value);
        return;
    }

    if (preptr == NULL)
    {
        printf("No node exists before %d.\n", value);
        return;
    }

    if (prepreptr == NULL)
    {
        start = ptr;
    }
    else
    {
        prepreptr->next = ptr;
    }

    free(preptr);

    printf("Node before %d deleted.\n", value);
}

/* DELETE NODE AFTER SPECIFIC NODE */
void delete_after()
{
    struct Node *ptr, *temp;
    int value;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter the value after which you want to delete: ");
    scanf("%d", &value);

    ptr = start;

    while (ptr != NULL && ptr->data != value)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Node %d not found.\n", value);
        return;
    }

    if (ptr->next == NULL)
    {
        printf("No node exists after %d.\n", value);
        return;
    }

    temp = ptr->next;
    ptr->next = temp->next;

    free(temp);

    printf("Node after %d deleted.\n", value);
}

/* DISPLAY */
void display()
{
    struct Node *ptr;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    ptr = start;

    printf("Linked List: ");

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
        printf("\n----- Singly Linked List -----\n");
        printf("1. Create linked list\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert after specific node\n");
        printf("5. Insert before specific node\n");
        printf("6. Delete first node\n");
        printf("7. Delete last node\n");
        printf("8. Delete specific node\n");
        printf("9. Delete node before specific node\n");
        printf("10. Delete node after specific node\n");
        printf("11. Display\n");
        printf("12. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                create_list();
                break;

            case 2:
                insert_begin();
                break;

            case 3:
                insert_end();
                break;

            case 4:
                insert_after();
                break;

            case 5:
                insert_before();
                break;

            case 6:
                delete_first();
                break;

            case 7:
                delete_last();
                break;

            case 8:
                delete_specific();
                break;

            case 9:
                delete_before();
                break;

            case 10:
                delete_after();
                break;

            case 11:
                display();
                break;

            case 12:
                exit(0);

            default:
                printf("Wrong choice!\n");
        }
    }

    return 0;
}
