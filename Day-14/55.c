#include <stdio.h>

int main() {
    int a[100], i, j, n, temp;
    
    printf("Enter total array elements: ");
    scanf("%d", &n);
    
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    //Bubble Sort
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    // Find the second largest element while ignoring duplicate maximums
    int second_largest = a[n-2];
    for(i = n - 2; i >= 0; i--) {
        if(a[i] < a[n-1]) {
            second_largest = a[i];
            break;
        }
    }
    
    printf("Second largest element of array is %d\n", second_largest);
    return 0;
}
