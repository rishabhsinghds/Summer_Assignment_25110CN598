#include<stdio.h>
#include<math.h>
int main()
{
    int num1,num2,n,i,d,nm=0,m,count=0,k;
    printf("Enter the range:");
    scanf("%d%d",&num1,&num2);
    for(int i=num1;i<=num2;i++)
    {
    n=i;
    m=i;
    k=i;
    nm=0;
    count=0;
    while(m>0)
    {
        m=m/10;
        count++;
    }
    while(n>0)
    {
        d=n%10;
        nm= nm + round(pow(d,count));
        n=n/10;
    }
    if (nm==k)
    {
        printf("%d\t",k);
    }
   
}
    return 0;
}