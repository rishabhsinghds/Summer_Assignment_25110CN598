#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0; 
    int choice, search_roll, found;

    printf("=========================================\n");
    printf("     STUDENT RECORD MANAGEMENT SYSTEM    \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- MAIN MENU -------------\n");
        printf("1. Add New Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit System\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (count >= MAX_STUDENTS) {
                    printf("❌ Error: System storage full! Cannot add more records.\n");
                    break;
                }
                
                printf("\nEnter Roll Number: ");
                scanf("%d", &students[count].roll_no);
                
                while (getchar() != '\n'); 

                printf("Enter Student Name: ");
                scanf("%[^\n]", students[count].name);

                printf("Enter Marks: ");
                scanf("%f", &students[count].marks);

                count++;                 printf("✅ Record added successfully!\n");
                break;

            case 2: 
                if (count == 0) {
                    printf("\n📭 No records found in the system database.\n");
                    break;
                }
            
                printf("\n--- Stored Student Records ---\n");
                printf("Roll No\tName\t\t\tMarks\n");
                printf("-----------------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%-20s\t%.2f\n", students[i].roll_no, students[i].name, students[i].marks);
                }
                break;

            case 3: 
                if (count == 0) {
                    printf("\n📭 Database empty. Nothing to search.\n");
                    break;
                }

                printf("\nEnter Roll Number to search: ");
                scanf("%d", &search_roll);
                
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (students[i].roll_no == search_roll) {
                        printf("\n🎉 Record Found!\n");
                        printf("Roll Number : %d\n", students[i].roll_no);
                        printf("Name        : %s\n", students[i].name);
                        printf("Marks       : %.2f\n", students[i].marks);
                        found = 1;
                        break; 
                    }
                }
                
                if (!found) {
                    printf("❌ Record not found for Roll Number %d.\n", search_roll);
                }
                break;

            case 4: 
                printf("\nExiting Student Management System. Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid choice! Please enter a value between 1 and 4.\n");
        }
    }

    return 0;
}
