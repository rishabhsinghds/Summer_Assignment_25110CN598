#include <stdio.h>

int main() {
    char str[100];
    int len = 0, i, j;
    int is_palindrome = 1; 

    printf("Enter a string: ");
    scanf("%[^\n]", str); 

    while (str[len] != '\0') {
        len++;
    }

    i = 0;          
    j = len - 1;  

    while (i < j) {
        if (str[i] != str[j]) {
            is_palindrome = 0; 
            break;            
        }
        i++; 
        j--; 
    }

    if (is_palindrome) {
        printf("\"%s\" is a Palindrome string.\n", str);
    } else {
        printf("\"%s\" is NOT a Palindrome string.\n", str);
    }

    return 0;
}
