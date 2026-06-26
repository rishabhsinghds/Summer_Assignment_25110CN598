#include <stdio.h>

#define MAX_BOOKS 50
#define TITLE_LENGTH 100

int main() {
    char library[MAX_BOOKS][TITLE_LENGTH];
    int count = 0; 
    int choice, i, found;
    char search_title[TITLE_LENGTH];

    printf("=========================================\n");
    printf("           MINI LIBRARY SYSTEM           \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- LIBRARY MENU -------------\n");
        printf("1. Add New Book Title\n");
        printf("2. Display All Books on Shelf\n");
        printf("3. Search for a Book\n");
        printf("4. Exit System\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (count >= MAX_BOOKS) {
                    printf("❌ Error: Mini library shelves are completely full!\n");
                    break;
                }

                while (getchar() != '\n'); 

                printf("\nEnter Book Title: ");
                scanf("%[^\n]", library[count]);

                count++; 
                printf("✅ Book title saved to shelf successfully!\n");
                break;

            case 2: 
                if (count == 0) {
                    printf("\n📭 The library shelf is currently empty.\n");
                    break;
                }

                printf("\n--- CURRENT BOOK SHELF DIRECTORY ---\n");
                for (i = 0; i < count; i++) {
                    printf("%d. %s\n", i + 1, library[i]);
                }
                printf("------------------------------------\n");
                printf("Total books in inventory = %d\n", count);
                break;

            case 3: 
                if (count == 0) {
                    printf("\n📭 The library shelf is empty. Nothing to search.\n");
                    break;
                }

                while (getchar() != '\n'); 
                printf("\nEnter Book Title to search: ");
                scanf("%[^\n]", search_title);

                found = 0;
                for (i = 0; i < count; i++) {
                    int j = 0;
                    while (library[i][j] == search_title[j] && library[i][j] != '\0' && search_title[j] != '\0') {
                        j++;
                    }
                    
                    if (library[i][j] == '\0' && search_title[j] == '\0') {
                        printf("🟢 Success: \"%s\" is AVAILABLE at shelf position %d!\n", library[i], i + 1);
                        found = 1;
                        break; 
                    }
                }
                
                if (!found) {
                    printf("❌ Sorry: \"%s\" is NOT found in this mini library.\n", search_title);
                }
                break;

            case 4: 
                printf("\nShutting down Mini Library System. Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid selection! Please enter a choice between 1 and 4.\n");
        }
    }

    return 0;
}
