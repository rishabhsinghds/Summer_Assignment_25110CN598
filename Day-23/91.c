#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int freq[256] = {0}; 
    int i = 0, is_anagram = 1;

    printf("Enter First string: ");
    scanf("%[^\n]", str1);
    
    while (getchar() != '\n'); 

    printf("Enter Second string: ");
    scanf("%[^\n]", str2);

    while (str1[i] != '\0') {
        freq[(unsigned char)str1[i]]++;
        i++;
    }

    i = 0;
    while (str2[i] != '\0') {
        freq[(unsigned char)str2[i]]--;
        i++;
    }

    for (i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            is_anagram = 0; 
            break;
        }
    }

    if (is_anagram) {
        printf("\nThe strings are Anagrams.\n");
    } else {
        printf("\nThe strings are NOT Anagrams.\n");
    }

    return 0;
}
