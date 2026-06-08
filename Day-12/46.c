#include<stdio.h>
#include<math.h>
int countm(int m)
{
    int count=0;
    while(m>0)
    {
        count++;
        m=m/10;
    }
    return count;
}
void armstrong(int n)
{
    int nm=0,d;
    int x=n;
    int cnt=countm(n);
    while(x>0)
    {
        d=x%10;
        nm=nm+ 0.1+(pow(d,cnt));
        x=x/10;
    }
    if(n==nm)
    {
        printf("Entered number is a armstrong number");
    }
    else
    {
        printf("Entered number is not a armstrong number");

    }
}
int main()
{
    int num;
    printf("Entered the number : ");
    scanf("%d",&num);
    armstrong(num);
    return 0;
}