#include<stdio.h>
int main()
{int num,rev=0,n,d;
printf("Enter the number:");
scanf("%d",&num);
n=num;
while(num>0)
{
 d=num%10;
 rev=rev*10+d;
 num=num/10;   
}
if(n==rev)
{
    printf("The given number is palindrome");
}
else
{
    printf("The given number is not palindrome");
}
return 0;
}