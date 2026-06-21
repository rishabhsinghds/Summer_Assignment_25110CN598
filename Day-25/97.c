#include <stdio.h>

int main() {
    int a[100], b[100], c[200];
    int n1, n2, n3;
    int i = 0, j = 0, k = 0;

    printf("Enter total elements for First sorted array: ");
    scanf("%d", &n1);
    printf("Enter First array elements (in sorted order): ");
    for (int x = 0; x < n1; x++) {
        scanf("%d", &a[x]);
    }

    printf("Enter total elements for Second sorted array: ");
    scanf("%d", &n2);
    printf("Enter Second array elements (in sorted order): ");
    for (int x = 0; x < n2; x++) {
        scanf("%d", &b[x]);
    }

    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        c[k] = a[i];
        i++;
        k++;
    }

    while (j < n2) {
        c[k] = b[j];
        j++;
        k++;
    }

    n3 = n1 + n2; 

    printf("\nMerged sorted array elements: ");
    for (int x = 0; x < n3; x++) {
        printf("%d ", c[x]);
    }
    printf("\nTotal merged size = %d\n", n3);

    return 0;
}
