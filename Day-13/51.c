#include<stdio.h>
int main()
{
    int a[100],i,j,n,temp;
    printf("Enter total array elements: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //sorting
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    printf("Largest element of array is %d\n",a[n-1]);
    printf("Smallest element of array is %d",a[0]);
    return 0;
}