#include<stdio.h>
#include<math.h>
int main()
{
    int num,n,i,d,nm=0,m,count=0;
    printf("Enter the number:");
    scanf("%d",&num);
    n=num;
    m=num;
    while(m>0)
    {
        m=m/10;
        count++;
    }
    while(n>0)
    {
        d=n%10;
        nm= nm + round(pow(d,count));
        n=n/10;
    }
    if (nm==num)
    {
        printf("Number is armstrong ");
    }
    else
    {
        printf("number is not a armstrong number");
    }
    return 0;
}