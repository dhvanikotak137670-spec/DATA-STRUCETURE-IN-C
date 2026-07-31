#include <stdio.h>

int main()
{
    int num, i;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 1)
    {
        printf("No smallest divisor exists.\n");
        return 0;
    }

    for (i = 2; i <= num; i++)
    {
        if (num % i == 0)
        {
            printf("Smallest Divisor = %d\n", i);
            break;
        }
    }

    return 0;
}
