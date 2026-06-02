#include<stdio.h>
int main()
{
    int num,pow,ans=1;
    printf("Enter the number and then its power:");
    scanf("%d%d",&num,&pow);
    for(int i=0;i<pow;i++)
    {
        ans=ans*num;
    }
    printf("%d",ans);
    return 0;
}