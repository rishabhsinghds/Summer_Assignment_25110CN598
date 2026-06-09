#include<stdio.h>
int main()
{
    int a[100],i,j,n,sum=0;
    printf("Enter total array elements: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0;j<n;j++)
    {
        sum+=a[j];
    }
   float avg = (float)sum / n ;
    printf("Here is the sum of inputed array: %d\n",sum);
    printf("Here is the average of inputed array: %f",avg);

    return 0;
}