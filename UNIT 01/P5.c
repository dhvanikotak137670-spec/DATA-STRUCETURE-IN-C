int main()
{
    int A[3] = {1, 2, 3};
    int B[3] = {4, 5, 6};
    int C[6];
    int i;

    // Copy A into C
    for (i = 0; i < 3; i++)
    {
        C[i] = A[i];
    }

    // Copy B into C
    for (i = 0; i < 3; i++)
    {
        C[i + 3] = B[i];
    }

    // Display merged array
    printf("Merged Array C: ");
    for (i = 0; i < 6; i++)
    {
        printf("%d ", C[i]);
    }

    return 0;
}
