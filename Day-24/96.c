#include <stdio.h>

int main() {

    char str[100]; 
    
    int visited[256] = {0}; 
    int i = 0, j = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str); 

    while (str[i] != '\0') {
        int ascii_value = (unsigned char)str[i];
        
        if (visited[ascii_value] == 0) {
            visited[ascii_value] = 1;
            str[j] = str[i];
            j++;
        }
        i++;
    }
    
    str[j] = '\0'; 

    printf("String after removing duplicates: %s\n", str);
    return 0;
}
