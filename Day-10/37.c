#include<stdio.h>
int main()
{
    int i,j,k,num;
    printf("Enter the number of rows:");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=num;j>i;j--)
        {
            printf(" ");
        }
        for(k=1;k<=2*i-1;k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}