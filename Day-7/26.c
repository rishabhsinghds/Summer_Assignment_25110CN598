#include<stdio.h>

int fib(int n)
{
    if(n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}

int main() { 
    int num; 
    printf("Enter the number of terms: "); 
    scanf("%d", &num); 
    
    if(num < 0) { 
        printf("Error! Fibonacci of a negative number doesn't exist.\n"); 
    } else { 
        for(int i = 0; i < num; i++) {
            int d = fib(i); 
            printf("%d\t", d); 
        }
    } 
    return 0; 
}
