#include <stdio.h>

#define MAX_SIZE 100

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];
    int choice, i, j, len1, len2;

    printf("=========================================\n");
    printf("       STRING OPERATIONS WORKBENCH       \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- STRING MENU -------------\n");
        printf("1. Find Length of a String\n");
        printf("2. Reverse a String\n");
        printf("3. Concatenate Two Strings\n");
        printf("4. Copy One String to Another\n");
        printf("5. Exit System\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("\nExiting String Operations System. Goodbye!\n");
            return 0;
        }

        if (choice < 1 || choice > 5) {
            printf("❌ Invalid selection! Please choose an option between 1 and 5.\n");
            continue;
        }

        while (getchar() != '\n');

        printf("\nEnter the primary string: ");
        scanf("%[^\n]", str1);

        switch (choice) {
            case 1: 
                len1 = 0;
                while (str1[len1] != '\0') {
                    len1++;
                }
                printf("📏 Length of the string = %d characters\n", len1);
                break;

            case 2:
                len1 = 0;
                while (str1[len1] != '\0') {
                    len1++;
                }
                
                
                i = 0;
                j = len1 - 1;
                while (i < j) {
                    char temp = str1[i];
                    str1[i] = str1[j];
                    str1[j] = temp;
                    i++;
                    j--;
                }
                printf("🔄 Reversed String: %s\n", str1);
                break;

            case 3: 
                
                while (getchar() != '\n');
                printf("Enter the string to append: ");
                scanf("%[^\n]", str2);

                
                i = 0;
                while (str1[i] != '\0') {
                    i++;
                }

                
                j = 0;
                while (str2[j] != '\0') {
                    str1[i] = str2[j];
                    i++;
                    j++;
                }
                str1[i] = '\0'; 
                printf("🔗 Concatenated String: %s\n", str1);
                break;

            case 4: 
                i = 0;
                while (str1[i] != '\0') {
                    str2[i] = str1[i];
                    i++;
                }
                str2[i] = '\0'; 

                printf("📋 Copied String into target buffer: %s\n", str2);
                break;
        }
    }

    return 0;
}
