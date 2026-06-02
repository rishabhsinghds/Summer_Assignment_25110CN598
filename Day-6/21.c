#include<stdio.h>
int main()
{
    int num,d,r[100],i=0,j;
    printf("Enter the decimal number:");
    scanf("%d",&num);
    if (num == 0) {
        printf("0");
        return 0;
    }

    while(num>0)
    {
        d=num%2;
        r[i]=d;
        num=num/2;
        i++;
    }
    for(j=i-1;j>=0;j--)
    {
        printf("%d",r[j]);
    }
    return 0;
}
