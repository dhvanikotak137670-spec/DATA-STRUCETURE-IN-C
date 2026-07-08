void main()
{
    int a[10],i,s;
    printf("Enter any 10 values of your choice:");

    for(i=0;i<=9;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Entered 10 values are \n");
    for(i=0;i<=9;i++)
    {
        printf("%d",a[i]);
    }
    printf("Enter the value which you want to search");
    scanf("%d",&s);
    for(i=0;i<=9;i++)
    if(s==a[i])
    {
        break;
    }
    if(i==10)
    {
        printf("Value is not found");
    }
    else
    {
        printf("Value is found at the location %d",i+1);
    }
    getch();
}
