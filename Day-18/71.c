#include <stdio.h>

int main() {
    int a[100], n, i, target, low, high, mid, found = 0;

    printf("Enter total array elements: ");
    scanf("%d", &n);

    printf("Enter array elements (must be in sorted order): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &target);
    
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = low + (high - low) / 2; 
        if (a[mid] == target) {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        }
        else if (a[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Element not found in the array.\n");
    }

    return 0;
}
