#include<stdio.h>
int main()
{
    int a[100],i,j,n,search;
    printf("Enter total array elements: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the search item:");
    scanf("%d",&search);
    //Linear Searching
    for(j=0;j<n;j++)
    {
        if(a[j]==search)
        {
            break;           
        }
    }
    printf("Position of search element =%d",j+1);
    return 0;
}