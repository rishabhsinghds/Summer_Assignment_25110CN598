#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 50
#define NAME_LEN 40

void displayMenu();
void addProduct(int ids[], char names[][NAME_LEN], float prices[], int quantities[], int *count);
void displayInventory(int ids[], char names[][NAME_LEN], float prices[], int quantities[], int count);
void searchProduct(int ids[], char names[][NAME_LEN], float prices[], int quantities[], int count);
void generateBill(int ids[], char names[][NAME_LEN], float prices[], int quantities[], int count);

int main() {
    int product_ids[MAX_ITEMS];
    char product_names[MAX_ITEMS][NAME_LEN];
    float product_prices[MAX_ITEMS];
    int product_quantities[MAX_ITEMS];
    
    int active_product_count = 0; 
    int choice;

    printf("=========================================\n");
    printf("     RETAIL STORE MANAGEMENT SYSTEM      \n");
    printf("=========================================\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(product_ids, product_names, product_prices, product_quantities, &active_product_count);
                break;
            case 2:
                displayInventory(product_ids, product_names, product_prices, product_quantities, active_product_count);
                break;
            case 3:
                searchProduct(product_ids, product_names, product_prices, product_quantities, active_product_count);
                break;
            case 4:
                generateBill(product_ids, product_names, product_prices, product_quantities, active_product_count);
                break;
            case 5:
                printf("\nShutting down System. Transactions saved. Goodbye!\n");
                return 0;
            default:
                printf("❌ Invalid Choice! Please pick an option between 1 and 5.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n------------- SERVICE MENU -------------\n");
    printf("1. Add Product to System\n");
    printf("2. View Store Stock Inventory\n");
    printf("3. Search Product Details\n");
    printf("4. Generate Customer Bill Invoice\n");
    printf("5. Close & Exit System\n");
    printf("Enter choice (1-5): ");
}

void addProduct(int ids[], char names[][NAME_LEN], float prices[], int quantities[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("❌ Storage Error: Store catalog is completely full!\n");
        return;
    }

    int current_index = *count;

    printf("\nEnter Unique Product ID: ");
    scanf("%d", &ids[current_index]);

    while (getchar() != '\n'); 

    printf("Enter Product Name: ");
    scanf("%[^\n]", names[current_index]);

    printf("Enter Selling Price: ₹");
    scanf("%f", &prices[current_index]);

    printf("Enter Initial Available Quantity: ");
    scanf("%d", &quantities[current_index]);

    if (prices[current_index] < 0 || quantities[current_index] < 0) {
        printf("❌ Rule Violation: Price and Quantity cannot be negative.\n");
    } else {
        (*count)++; 
        printf("✅ Product \"%s\" added successfully!\n", names[current_index]);
    }
}

void displayInventory(int ids[], char names[][NAME_LEN], float prices[], int quantities[], int count) {
    if (count == 0) {
        printf("\n📭 Database Empty: No products currently exist inside the system.\n");
        return;
    }

    printf("\n------------------------ STOCK LEDGER REPORT ------------------------\n");
    printf("ID\t%-25s\tPrice\t\tStock Level\n", "Product Name");
    printf("---------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-25s\t₹%-10.2f\t%d units\n", ids[i], names[i], prices[i], quantities[i]);
    }
    printf("---------------------------------------------------------------------\n");
}


void searchProduct(int ids[], char names[][NAME_LEN], float prices[], int quantities[], int count) {
    if (count == 0) {
        printf("\n📭 Database Empty: Nothing available to search.\n");
        return;
    }

    int target_id, found = 0;
    printf("\nEnter Product ID to lookup: ");
    scanf("%d", &target_id);

    for (int i = 0; i < count; i++) {
        if (ids[i] == target_id) {
            printf("\n=========================================\n");
            printf("             PRODUCT FILE                \n");
            printf("=========================================\n");
            printf(" Product ID     : %d\n", ids[i]);
            printf(" Description    : %s\n", names[i]);
            printf(" Current Price  : ₹%.2f\n", prices[i]);
            printf(" Stock Level    : %d units\n", quantities[i]);
            printf("=========================================\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("❌ Query Error: No item matching ID %d found.\n", target_id);
    }
}


void generateBill(int ids[], char names[][NAME_LEN], float prices[], int quantities[], int count) {
    if (count == 0) {
        printf("\n📭 Billing Cancelled: No items exist in the catalog to sell.\n");
        return;
    }

    int target_id, buy_qty, found;
    float grand_total = 0;
    char purchase_choice;

    printf("\n--- INITIALIZING POS CHECKOUT TRANSACTION ---\n");

    do {
        printf("Enter Product ID to purchase: ");
        scanf("%d", &target_id);

        found = 0;
        for (int i = 0; i < count; i++) {
            if (ids[i] == target_id) {
                found = 1;
                printf("Item Found: \"%s\" | Available Stock: %d | Price: ₹%.2f\n", names[i], quantities[i], prices[i]);
                printf("Enter quantity to purchase: ");
                scanf("%d", &buy_qty);

                if (buy_qty <= 0) {
                    printf("❌ Selection Error: Quantity must be greater than zero.\n");
                } else if (buy_qty > quantities[i]) {
                    printf("❌ Transaction Denied: Insufficient inventory stock!\n");
                } else {
                    quantities[i] -= buy_qty; 
                    float item_cost = prices[i] * buy_qty;
                    grand_total += item_cost;

                    printf("🛒 Added: %d x %s = ₹%.2f\n", buy_qty, names[i], item_cost);
                }
                break;
            }
        }

        if (!found) {
            printf("❌ Item Selection Error: ID %d does not exist.\n", target_id);
        }

        printf("\nDo you want to add another item to this bill? (y/n): ");
        scanf(" %c", &purchase_choice);

    } while (purchase_choice == 'y' || purchase_choice == 'Y');

    if (grand_total > 0) {
        printf("\n==================================================\n");
        printf("               FINAL STORE RECEIPT                \n");
        printf("==================================================\n");
        printf(" Total Bill Amount (Inclusive of Tax): ₹%.2f\n", grand_total);
        printf(" Cashier Status: Payment Received. Thank you!\n");
        printf("==================================================\n");
    } else {
        printf("\n⚠️ Transaction Aborted: No items were successfully billed.\n");
    }
}
