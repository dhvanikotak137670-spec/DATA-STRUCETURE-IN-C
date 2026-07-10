int main()
{
    int A[10], i, largest;

    printf("Enter 10 numbers:\n");

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &A[i]);
    }

    largest = A[0];

    for (i = 1; i < 10; i++)
    {
        if (A[i] > largest)
        {
            largest = A[i];
        }
    }

    printf("Largest value = %d", largest);

    return 0;
}
