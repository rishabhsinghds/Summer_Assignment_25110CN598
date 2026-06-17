#include <stdio.h>

int main() {
    char str[100];
    int len = 0, i;
    char temp;

    printf("Enter a string: ");
    scanf("%[^\n]", str); 

    while (str[len] != '\0') {
        len++;
    }

    int j = len - 1;
    for (i = 0; i < j; i++) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        
        j--; 
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
