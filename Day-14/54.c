#include<stdio.h>
int main()
{
    int a[100],i,j,n,item,count=0;
    printf("Enter total array elements: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter array elements to find its frequency: ");
    scanf("%d",&item);
    for(j=0;j<n;j++)
    {
        if(a[j]==item)
        {
            count++;           
        }
    }
    printf("Frequency of entered element =%d",count);
    return 0;
}