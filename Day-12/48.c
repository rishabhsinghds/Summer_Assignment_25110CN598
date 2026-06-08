#include<stdio.h>
void perfect(int n)
{
    int i,sum=0;
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum=sum+i;
        }
    }
    if(sum==n)
    {
        printf("Entered number is a perfect number");
    }
    else
    {
        printf("Entered number is not a perfect number");
    }
}
int main()
{
    int num;
    printf("Entered the number: ");
    scanf("%d",&num);
    perfect(num);
    return 0;
}