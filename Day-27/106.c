#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};

int main() {
    struct Employee emp[MAX_EMPLOYEES];
    int count = 0; 
    int choice, search_id, found;

    printf("=========================================\n");
    printf("        EMPLOYEE MANAGEMENT SYSTEM       \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- MAIN MENU -------------\n");
        printf("1. Add New Employee Record\n");
        printf("2. Display All Employee Records\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Salary by Employee ID\n");
        printf("5. Exit System\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (count >= MAX_EMPLOYEES) {
                    printf("❌ Error: System storage full! Cannot add more records.\n");
                    break;
                }
                
                printf("\nEnter Employee ID: ");
                scanf("%d", &emp[count].id);
                
                while (getchar() != '\n'); 

                printf("Enter Employee Name: ");
                scanf("%[^\n]", emp[count].name);
                while (getchar() != '\n'); 

                printf("Enter Designation: ");
                scanf("%[^\n]", emp[count].designation);

                printf("Enter Monthly Salary: ₹");
                scanf("%f", &emp[count].salary);

                count++; 
                printf("✅ Employee record added successfully!\n");
                break;

            case 2: 
                if (count == 0) {
                    printf("\n📭 No employee records found in the database.\n");
                    break;
                }
                
                printf("\n----------------------- EMPLOYEE DIRECTORY -----------------------\n");
                printf("ID\t%-20s\t%-20s\tSalary\n", "Name", "Designation");
                printf("------------------------------------------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%-20s\t%-20s\t₹%.2f\n", emp[i].id, emp[i].name, emp[i].designation, emp[i].salary);
                }
                break;

            case 3: 
                if (count == 0) {
                    printf("\n📭 Database empty. Nothing to search.\n");
                    break;
                }

                printf("\nEnter Employee ID to search: ");
                scanf("%d", &search_id);
                
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (emp[i].id == search_id) {
                        printf("\n🎉 Record Found!\n");
                        printf("ID          : %d\n", emp[i].id);
                        printf("Name        : %s\n", emp[i].name);
                        printf("Designation : %s\n", emp[i].designation);
                        printf("Salary      : ₹%.2f\n", emp[i].salary);
                        found = 1;
                        break; 
                    }
                }
                if (!found) {
                    printf("❌ Record not found for Employee ID %d.\n", search_id);
                }
                break;

            case 4: 
                if (count == 0) {
                    printf("\n📭 Database empty. Nothing to update.\n");
                    break;
                }

                printf("\nEnter Employee ID to update salary: ");
                scanf("%d", &search_id);
                
                found = 0;
                for (int i = 0; i < count; i++) {
                if (emp[i].id == search_id) {
                        printf("\nCurrent Salary for %s is ₹%.2f\n", emp[i].name, emp[i].salary);
                        printf("Enter New Salary: ₹");
                        scanf("%f", &emp[i].salary);
                        printf("✅ Salary updated successfully!\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Employee ID %d does not exist.\n", search_id);
                }
                break;

            case 5: 
                printf("\nExiting Employee Management System. Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid choice! Please enter a value between 1 and 5.\n");
        }
    }

    return 0;
}
