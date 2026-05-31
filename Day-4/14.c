#include<stdio.h>
int main()
{
    int a=0,b=1,temp,num;
    printf("Enter the nth number:");
    scanf("%d",&num);
    for(int i=1;i<num;i++)
    {
        temp=a+b;
        a=b;
        b=temp;
    }
    printf("%d",a);
    return 0;
}