// write a program with following operations in queue insert delete and display and exit



#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int queue[MAX];
int top = -1;

// Insert operation
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        top++;
        queue[top] = value;
        printf("%d inserted into queue.\n", value);
    }
}
// Delete operation
void delete()
{
    if (top == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[top]);
        top--;
    }
}


// Display operation
void display()
{
    int i;


    if (top == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", queue[i]);
        }
    }
}
int main()
{
    int choice, value, position;
    while (1)
    {
        printf("\n===== QUEUE MENU =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                delete();
                break;

            case 3:
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0 ;
}
