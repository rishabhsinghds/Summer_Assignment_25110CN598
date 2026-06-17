#include <stdio.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0, i = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str); 

    while (str[i] != '\0') {
        char ch = str[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            
            if (ch >= 'A' && ch <= 'Z') {
                ch = ch + 32; 
            }

           
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++; 
            }
        }
        i++; 
    }

    printf("\nTotal Vowels = %d\n", vowels);
    printf("Total Consonants = %d\n", consonants);

    return 0;
}
