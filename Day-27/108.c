#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100


struct Marksheet {
    int roll_no;
    char name[50];
    int marks[3];     
    int total;
    float percentage;
    char grade[5];
    int is_passed;    
};

int main() {
    struct Marksheet students[MAX_STUDENTS];
    int count = 0; 
    int choice, search_roll, found;

    printf("=========================================\n");
    printf("        MARKSHEET GENERATION SYSTEM      \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- MAIN MENU -------------\n");
        printf("1. Generate New Student Marksheet\n");
        printf("2. View All Student Marksheets (Ledger)\n");
        printf("3. Print Marksheet by Roll Number\n");
        printf("4. Exit System\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (count >= MAX_STUDENTS) {
                    printf("❌ Error: Storage full! Cannot generate more marksheets.\n");
                    break;
                }
                
                printf("\nEnter Roll Number: ");
                scanf("%d", &students[count].roll_no);
                
                
                while (getchar() != '\n'); 

                printf("Enter Student Name: ");
                scanf("%[^\n]", students[count].name);

                printf("Enter marks for Mathematics (out of 100): ");
                scanf("%d", &students[count].marks[0]);

                printf("Enter marks for Science (out of 100): ");
                scanf("%d", &students[count].marks[1]);

                printf("Enter marks for English (out of 100): ");
                scanf("%d", &students[count].marks[2]);

            
                students[count].total = students[count].marks[0] + students[count].marks[1] + students[count].marks[2];
                students[count].percentage = (float)students[count].total / 3.0;

                
                if (students[count].marks[0] >= 40 && students[count].marks[1] >= 40 && students[count].marks[2] >= 40) {
                    students[count].is_passed = 1;
                } else {
                    students[count].is_passed = 0;
                }

            
                if (students[count].is_passed == 0) {
                    strcpy(students[count].grade, "F");
                } else if (students[count].percentage >= 90) {
                    strcpy(students[count].grade, "A+");
                } else if (students[count].percentage >= 75) {
                    strcpy(students[count].grade, "A");
                } else if (students[count].percentage >= 60) {
                    strcpy(students[count].grade, "B");
                } else if (students[count].percentage >= 50) {
                    strcpy(students[count].grade, "C");
                } else {
                    strcpy(students[count].grade, "D");
                }

                count++; 
                printf("✅ Marksheet processed and saved successfully!\n");
                break;

            case 2: 
                if (count == 0) {
                    printf("\n📭 No records found in the database.\n");
                    break;
                }
                
                printf("\n-------------------------------- GENERAL REPORT CARD LEDGER --------------------------------\n");
                printf("Roll No\t%-15s\tMaths\tScience\tEnglish\tTotal\tPercentage\tGrade\tStatus\n", "Name");
                printf("--------------------------------------------------------------------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%-15s\t%d\t%d\t%d\t%d\t%.2f%%\t\t%s\t%s\n", 
                           students[i].roll_no, students[i].name, 
                           students[i].marks[0], students[i].marks[1], students[i].marks[2],
                           students[i].total, students[i].percentage, students[i].grade,
                           students[i].is_passed ? "PASS" : "FAIL");
                }
                break;

            case 3: 
                if (count == 0) {
                    printf("\n📭 Database empty. Nothing to print.\n");
                    break;
                }

                printf("\nEnter Roll Number to search and print report card: ");
                scanf("%d", &search_roll);
                
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (students[i].roll_no == search_roll) {
                        printf("\n==================================================\n");
                        printf("            OFFICIAL ACADEMIC MARKSHEET           \n");
                        printf("==================================================\n");
                        printf(" Roll Number : %-15d Name : %s\n", students[i].roll_no, students[i].name);
                        printf("--------------------------------------------------\n");
                        printf(" Subject               Max Marks      Marks Obtained\n");
                        printf("--------------------------------------------------\n");
                        printf(" 1. Mathematics           100               %d\n", students[i].marks[0]);
                        printf(" 2. Science               100               %d\n", students[i].marks[1]);
                        printf(" 3. English               100               %d\n", students[i].marks[2]);
                        printf("--------------------------------------------------\n");
                        printf(" GRAND TOTAL: %d / 300       PERCENTAGE: %.2f%%\n", students[i].total, students[i].percentage);
                        printf(" FINAL GRADE: %-15s STATUS: %s\n", students[i].grade, students[i].is_passed ? "🎉 PASS" : "❌ FAIL");
                        printf("==================================================\n");
                        found = 1;
                        break; 
                    }
                }
                if (!found) {
                    printf("❌ No marksheet record found for Roll Number %d.\n", search_roll);
                }
                break;

            case 4: 
                printf("\nShutting down Marksheet Generation System. Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid choice! Please enter a value between 1 and 4.\n");
        }
    }

    return 1;
}
