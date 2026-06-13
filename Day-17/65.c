#include <stdio.h>

int main() {
    int a[100], b[100], c[200]; 
    int n1, n2, n3;
    int i, j;
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

    n3 = n1 + n2;

    for (i = 0; i < n1; i++) {
        c[i] = a[i];
    }

    for (j = 0; j < n2; j++) {
        c[i] = b[j];
        i++;
    }
    printf("\nMerged array elements: ");
    for (i = 0; i < n3; i++) {
        printf("%d ", c[i]);
    }
    printf("\nTotal merged size = %d\n", n3);

    return 0;
}
