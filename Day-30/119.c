#include <stdio.h>

#define MAX_EMPLOYEES 50
#define NAME_LENGTH 50

int main() {
    int emp_ids[MAX_EMPLOYEES];
    char emp_names[MAX_EMPLOYEES][NAME_LENGTH]; 
    float emp_salaries[MAX_EMPLOYEES];
    
    int count = 0; 
    int choice, i, search_id, found;
    float new_salary;

    printf("=========================================\n");
    printf("      MINI EMPLOYEE MANAGEMENT SYSTEM    \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- DIRECTORY MENU -------------\n");
        printf("1. Add New Employee Record\n");
        printf("2. Display Employee Roster\n");
        printf("3. Update Salary by Employee ID\n");
        printf("4. Exit System\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (count >= MAX_EMPLOYEES) {
                    printf("❌ Error: Mini employee directory is completely full!\n");
                    break;
                }

                printf("\nEnter Employee ID: ");
                scanf("%d", &emp_ids[count]);

                while (getchar() != '\n'); 

                printf("Enter Employee Name: ");
                scanf("%[^\n]", emp_names[count]);

                printf("Enter Monthly Salary: ₹");
                scanf("%f", &emp_salaries[count]);

                if (emp_salaries[count] < 0) {
                    printf("❌ Error: Salary cannot be a negative number.\n");
                } else {
                    count++;
                    printf("✅ Employee record saved successfully!\n");
                }
                break;

            case 2: 
                if (count == 0) {
                    printf("\n📭 The employee directory is currently empty.\n");
                    break;
                }

                printf("\n------------------- EMPLOYEE ROSTER -------------------\n");
                printf("ID\t%-25s\tSalary\n", "Employee Name");
                printf("-------------------------------------------------------\n");
                for (i = 0; i < count; i++) {
                    printf("%d\t%-25s\t₹%.2f\n", emp_ids[i], emp_names[i], emp_salaries[i]);
                }
                printf("-------------------------------------------------------\n");
                printf("Total active workforce = %d\n", count);
                break;

            case 3: 
                if (count == 0) {
                    printf("\n📭 Directory empty. Nothing to update.\n");
                    break;
                }

                printf("\nEnter Employee ID to update salary: ");
                scanf("%d", &search_id);

                found = 0;
                for (i = 0; i < count; i++) {    
                    if (emp_ids[i] == search_id) {
                        printf("Current Salary for \"%s\" is ₹%.2f\n", emp_names[i], emp_salaries[i]);
                        printf("Enter New Salary: ₹");
                        scanf("%f", &new_salary);
                        
                        if (new_salary < 0) {
                            printf("❌ Error: Salary cannot be negative.\n");
                        } else {
                            emp_salaries[i] = new_salary; 
                            printf("✅ Salary updated successfully for ID %d!\n", search_id);
                        }
                        found = 1;
                        break; 
                    }
                }
                if (!found) {
                    printf("❌ Error: No employee profile found matching ID %d.\n", search_id);
                }
                break;

            case 4: 
                printf("\nShutting down Employee System. Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid selection! Please enter a choice between 1 and 4.\n");
        }
    }

    return 0;
}
