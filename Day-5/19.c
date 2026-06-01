#include<stdio.h> 
#include<math.h> 

int main() { 
    int num, i, n, isprime; 
    printf("Enter the number: "); 
    scanf("%d", &num); 
    
    n = num; 
    for(i = 2; i <= n; i++) { 
        if(num % i == 0) { 
            isprime = 1; 
            for(int j = 2; j <= sqrt(i); j++) { 
                if(i % j == 0) { 
                    isprime = 0; 
                    break; 
                } 
            } 
            if(isprime == 1) { 
                while(num % i == 0) { 
                    printf("%d\t", i); 
                    num = num / i; 
                } 
            } 
        } 
    } 
    return 0; 
}
