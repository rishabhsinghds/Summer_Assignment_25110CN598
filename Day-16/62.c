#include <stdio.h>

int main() {
    int a[100], n, i, j;
    int max_element, max_count = 0;

    printf("Enter total array elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        int count = 0;
        
        for (j = 0; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
            }
        }

        if (count > max_count) {
            max_count = count;
            max_element = a[i];
        }
    }

    printf("\nElement with maximum frequency = %d\n", max_element);
    printf("Frequency = %d times\n", max_count);

    return 0;
}
