#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct node*prev;
    struct node*next;

}*start,*newnode;


void create()
{
    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("ENTER THE VALUE: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=start;


    if(start!=NULL)
    {
        start->prev=newnode;
    }
    start=newnode;
}

void display()
{
     struct Node * ptr;
    for(ptr=start;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d",ptr->data);
    }
    printf("\n");
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
            case 1: create();
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
