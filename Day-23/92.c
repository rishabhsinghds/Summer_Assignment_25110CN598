#include <stdio.h>

int main() {
    char str[100];
    int freq[256] = {0}; 
    int i = 0;
    int max_count = 0;
    char max_char;

    printf("Enter a string: ");
    scanf("%[^\n]", str); 

    while (str[i] != '\0') {
        freq[(unsigned char)str[i]]++;
        i++;
    }

    for (i = 0; i < 256; i++) {
        if (i != ' ' && freq[i] > max_count) {
            max_count = freq[i];
            max_char = (char)i;
        }
    }

    if (max_count > 0) {
        printf("\nMaximum occurring character = '%c'\n", max_char);
        printf("It appears %d time(s)\n", max_count);
    } else {
        printf("The string is empty.\n");
    }

    return 0;
}
