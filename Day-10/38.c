#include<stdio.h>
int main()
{
    int i,j,k,num;
    printf("Enter the number of rows:");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf(" ");
        }
        for(k=i;k<=2*num-i;k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}