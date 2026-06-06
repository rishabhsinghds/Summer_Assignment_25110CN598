#include<stdio.h>
int main()
{
    int i,j,k,l,num;
    printf("Enter the number of rows:");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=num;j>i;j--)
        {
            printf(" ");
        }
        for(k=1;k<=i;k++)
        {
            printf("%d",k);
        }
        for(l=2;l<=i;l++)
        {
            printf("%d",i-(l-1));
        }

        printf("\n");
    }
    return 0;
}