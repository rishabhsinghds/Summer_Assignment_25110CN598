#include <stdio.h>

int main() {
    int a[100], b[100], c[100];
    int n1, n2, n3;
    int i = 0, j = 0, k = 0;
    int found = 0, last_printed = -1;
    
    printf("Enter size of First sorted array: ");
    scanf("%d", &n1);
    printf("Enter First array elements (in sorted order): ");
    for(int x = 0; x < n1; x++) scanf("%d", &a[x]);

    printf("Enter size of Second sorted array: ");
    scanf("%d", &n2);
    printf("Enter Second array elements (in sorted order): ");
    for(int x = 0; x < n2; x++) scanf("%d", &b[x]);

    printf("Enter size of Third sorted array: ");
    scanf("%d", &n3);
    printf("Enter Third array elements (in sorted order): ");
    for(int x = 0; x < n3; x++) scanf("%d", &c[x]);

    printf("\nCommon elements are: ");

    while (i < n1 && j < n2 && k < n3) {
        
       if (a[i] == b[j] && b[j] == c[k]) {
            
            if (found == 0 || a[i] != last_printed) {
                printf("%d ", a[i]);
                last_printed = a[i];
                found = 1;
            }
            i++; j++; k++;
        }
        else if (a[i] < b[j]) {
            i++;
        }
        else if (b[j] < c[k]) {
            j++;
        }
        else {
            k++;
        }
    }

    if (!found) {
        printf("No common elements found.");
    }
    printf("\n");

    return 0;
}
