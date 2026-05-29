#include<stdio.h>
int main()
{int num,sum=0,d;
printf("Enter the number:");
scanf("%d",&num);
while(num>0)
{
 d=num%10;
 sum+=d;
 num=num/10;   
}
printf("Here is your sum of digits=%d",sum);
return 0;
}