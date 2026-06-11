#include <stdio.h>

int main() {
    int a[100], i, j, n, temp;
    
    printf("Enter total array elements: ");
    scanf("%d", &n);
    
    printf("Enter array elements: \n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
 
    for(j = 0; j < n / 2; j++) {
        temp = a[j];
        a[j] = a[n - j - 1];
        a[n - j - 1] = temp;
    }
    
    printf("Reversed array: \n");
    for(int k = 0; k < n; k++) {
        printf("%d\t", a[k]);
    }
    
    return 0;
}
