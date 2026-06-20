#include <stdio.h>
#include <string.h>

int main() {
    char str[100], compressed[200];
    int i = 0, j = 0, len;

    printf("Enter a string to compress: ");
    scanf("%[^\n]", str);

    len = strlen(str);

    while (i < len) {
        int count = 1;
        
        while (i + 1 < len && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        compressed[j++] = str[i];

        j += sprintf(&compressed[j], "%d", count);

        i++; 
    }
    
    compressed[j] = '\0'; 

    if (strlen(compressed) < len) {
        printf("Compressed string: %s\n", compressed);
    } else {
        printf("Compression not beneficial. Original string: %s\n", str);
    }

    return 0;
}
