#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

int main() {
    int roll_numbers[MAX_STUDENTS];
    char names[MAX_STUDENTS][NAME_LENGTH]; 
    float marks[MAX_STUDENTS];
    
    int count = 0; 
    int choice, i, search_roll, found;

    printf("=========================================\n");
    printf("         STUDENT RECORD SYSTEM           \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- MAIN MENU -------------\n");
        printf("1. Add New Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit System\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (count >= MAX_STUDENTS) {
                    printf("❌ Error: Database storage full! Cannot add more records.\n");
                    break;
                }

                printf("\nEnter Roll Number: ");
                scanf("%d", &roll_numbers[count]);

                while (getchar() != '\n'); 

                printf("Enter Student Name: ");
                scanf("%[^\n]", names[count]);

                printf("Enter Total Marks: ");
                scanf("%f", &marks[count]);

                if (marks[count] < 0 || marks[count] > 100) {
                    printf("❌ Error: Marks must be evaluated between 0 and 100.\n");
                } else {
                    count++; 
                    printf("✅ Student record added successfully!\n");
                }
                break;

            case 2: 
                if (count == 0) {
                    printf("\n📭 No student records found in the database.\n");
                    break;
                }

                printf("\n------------------- STUDENT ROSTER -------------------\n");
                printf("Roll No\t%-25s\tMarks\n", "Student Name");
                printf("------------------------------------------------------\n");
                for (i = 0; i < count; i++) {
                    
                    printf("%d\t%-25s\t%.2f\n", roll_numbers[i], names[i], marks[i]);
                }
                printf("------------------------------------------------------\n");
                printf("Total enrolled students = %d\n", count);
                break;

            case 3: 
                if (count == 0) {
                    printf("\n📭 Database empty. Nothing to search.\n");
                    break;
                }

                printf("\nEnter Roll Number to lookup: ");
                scanf("%d", &search_roll);

                found = 0;
                for (i = 0; i < count; i++) {
                    
                    if (roll_numbers[i] == search_roll) {
                        printf("\n=========================================\n");
                        printf("             STUDENT PROFILE             \n");
                        printf("=========================================\n");
                        printf(" Roll Number : %d\n", roll_numbers[i]);
                        printf(" Full Name   : %s\n", names[i]);
                        printf(" Marks       : %.2f / 100.00\n", marks[i]);
                        printf("=========================================\n");
                        found = 1;
                        break; 
                    }
                }
                if (!found) {
                    printf("❌ Error: No student file found matching Roll Number %d.\n", search_roll);
                }
                break;

            case 4: 
                printf("\nShutting down Student Record System. Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid choice! Please enter a value between 1 and 4.\n");
        }
    }

    return 0;
}
