#include<stdio.h>
int main()
{
    int num ,count=0,i;
    printf("Enter the number:");
    scanf("%d",&num);
    for(i=1;i<num;i++)
    {
        if(num%i==0)
        { 
          count=count+i;
        }
    }
    if(count==num)
        {
            printf("Given number is perfect number");
        }
    else
    {
        printf("Given number is not a perfect number");
    }
    return 0;
}