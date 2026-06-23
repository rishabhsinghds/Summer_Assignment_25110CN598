#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100


struct SalaryRecord {
    int emp_id;
    char name[50];
    float basic_salary;
    float hra;        
    float da;         
    float pf;       
    float net_salary; 
};

int main() {
    struct SalaryRecord emp[MAX_EMPLOYEES];
    int count = 0; 
    int choice, search_id, found;

    printf("=========================================\n");
    printf("         SALARY MANAGEMENT SYSTEM        \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- MAIN MENU -------------\n");
        printf("1. Generate New Salary Slip\n");
        printf("2. Display All Salary Slips (Payroll)\n");
        printf("3. Search Salary Slip by Employee ID\n");
        printf("4. Exit System\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (count >= MAX_EMPLOYEES) {
                    printf("❌ Error: Payroll storage full!\n");
                    break;
                }
                
                printf("\nEnter Employee ID: ");
                scanf("%d", &emp[count].emp_id);

                while (getchar() != '\n'); 

                printf("Enter Employee Name: ");
                scanf("%[^\n]", emp[count].name);

                printf("Enter Basic Monthly Salary: ₹");
                scanf("%f", &emp[count].basic_salary);

                emp[count].hra = emp[count].basic_salary * 0.20; 
                emp[count].da = emp[count].basic_salary * 0.10;  
                emp[count].pf = emp[count].basic_salary * 0.12;  

                emp[count].net_salary = (emp[count].basic_salary + emp[count].hra + emp[count].da) - emp[count].pf;

                count++; 
                printf("✅ Salary details processed and saved successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("\n📭 No payroll records found in the database.\n");
                    break;
                }
                
                printf("\n---------------------------------- COMPANY PAYROLL SHEET ----------------------------------\n");
                printf("ID\t%-15s\tBasic\t\tHRA(20%%)\tDA(10%%)\tPF(12%%)\tNet Salary\n", "Name");
                printf("-------------------------------------------------------------------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%-15s\t₹%-10.2f\t₹%-9.2f\t₹%-7.2f\t₹%-7.2f\t₹%.2f\n", 
                           emp[i].emp_id, emp[i].name, emp[i].basic_salary, emp[i].hra, emp[i].da, emp[i].pf, emp[i].net_salary);
                }
                break;

            case 3: 
                if (count == 0) {
                    printf("\n📭 Database empty. Nothing to search.\n");
                    break;
                }

                printf("\nEnter Employee ID to look up payslip: ");
                scanf("%d", &search_id);
                
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (emp[i].emp_id == search_id) {
                        printf("\n=========================================\n");
                        printf("         SALARY SLIP / PAY ADVICE        \n");
                        printf("=========================================\n");
                        printf("Employee ID   : %d\n", emp[i].emp_id);
                        printf("Employee Name : %s\n", emp[i].name);
                        printf("-----------------------------------------\n");
                        printf(" (+) Basic Salary        : ₹%.2f\n", emp[i].basic_salary);
                        printf(" (+) House Rent (HRA)    : ₹%.2f\n", emp[i].hra);
                        printf(" (+) Dearness (DA)       : ₹%.2f\n", emp[i].da);
                        printf(" (-) Provident Fund (PF) : ₹%.2f\n", emp[i].pf);
                        printf("-----------------------------------------\n");
                        printf(" 💵 NET TAKE-HOME SALARY : ₹%.2f\n", emp[i].net_salary);
                        printf("=========================================\n");
                        found = 1;
                        break; 
                    }
                }
                if (!found) {
                    printf("❌ No salary record found for Employee ID %d.\n", search_id);
                }
                break;

            case 4: 
                printf("\nShutting down Salary Management System. Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid choice! Please enter a value between 1 and 4.\n");
        }
    }

    return 0;
}
