#include <stdio.h>

int main() {
    int a[100], n, i, j, target_sum;
    int found = 0;

    printf("Enter total array elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target_sum);

    printf("\nPairs with sum %d are:\n", target_sum);

    for (i = 0; i < n - 1; i++) {
        
    
        for (j = i + 1; j < n; j++) {
           
            if (a[i] + a[j] == target_sum) {
                printf("Pair found: (%d, %d)\n", a[i], a[j]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No pair found with the given sum.\n");
    }

    return 0;
}