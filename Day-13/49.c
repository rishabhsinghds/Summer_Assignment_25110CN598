#include<stdio.h>
int main()
{
    int a[100],i,j,n;
    printf("Enter total array elements: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Here is the inputed array\n");
    for(j=0;j<n;j++)
    {
        printf("%d\t",a[j]);
    }
    return 0;
}