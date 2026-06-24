#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

int main() {
    struct Contact directory[MAX_CONTACTS];
    int count = 0; 
    int choice, found, delete_idx;
    char search_name[50];

    printf("=========================================\n");
    printf("        CONTACT MANAGEMENT SYSTEM        \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- MAIN MENU -------------\n");
        printf("1. Add New Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Delete a Contact\n");
        printf("5. Exit System\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (count >= MAX_CONTACTS) {
                    printf("❌ Error: Contact directory full!\n");
                    break;
                }
                
                
                while (getchar() != '\n'); 

                printf("\nEnter Contact Name: ");
                scanf("%[^\n]", directory[count].name);
                while (getchar() != '\n'); 

                printf("Enter Phone Number: ");
                scanf("%[^\n]", directory[count].phone);
                while (getchar() != '\n'); 

                printf("Enter Email Address: ");
                scanf("%[^\n]", directory[count].email);

                count++; 
                printf("✅ Contact saved successfully!\n");
                break;

            case 2: 
                if (count == 0) {
                    printf("\n📭 Your contact list is currently empty.\n");
                    break;
                }
                
                printf("\n--------------------------- CONTACT LIST ---------------------------\n");
                printf("%-20s\t%-15s\t%-25s\n", "Name", "Phone Number", "Email");
                printf("--------------------------------------------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%-20s\t%-15s\t%-25s\n", 
                           directory[i].name, 
                           directory[i].phone, 
                           directory[i].email);
                }
                break;

            case 3: 
                if (count == 0) {
                    printf("\n📭 Contact list empty. Nothing to search.\n");
                    break;
                }

                while (getchar() != '\n'); 
                printf("\nEnter Name to search: ");
                scanf("%[^\n]", search_name);
                
                found = 0;
                for (int i = 0; i < count; i++) {
                    
                    if (strcmp(directory[i].name, search_name) == 0) {
                        printf("\n🎉 Contact Found!\n");
                        printf("Name         : %s\n", directory[i].name);
                        printf("Phone Number : %s\n", directory[i].phone);
                        printf("Email Address: %s\n", directory[i].email);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Error: Contact \"%s\" not found.\n", search_name);
                }
                break;

            case 4: 
                if (count == 0) {
                    printf("\n📭 Contact list empty. Nothing to delete.\n");
                    break;
                }

                while (getchar() != '\n'); 
                printf("\nEnter exact Contact Name to delete: ");
                scanf("%[^\n]", search_name);
                
                delete_idx = -1;
                for (int i = 0; i < count; i++) {
                    if (strcmp(directory[i].name, search_name) == 0) {
                        delete_idx = i;
                        break;
                    }
                }

                if (delete_idx == -1) {
                    printf("❌ Error: Contact \"%s\" does not exist.\n", search_name);
                } else {
                    for (int i = delete_idx; i < count - 1; i++) {
                        directory[i] = directory[i + 1];
                    }
                    count--; 
                    printf("🗑️ Contact \"%s\" deleted successfully!\n", search_name);
                }
                break;

            case 5: 
                printf("\nShutting down Contact Management System. Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid choice! Please enter a value between 1 and 5.\n");
        }
    }

    return 0;
}
