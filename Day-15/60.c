#include <stdio.h>

int main() {
    int a[100], i, n;
    int count = 0; 
    
    printf("Enter total array elements: ");
    scanf("%d", &n);
    
    printf("Enter array elements: \n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
 
    for(i = 0; i < n; i++) {
        if(a[i] != 0) {
            a[count] = a[i];
            count++;
        }
    }
    
    while(count < n) {
        a[count] = 0;
        count++;
    }
    
    printf("Required array: \n");
    for(int k = 0; k < n; k++) {
        printf("%d\t", a[k]);
    }
    printf("\n");
    
    return 0;
}
