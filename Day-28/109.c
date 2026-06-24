#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[50];
    int is_issued;
};

int main() {
    struct Book library[MAX_BOOKS];
    int count = 0; 
    int choice, search_id, found;

    printf("=========================================\n");
    printf("        LIBRARY MANAGEMENT SYSTEM        \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- MAIN MENU -------------\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Issue a Book\n");
        printf("4. Return a Book\n");
        printf("5. Exit System\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= MAX_BOOKS) {
                    printf("❌ Error: Library catalogue storage full!\n");
                    break;
                }
                
                printf("\nEnter Unique Book ID: ");
                scanf("%d", &library[count].id);
                
                
                while (getchar() != '\n'); 

                printf("Enter Book Title: ");
                scanf("%[^\n]", library[count].title);
                while (getchar() != '\n'); 

                printf("Enter Author Name: ");
                scanf("%[^\n]", library[count].author);

                library[count].is_issued = 0; 

                count++; 
                printf("✅ Book added to inventory successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("\n📭 The library catalogue is currently empty.\n");
                    break;
                }
                
                printf("\n--------------------------- LIBRARY CATALOGUE ---------------------------\n");
                printf("ID\t%-30s\t%-20s\tStatus\n", "Title", "Author");
                printf("-------------------------------------------------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%-30s\t%-20s\t%s\n", 
                           library[i].id, 
                           library[i].title, 
                           library[i].author, 
                           library[i].is_issued ? "❌ ISSUED" : "🟢 AVAILABLE");
                }
                break;

            case 3: 
                if (count == 0) {
                    printf("\n📭 Catalogue empty. No books to issue.\n");
                    break;
                }

                printf("\nEnter Book ID to Issue: ");
                scanf("%d", &search_id);
                
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (library[i].id == search_id) {
                        found = 1;
                        if (library[i].is_issued == 1) {
                            printf("❌ Transaction Declined: \"%s\" is already issued out!\n", library[i].title);
                        } else {
                            library[i].is_issued = 1; // Flip status to Issued
                            printf("📖 Success! \"%s\" has been issued to you.\n", library[i].title);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Error: Book ID %d does not exist in the catalogue.\n", search_id);
                }
                break;

            case 4: 
                if (count == 0) {
                    printf("\n📭 Catalogue empty. No books to return.\n");
                    break;
                }

                printf("\nEnter Book ID to Return: ");
                scanf("%d", &search_id);
                
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (library[i].id == search_id) {
                        found = 1;
                        if (library[i].is_issued == 0) {
                            printf("⚠️ Notice: \"%s\" is already marked as available inside shelves.\n", library[i].title);
                        } else {
                            library[i].is_issued = 0; // Flip status to Available
                            printf("🟢 Success! \"%s\" has been returned to the shelves.\n", library[i].title);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Error: Book ID %d does not exist in the catalogue.\n", search_id);
                }
                break;

            case 5: 
                printf("\nShutting down Library Management System. Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid choice! Please enter a value between 1 and 5.\n");
        }
    }

    return 0;
}
