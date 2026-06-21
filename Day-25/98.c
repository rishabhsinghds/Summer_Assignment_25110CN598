#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int present_in_str1[256] = {0};
    int present_in_str2[256] = {0};
    int i, found = 0;

    printf("Enter First string: ");
    scanf("%[^\n]", str1);
    
    while (getchar() != '\n'); 

    printf("Enter Second string: ");
    scanf("%[^\n]", str2);

    i = 0;
    while (str1[i] != '\0') {
        if (str1[i] != ' ') {
            present_in_str1[(unsigned char)str1[i]] = 1;
        }
        i++;
    }

    i = 0;
    while (str2[i] != '\0') {
        if (str2[i] != ' ') {
            present_in_str2[(unsigned char)str2[i]] = 1;
        }
        i++;
    }

    printf("\nCommon characters are: ");
    for (i = 0; i < 256; i++) {
        if (present_in_str1[i] == 1 && present_in_str2[i] == 1) {
            printf("%c ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");

    return 0;
}
