#include <stdio.h>

int main() {
    char str[100];
    int visited[256] = {0}; 
    int i = 0;
    int found = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str); 

    while (str[i] != '\0') {
        int ascii_value = (unsigned char)str[i];

        if (visited[ascii_value] == 1) {
            printf("The first repeating character is: '%c' at index %d\n", str[i], i);
            found = 1;
            break; 
        }

        visited[ascii_value] = 1;
        i++;
    }

    if (!found) {
        printf("No repeating characters found in the string.\n");
    }

    return 0;
}
