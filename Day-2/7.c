#include<stdio.h>
int main()
{int num,prod=1,d;
printf("Enter the number:");
scanf("%d",&num);
while(num>0)
{
 d=num%10;
 prod*=d;
 num=num/10;   
}
printf("Here is your product of digits=%d",prod);
return 0;
}