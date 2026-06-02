#include<stdio.h>
#include<math.h>
int main()
{
    int num,d,i=0,r=0;
    printf("Enter the binary number:");
    scanf("%d",&num);
    if(num==0)
    {
        printf("%d",0);
        return 0;
    }
    while(num>0)
    {
        d=num%10;
        r+=d*pow(2,i);
        num=num/10;
        i++;
    }
    printf("%d",r);
    return 0;
}