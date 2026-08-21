#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// 1. Create a linked list
struct Node* createList(int n) {
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode;
    int i, value;

    for (i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &value);

        newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

// 2. Display the linked list
void display(struct Node *head) {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// 3. Insert a node at the beginning
struct Node* insertBeginning(struct Node *head, int value) {
    struct Node *newNode;

    newNode = createNode(value);

    newNode->next = head;
    head = newNode;

    return head;
}

// 4. Insert a node at the end
struct Node* insertEnd(struct Node *head, int value) {
    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(value);

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    temp = head;

    // Go to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

int main()
{
    struct Node *head = NULL;
    int n, choice, value;

    // Create the linked list
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    while (1) {
        printf("\n========== MENU ==========\n");
        printf("1. Display List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Exit\n");
        printf("==========================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                display(head);
                break;

            case 2:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);

                head = insertBeginning(head, value);

                printf("Node inserted at beginning.\n");
                break;

            case 3:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);

                head = insertEnd(head, value);

                printf("Node inserted at end.\n");
                break;

            case 4:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
