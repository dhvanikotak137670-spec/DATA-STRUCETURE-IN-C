#include <stdio.h>

int main()
{
    int a[10], i, j, temp;

    printf("Enter 10 elements:\n");
    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    // Sort in ascending order
    for(i = 0; i < 9; i++)
    {
        for(j = i + 1; j < 10; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nArray in ascending order:\n");
    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);

    return 0;
}
