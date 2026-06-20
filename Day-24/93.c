#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp[200];
    int len1, len2;

    printf("Enter First string: ");
    scanf("%[^\n]", str1);
    
    while (getchar() != '\n'); 

    printf("Enter Second string: ");
    scanf("%[^\n]", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (len1 != len2) {
        printf("\nThe strings are NOT rotations of each other.\n");
        return 0;
    }

    strcpy(temp, str1);
    strcat(temp, str1);


    if (strstr(temp, str2) != NULL) {
        printf("\nThe strings are rotations of each other.\n");
    } else {
        printf("\nThe strings are NOT rotations of each other.\n");
    }

    return 0;
}
