#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Account {
    int account_number;
    char holder_name;
    char account_type; 
    float balance;
};

int main() {
    struct Account bank[MAX_ACCOUNTS];
    int count = 0; 
    int choice, search_acc, found;
    float transaction_amount;

    printf("=========================================\n");
    printf("           COSMOS BANKING SYSTEM         \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- MAIN MENU -------------\n");
        printf("1. Open New Bank Account\n");
        printf("2. Display All Accounts\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Search Account Details\n");
        printf("6. Exit System\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (count >= MAX_ACCOUNTS) {
                    printf("❌ Error: Bank database storage full!\n");
                    break;
                }
                
                printf("\nEnter Unique Account Number: ");
                scanf("%d", &bank[count].account_number);
                
                while (getchar() != '\n'); 

                printf("Enter Account Holder Name: ");
                scanf("%[^\n]", bank[count].holder_name);
                while (getchar() != '\n'); 

                printf("Enter Account Type (S for Savings / C for Current): ");
                scanf("%c", &bank[count].account_type);

                printf("Enter Initial Deposit Amount: ₹");
                scanf("%f", &bank[count].balance);

                if (bank[count].balance < 0) {
                    printf("❌ Error: Initial deposit cannot be negative.\n");
                } else {
                    count++; 
                    printf("✅ Account opened successfully!\n");
                }
                break;

            case 2: 
                if (count == 0) {
                    printf("\n📭 No accounts found in the bank database.\n");
                    break;
                }
                
                printf("\n--------------------------- ACTIVE BANK ACCOUNTS ---------------------------\n");
                printf("Acc No\t%-25s\tType\t\tBalance\n", "Holder Name");
                printf("----------------------------------------------------------------------------\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\t%-25s\t%s\t\t₹%.2f\n", 
                           bank[i].account_number, 
                           bank[i].holder_name, 
                           (bank[i].account_type == 'S' || bank[i].account_type == 's') ? "Savings" : "Current", 
                           bank[i].balance);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\n📭 Database empty. No accounts available.\n");
                    break;
                }

                printf("\nEnter Account Number for Deposit: ");
                scanf("%d", &search_acc);
                
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (bank[i].account_number == search_acc) {
                        found = 1;
                        printf("Enter amount to deposit: ₹");
                        scanf("%f", &transaction_amount);
                        
                        if (transaction_amount <= 0) {
                            printf("❌ Invalid amount. Deposit must be greater than zero.\n");
                        } else {
                            bank[i].balance += transaction_amount; // Update ledger
                            printf("✅ ₹%.2f deposited successfully to account %d.\n", transaction_amount, search_acc);
                            printf("Updated Balance: ₹%.2f\n", bank[i].balance);
                        }
                        break;
                    }
                }
                if (!found) printf("❌ Error: Account number %d not found.\n", search_acc);
                break;

            case 4: 
                if (count == 0) {
                    printf("\n📭 Database empty. No accounts available.\n");
                    break;
                }

                printf("\nEnter Account Number for Withdrawal: ");
                scanf("%d", &search_acc);
                
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (bank[i].account_number == search_acc) {
                        found = 1;
                        printf("Enter amount to withdraw: ₹");
                        scanf("%f", &transaction_amount);
                        
                        if (transaction_amount <= 0) {
                            printf("❌ Invalid amount. Withdrawal must be greater than zero.\n");
                        } else if (transaction_amount > bank[i].balance) {
                            printf("❌ Transaction Declined: Insufficient balance!\n");
                            printf("Available balance is ₹%.2f\n", bank[i].balance);
                        } else {
                            bank[i].balance -= transaction_amount; // Update ledger
                            printf("✅ ₹%.2f withdrawn successfully from account %d.\n", transaction_amount, search_acc);
                            printf("Updated Balance: ₹%.2f\n", bank[i].balance);
                        }
                        break;
                    }
                }
                if (!found) printf("❌ Error: Account number %d not found.\n", search_acc);
                break;

            case 5: 
                if (count == 0) {
                    printf("\n📭 Database empty. Nothing to search.\n");
                    break;
                }

                printf("\nEnter Account Number to lookup: ");
                scanf("%d", &search_acc);
                
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (bank[i].account_number == search_acc) {
                        printf("\n=========================================\n");
                        printf("             ACCOUNT SUMMARY             \n");
                        printf("=========================================\n");
                        printf(" Account Number : %d\n", bank[i].account_number);
                        printf(" Holder Name    : %s\n", bank[i].holder_name);
                        printf(" Account Type   : %s\n", (bank[i].account_type == 'S' || bank[i].account_type == 's') ? "Savings" : "Current");
                        printf(" Ledger Balance : ₹%.2f\n", bank[i].balance);
                        printf("=========================================\n");
                        found = 1;
                        break; 
                    }
                }
                if (!found) printf("❌ Error: Account number %d does not exist.\n", search_acc);
                break;

            case 6: 
                printf("\nShutting down Cosmos Banking System. Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid choice! Please enter a value between 1 and 6.\n");
        }
    }

    return 0;
}
