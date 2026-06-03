#include<stdio.h> 

int fact(int n) { 
    if(n==0 || n==1) { 
        return 1; 
    } else { 
        return n * fact(n-1); 
    } 
} 

int main() { 
    int num; 
    printf("Enter the number:"); 
    scanf("%d",&num); 
    
    if(num < 0) { 
        printf("Error! Factorial of a negative number doesn't exist.\n"); 
    } else { 
        unsigned long long d = fact(num); 
        printf("The factorial of number %d is = %llu", num, d); 
    } 
    return 0; 
}
