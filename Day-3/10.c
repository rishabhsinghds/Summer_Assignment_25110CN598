#include <stdio.h>
#include <math.h>

int main() {
    int num1, num2, i, j, isPrime;

    printf("Enter a positive lower range: ");
    scanf("%d", &num1);
    printf("Enter a positive upper range: ");
    scanf("%d", &num2);

    printf("Prime numbers between %d and %d are: ", num1, num2);
    for (i = num1; i <= num2; i++) {
        if (i <= 1) {
            continue;
        }

        isPrime = 1; 

        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = 0; 
                break;      
            }
        }

        
        if (isPrime == 1) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
