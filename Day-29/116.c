#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

int main() {
    struct Product inventory[MAX_ITEMS];
    int count = 0; 
    int choice, search_id, found, added_stock;

    printf("=========================================\n");
    printf("       INVENTORY MANAGEMENT SYSTEM       \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- MAIN MENU -------------\n");
        printf("1. Add New Product\n");
        printf("2. Display Current Inventory\n");
        printf("3. Restock Product (Update Quantity)\n");
        printf("4. Search Product by ID\n");
        printf("5. Exit System\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (count >= MAX_ITEMS) {
                    printf("❌ Error: Inventory warehouse storage full!\n");
                    break;
                }
                
                printf("\nEnter Unique Product ID: ");
                scanf("%d", &inventory[count].id);
                
                while (getchar() != '\n'); 

                printf("Enter Product Name: ");
                scanf("%[^\n]", inventory[count].name);

                printf("Enter Unit Price: ₹");
                scanf("%f", &inventory[count].price);

                printf("Enter Initial Quantity: ");
                scanf("%d", &inventory[count].quantity);

                if (inventory[count].quantity < 0 || inventory[count].price < 0) {
                    printf("❌ Error: Price and Quantity cannot be negative numbers.\n");
                } else {
                    count++; 
                    printf("✅ Product added to inventory successfully!\n");
                }
                break;

            case 2: 
                if (count == 0) {
                    printf("\n📭 The inventory warehouse is currently empty.\n");
                    break;
                }
                
                printf("\n----------------------- WAREHOUSE INVENTORY DIRECTORY -----------------------\n");
                printf("ID\t%-25s\tPrice\t\tQuantity\tTotal Value\n", "Product Name");
                printf("-----------------------------------------------------------------------------\n");
                float total_warehouse_value = 0;
                for (int i = 0; i < count; i++) {
                    float item_total_value = inventory[i].price * inventory[i].quantity;
                    total_warehouse_value += item_total_value;
                    
                    printf("%d\t%-25s\t₹%-10.2f\t%-10d\t₹%.2f\n", 
                           inventory[i].id, 
                           inventory[i].name, 
                           inventory[i].price, 
                           inventory[i].quantity,
                           item_total_value);
                }
                printf("-----------------------------------------------------------------------------\n");
                printf("📦 Total Cumulative Stock Value: ₹%.2f\n", total_warehouse_value);
                break;

            case 3: 
                if (count == 0) {
                    printf("\n📭 Inventory empty. Nothing to restock.\n");
                    break;
                }

                printf("\nEnter Product ID to restock: ");
                scanf("%d", &search_id);
                
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (inventory[i].id == search_id) {
                        found = 1;
                        printf("Current stock level for \"%s\" is %d units.\n", inventory[i].name, inventory[i].quantity);
                        printf("Enter quantity to ADD: ");
                        scanf("%d", &added_stock);
                        
                        if (added_stock <= 0) {
                            printf("❌ Invalid input! Added stock quantity must be greater than zero.\n");
                        } else {
                            inventory[i].quantity += added_stock; // Update stock count
                            printf("✅ Stock updated successfully! New quantity = %d units.\n", inventory[i].quantity);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Error: Product ID %d does not exist in the ledger.\n", search_id);
                }
                break;

            case 4: 
                if (count == 0) {
                    printf("\n📭 Inventory empty. Nothing to search.\n");
                    break;
                }

                printf("\nEnter Product ID to lookup: ");
                scanf("%d", &search_id);
                
                found = 0;
                for (int i = 0; i < count; i++) {
                    if (inventory[i].id == search_id) {
                        printf("\n=========================================\n");
                        printf("             PRODUCT PROFILE             \n");
                        printf("=========================================\n");
                        printf(" Product ID    : %d\n", inventory[i].id);
                        printf(" Product Name  : %s\n", inventory[i].name);
                        printf(" Unit Price    : ₹%.2f\n", inventory[i].price);
                        printf(" Stock Level   : %d units\n", inventory[i].quantity);
                        printf(" Asset Value   : ₹%.2f\n", inventory[i].price * inventory[i].quantity);
                        printf("=========================================\n");
                        found = 1;
                        break; 
                    }
                }
                if (!found) {
                    printf("❌ Error: Product ID %d not found.\n", search_id);
                }
                break;

            case 5: 
                printf("\nExiting Inventory Management System. Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid choice! Please enter a value between 1 and 5.\n");
        }
    }

    return 0;
}
