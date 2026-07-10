int main()
{
    int a[10], n, i, pos, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d%d", &pos, &x);

    for(i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = x;

    for(i = 0; i <= n; i++)
        printf("%d ", a[i]);

    return 0;
}
