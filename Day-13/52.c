#include<stdio.h>
int main()
{
    int a[100],i,j,n,even=0,odd=0;
    printf("Enter total array elements: ");
    scanf("%d",&n);
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(j=0;j<n;j++)
    {
       if(a[j]%2==0)
       {
        even++;
       }
       else
       {
        odd++;
       }
    }
    printf("Total numbers of even number in array = %d\n",even);
    printf("Total numbers of odd number in array = %d\n",odd);
    return 0;
}