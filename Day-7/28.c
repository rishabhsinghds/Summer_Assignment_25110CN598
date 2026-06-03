#include<stdio.h>
#include<math.h>
int count(int x)
{   
    int c=0;
    while(x>0)
    {  
        x=x/10;
        c ++;
    }
    return c;
}
int rev(int n)
{
    if (n==0)
    return 0;
    else
    return (n%10)*pow(10,count(n)-1) + rev(n/10);
}
int main()
{
    int num;
    printf("Enter the number:");
    scanf("%d",&num);
    printf("Reverse number = %d",rev(num));
    return 0;
}