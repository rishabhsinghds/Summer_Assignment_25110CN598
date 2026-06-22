#include <stdio.h>

int main() {
    float balance = 5000.0; 
    float amount;
    int choice;
    int pin = 1234;         
    int entered_pin, attempts = 0;
    int authenticated = 0;

    printf("=========================================\n");
    printf("         WELCOME TO THE APEX BANK        \n");
    printf("=========================================\n");

    while (attempts < 3) {
        printf("Enter your 4-digit ATM PIN: ");
        scanf("%d", &entered_pin);
        attempts++;

        if (entered_pin == pin) {
            authenticated = 1;
            break;
        } else {
            printf("Incorrect PIN. %d attempt(s) remaining.\n\n", 3 - attempts);
        }
    }

    if (!authenticated) {
        printf("❌ Card Blocked! Too many incorrect PIN attempts. Please visit your branch.\n");
        return 0;
    }

    while (1) {
        printf("\n------------- ATM MAIN MENU -------------\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Cash\n");
        printf("3. Withdraw Cash\n");
        printf("4. Exit Session\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n💳 Current Balance: ₹%.2f\n", balance);
                break;

            case 2:
                printf("\nEnter amount to deposit: ₹");
                scanf("%f", &amount);
                
                if (amount <= 0) {
                    printf("❌ Invalid amount. Deposit must be greater than zero.\n");
                } else {
                    balance += amount;
                    printf("✅ ₹%.2f deposited successfully.\n", amount);
                    printf("Updated Balance: ₹%.2f\n", balance);
                }
                break;

            case 3:
                printf("\nEnter amount to withdraw: ₹");
                scanf("%f", &amount);
                
                if (amount <= 0) {
                    printf("❌ Invalid amount. Withdrawal must be greater than zero.\n");
                } else if (amount > balance) {
                    printf("❌ Transaction Declined: Insufficient funds!\n");
                    printf("Your available balance is ₹%.2f\n", balance);
                } else {
                    balance -= amount; 
                    printf("🏧 Please collect your cash.\n");
                    printf("✅ ₹%.2f withdrawn successfully.\n", amount);
                    printf("Updated Balance: ₹%.2f\n", balance);
                }
                break;

            case 4:
                printf("\nThank you for banking with Apex Bank. Goodbye!\n");
                return 0;
            default:
                printf("❌ Invalid selection. Please enter a choice between 1 and 4.\n");
        }
    }

    return 0;
}
