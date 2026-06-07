#include<stdio.h>
#include<math.h>
void checkprime(int n)
{
    int isprime=1;
    if(n<=1)
    {
        printf("enter a positive number greater than 1");
    }
    else
    {
        for(int i=2;i<=sqrt(n);i++)
     {
        if(n%i==0)
        {
            isprime=0;
            break;
        }
     }
    }
    if(isprime==1)
    {
        printf("Given number is prime");
    }
    else
    {
        printf("Given number is not prime");
    }

}
int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d",&num);
    checkprime(num);
    return 0;
}