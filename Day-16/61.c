#include<stdio.h>
int main()
{
    int a[100],i,j,n,sm,sum=0;
    printf("Enter total array elements: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    int N = n + 1;
    sm = (N * (N + 1)) / 2;

    for(j=0;j<n;j++)
    {
        sum+=a[j];
    }
    int m=sm-sum;
    printf("Missing element = %d ",m);
    return 0;
}
