#include<stdio.h>
int main()
{
    int a=0,b=1,temp,num;
    printf("Enter the number up to which you want to generate the fibonacci series:");
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {
        printf("%d",a);
        temp=a+b;
        a=b;
        b=temp;
        printf("\t");
    }
    return 0;
}