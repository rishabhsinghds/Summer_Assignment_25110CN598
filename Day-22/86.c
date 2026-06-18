#include <stdio.h>

int main() {
    char str[200];
    int i = 0, words = 0;
    int in_word = 0;

    printf("Enter a sentence: ");
    scanf("%[^\n]", str); 

    while (str[i] != '\0') {
        
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            in_word = 0; 
        } 
        else if (in_word == 0) {
            in_word = 1; 
            words++;     
        }
        
        i++; 
    }

    printf("Total number of words = %d\n", words);

    return 0;
}
