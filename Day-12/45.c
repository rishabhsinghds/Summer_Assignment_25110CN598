#include<stdio.h>
void palindrome(int n)
{
    int rev=0,d;
    int x=n;
    while(x>0)
    {
        d=x%10;
        rev=rev*10 + d;
        x=x/10;
    }
    if(rev==n)
    {
        printf("Entered number is palindrome number");
    }
    else
    {
        printf("Entered number is not a palindrome number");
    }
}
int main()
{
    int num;
    printf("Entered the number : ");
    scanf("%d",&num);
    palindrome(num);
    return 0;
}