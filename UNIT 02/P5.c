#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop operation
int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return 1;
    }
    return stack[top--];
}

int main()
{
    int base, exponent, i;
    long long power = 1;

    printf("Enter the base: ");
    scanf("%d", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    // Push the base into the stack exponent times
    for(i = 1; i <= exponent; i++)
    {
        push(base);
    }

    // Pop each element and multiply
    while(top != -1)
    {
        power = power * pop();
    }

    printf("%d ^ %d = %lld\n", base, exponent, power);

    return 0;
}
