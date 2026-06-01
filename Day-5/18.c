#include<stdio.h>
int fact(int);

int main()
{   int num,d,sum=0;
    printf("Enter the number:");
    scanf("%d",&num);
    int n=num;
    while(n>0)
    {
        d=n%10;
        sum+=fact(d);
        n=n/10;
    }
    if (sum==num)
    {
        printf("Given number is a strong number");
    }

    return 0;
}

int fact(int num)
{
    int fct=1;
    for(int j=1;j<=num;j++)
    {
        fct=fct*j;
    }
    return fct;
}