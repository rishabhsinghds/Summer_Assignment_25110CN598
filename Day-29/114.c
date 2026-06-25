#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size = 0; 
    int choice, element, position, i, found;

    printf("=========================================\n");
    printf("       ARRAY OPERATIONS MANAGEMENT       \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- ARRAY MENU -------------\n");
        printf("1. Display Array Elements\n");
        printf("2. Insert Element at a Position\n");
        printf("3. Delete Element from a Position\n");
        printf("4. Search Element (Linear Search)\n");
        printf("5. Exit System\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (size == 0) {
                    printf("\n📭 Array is currently empty.\n");
                } else {
                    printf("\nArray elements: ");
                    for (i = 0; i < size; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n(Current Size = %d)\n", size);
                }
                break;

            case 2: 
                if (size >= MAX_SIZE) {
                    printf("❌ Error: Array overflow! Cannot insert more elements.\n");
                    break;
                }

                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position (1 to %d): ", size + 1);
                scanf("%d", &position);

                if (position < 1 || position > size + 1) {
                    printf("❌ Invalid position selection!\n");
                } else {
                    
                    for (i = size - 1; i >= position - 1; i--) {
                        arr[i + 1] = arr[i];
                    }
                    arr[position - 1] = element; 
                    size++;                      
                    printf("✅ Element inserted successfully!\n");
                }
                break;

            case 3: 
                if (size == 0) {
                    printf("❌ Error: Array underflow! Nothing to delete.\n");
                    break;
                }

                printf("Enter position to delete from (1 to %d): ", size);
                scanf("%d", &position);

                
                if (position < 1 || position > size) {
                    printf("❌ Invalid position selection!\n");
                } else {
                    element = arr[position - 1]; 
                    
                    for (i = position - 1; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--; 
                    printf("🗑️ Element %d deleted successfully from position %d.\n", element, position);
                }
                break;

            case 4: 
                if (size == 0) {
                    printf("\n📭 Array empty. Nothing to search.\n");
                    break;
                }

                printf("Enter element to search for: ");
                scanf("%d", &element);

                found = 0;
                for (i = 0; i < size; i++) {
                    if (arr[i] == element) {
                        printf("🎉 Element found at position %d (Index %d)\n", i + 1, i);
                        found = 1;
                        break; 
                    }
                }
                if (!found) {
                    printf("❌ Element %d not found inside the array.\n", element);
                }
                break;

            case 5: 
                printf("\nExiting Array Operations System. Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid selection! Please enter a choice between 1 and 5.\n");
        }
    }

    return 0;
}
