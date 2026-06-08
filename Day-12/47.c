#include<stdio.h>
void fib(int n)
{
    int a=0,b=1,temp,i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a);
        temp=a+b;
        a=b;
        b=temp;
    }
}
int main()
{
    int num;
    printf("Enter the number of terms up to which you need fibonacci series : ");
    scanf("%d",&num);
    fib(num);
    return 0;
}