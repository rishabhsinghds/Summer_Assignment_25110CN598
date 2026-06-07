#include<stdio.h>
int sum(int a,int b)
{
    return a+b;
}
int main()
{
    int num1,num2;
    printf("Enter first number:");
    scanf("%d",&num1);
    printf("Enter second number:");
    scanf("%d",&num2);
    printf("Sum of given two numbers = %d",sum(num1,num2));
    return 0;
}