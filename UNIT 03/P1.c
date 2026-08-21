#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node
{
    int data;
    struct Node *next;
}*start,*newnode;

void create_ll()
{

    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("enter value");
    scanf("%d",&newnode->data);

    newnode->next=NULL;
     start=newnode;

}

void display()
{
    struct Node * ptr;
    for(ptr=start;ptr->next!=NULL;ptr=ptr->next)
    {
        printf("\n %d",ptr->data);
    }
}
void main()
{
    start=NULL;
    int ch;
    while(1)
    {
        printf("1. create\n");
        printf("2. display\n");
        printf("3. exit\n");

        printf("enter your choice:");
        scanf("\n %d",&ch);
        switch(ch)
        {
            case 1: create_ll();
                    break;

            case 2: display();
                    break;

            case 3: exit(0);
                    break;
            default: printf("wrong choice");
        }
    }
    return 0;
}
