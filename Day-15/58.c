#include <stdio.h> 

int main() { 
    int a[100], i, n, m, temp; 
    
    printf("Enter total array elements: "); 
    scanf("%d", &n); 
    
    printf("Enter array elements: \n"); 
    for(i = 0; i < n; i++) { 
        scanf("%d", &a[i]); 
    } 
    
    printf("Enter total number of places to rotate array elements: "); 
    scanf("%d", &m); 
    m = m % n; 
    
    if (m > 0) {
        // Step 1: Reverse the first n-m elements
        for(i = 0; i < (n - m)/2; i++) { 
            temp = a[i]; 
            a[i] = a[n - m - i - 1]; 
            a[n - m - i - 1] = temp; 
        } 
        
        // Step 2: Reverse the remaining m elements
        for(i = 0; i < m/2; i++) { 
            temp = a[n - m + i]; 
            a[n - m + i] = a[n - i - 1]; 
            a[n - i - 1] = temp; 
        } 
        
        // Step 3: Reverse the entire array
        for(i = 0; i < n/2; i++) { 
            temp = a[i]; 
            a[i] = a[n - i - 1]; 
            a[n - i - 1] = temp; 
        }
    }
    
    printf("Left Rotated array: \n"); 
    for(int k = 0; k < n; k++) { 
        printf("%d\t", a[k]); 
    } 
    printf("\n");
    
    return 0; 
}
