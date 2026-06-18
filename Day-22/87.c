#include <stdio.h>

int main() {
    char str[100];
    int freq[256] = {0}; 
    int i = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str); 

    while (str[i] != '\0') {
        int ascii_value = (unsigned char)str[i];
        freq[ascii_value]++;
        i++;
    }

    printf("\n--- Character Frequencies ---\n");
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c' occurs %d time(s)\n", i, freq[i]);
        }
    }

    return 0;
}
