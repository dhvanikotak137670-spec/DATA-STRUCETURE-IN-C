#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = ch;
    }
}

// Pop operation
char pop()
{
    if (top == -1)
    {
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    char str[MAX];
    int i;

    printf("Enter a string: ");
    gets(str);

    // Push each character onto the stack
    for (i = 0; i < strlen(str); i++)
    {
        push(str[i]);
    }

    printf("Reversed string: ");

    // Pop and print each character
    while (top != -1)
    {
        printf("%c", pop());
    }

    printf("\n");

    return 0;
}
