#include<stdio.h>
#include<math.h>

int main() {
    int num, i, n, isprime, count;
    int max_prime ; 
    
    printf("Enter the number: ");
    scanf("%d", &num);
    
    n = num;
    for(i = 2; i <= n; i++) {
        count = 0;
        if(num % i == 0) {
            isprime = 1;
            count = i;
            
            for(int j = 2; j <= sqrt(i); j++) {
                if(i % j == 0) {
                    isprime = 0;
                    break;
                }
            }
            
            if(isprime == 1) {
                max_prime = count; 
            }
        }
    }
    
   
        printf("%d\n", max_prime);
    
    return 0;
}
