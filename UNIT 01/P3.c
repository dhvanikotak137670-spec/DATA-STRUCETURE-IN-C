void main()
{
    int a[10],i,sum;
    float average;
    printf("Enter any 10 values of your choice:");
    sum=0;
    for(i=0;i<=9;i++)
    {
        scanf("%d",&a[i]);
        sum=sum+a[i];
    }
    average=sum/10.0;

    printf("sum = %d\n",sum);
    printf("average = %f",average);
    getch();
}
