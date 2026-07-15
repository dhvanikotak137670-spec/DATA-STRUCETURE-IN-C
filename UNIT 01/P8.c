#include <stdio.h>

int main()
{
    int a[10], i, j, pos, temp, n = 10;

    printf("Enter 10 elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter position to delete (1-10): ");
    scanf("%d", &pos);

    // Delete element
    for(i = pos - 1; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;

    // Sort in ascending order
    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

    printf("\nArray after deletion and sorting:\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
