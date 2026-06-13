#include <stdio.h>

int main() {
    int a[100], b[100], intersection_arr[100];
    int n1, n2, i_size = 0;
    int i, j, k, exists, already_added;

    printf("Enter total elements for First array: ");
    scanf("%d", &n1);
    printf("Enter First array elements: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter total elements for Second array: ");
    scanf("%d", &n2);
    printf("Enter Second array elements: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    for (i = 0; i < n1; i++) {
        exists = 0;

        for (j = 0; j < n2; j++) {
            if (a[i] == b[j]) {
                exists = 1;
                break;
            }
        }

        if (exists) {
            already_added = 0;
            for (k = 0; k < i_size; k++) {
                if (a[i] == intersection_arr[k]) {
                    already_added = 1;
                    break;
                }
            }

            // Step 3: If it's a unique common element, add it to our results
            if (!already_added) {
                intersection_arr[i_size] = a[i];
                i_size++;
            }
        }
    }
    printf("Intersection of the two arrays: ");
    if (i_size == 0) {
        printf("No common elements found.");
    } else {
        for (i = 0; i < i_size; i++) {
            printf("%d ", intersection_arr[i]);
        }
        printf("\nTotal elements in Intersection = %d\n", i_size);
    }

    return 0;
}
