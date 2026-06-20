#include <stdio.h>
#include <string.h>

int main() {
    char str[1000]; 
    int i = 0, curr_len = 0, max_len = 0;
    int curr_start = 0, max_start = 0;

    printf("Enter a sentence: "); 
    scanf("%[^\n]", str);        

    int len = strlen(str);

    for (i = 0; i <= len; i++) {
        
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\0') { 
            if (curr_len > max_len) {
                max_len = curr_len;
                max_start = curr_start;
            }
            curr_len = 0;
        } else {
            if (curr_len == 0) {
                curr_start = i;
            }
            curr_len++;
        }
    }

    printf("\nThe longest word is: "); 
    for (i = max_start; i < max_start + max_len; i++) {
        printf("%c", str[i]);          
    }
    
    printf("\nLength = %d characters\n", max_len); 

    return 0;
}
