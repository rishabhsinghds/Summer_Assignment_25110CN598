#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];
    int visited[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }

    printf("\nDuplicate elements in the array are:\n");
    int found_duplicate = 0;

    for (int i = 0; i < n; i++) {
        
        if (visited[i] == 1) {
            continue;
        }

        int is_counted = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                is_counted = 1;
                visited[j] = 1; 
            }
        }
        if (is_counted == 1) {
            printf("%d ", arr[i]);
            found_duplicate = 1;
        }
    }

    if (!found_duplicate) {
        printf("None");
    }
    printf("\n");

    return 0;
}
