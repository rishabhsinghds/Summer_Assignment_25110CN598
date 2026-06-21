#include <stdio.h>
#include <string.h>

int main() {
    char names[100][50];
    char temp[50];
    int n, i, j;

    printf("Enter total number of names: ");
    scanf("%d", &n);

    while (getchar() != '\n'); 

    printf("Enter %d names:\n", n);
    for (i = 0; i < n; i++) {
        printf("Name %d: ", i + 1);
        scanf("%[^\n]", names[i]);
        while (getchar() != '\n'); 
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("\nNames in alphabetical order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
