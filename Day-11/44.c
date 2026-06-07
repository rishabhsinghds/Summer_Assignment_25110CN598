#include <stdio.h>

void fact(int n) {
    int fct = 1;
    for (int i = 1; i <= n; i++) {
        fct = fct * i;
    }
    printf("Factorial of number %d is %d\n", n, fct);
}

int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    
    fact(num);
    
    return 0;
}
