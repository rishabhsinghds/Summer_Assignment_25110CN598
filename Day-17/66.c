#include <stdio.h>

int main() {
    int a[100], b[100], union_arr[200];
    int n1, n2, u_size = 0;
    int i, j, exists;
    
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
        for (j = 0; j < u_size; j++) {
            if (a[i] == union_arr[j]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            union_arr[u_size] = a[i];
            u_size++;
        }
    }

    for (i = 0; i < n2; i++) {
        exists = 0;
        for (j = 0; j < u_size; j++) {
            if (b[i] == union_arr[j]) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            union_arr[u_size] = b[i];
            u_size++;
        }
    }

    printf("\nUnion of the two arrays: ");
    for (i = 0; i < u_size; i++) {
        printf("%d ", union_arr[i]);
    }
    printf("\nTotal elements in Union = %d\n", u_size);

    return 0;
}
