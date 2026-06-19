#include <stdio.h>

int main() {
    char str[100];
    int freq[256] = {0}; 
    int i;
    int found = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str); 

    i = 0;
    while (str[i] != '\0') {
        int ascii_value = (unsigned char)str[i];
        freq[ascii_value]++;
        i++;
    }

    i = 0;
    while (str[i] != '\0') {
        int ascii_value = (unsigned char)str[i];
        if (freq[ascii_value] == 1) {
            printf("The first non-repeating character is: '%c' at index %d\n", str[i], i);
            found = 1;
            break; 
        }
        i++;
    }

    if (!found) {
        printf("All characters are repeating or the string is empty.\n");
    }

    return 0;
}
