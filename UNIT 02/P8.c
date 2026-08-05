#include <stdio.h>

void findMinMax(int arr[], int size, int index, int *min, int *max)
{
    // Base case
    if (index == size)
        return;

    // Update minimum
    if (arr[index] < *min)
        *min = arr[index];

    // Update maximum
    if (arr[index] > *max)
        *max = arr[index];

    // Recursive call
    findMinMax(arr, size, index + 1, min, max);
}

int main()
{
    int arr[100], n, i;
    int min, max;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    min = max = arr[0];

    findMinMax(arr, n, 0, &min, &max);

    printf("Minimum element = %d\n", min);
    printf("Maximum element = %d\n", max);

    return 0;
}
