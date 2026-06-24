#include <stdio.h>

#define ROWS 5
#define COLS 6
#define TICKET_PRICE 150.0 

int main() {
    int seats[ROWS][COLS] = {0}; 
    int choice, r, c, tickets_to_book;
    float total_bill;

    printf("=========================================\n");
    printf("         CINEPLEX TICKET BOOKING         \n");
    printf("=========================================\n");

    while (1) {
        printf("\n------------- MAIN MENU -------------\n");
        printf("1. View Seating Layout Chart\n");
        printf("2. Book Movie Tickets\n");
        printf("3. Check Seat Status Lookup\n");
        printf("4. Exit System\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("\n--- SEATING CHART CHART (🟢=Avail, ❌=Booked) ---\n");
                printf("       ");
                for (int j = 0; j < COLS; j++) {
                    printf("Col %d  ", j + 1);
                }
                printf("\n-------------------------------------------------\n");
                
                for (int i = 0; i < ROWS; i++) {
                    printf("Row %d | ", i + 1);
                    for (int j = 0; j < COLS; j++) {
                        if (seats[i][j] == 0) {
                            printf(" 🟢   "); 
                        } else {
                            printf(" ❌   "); 
                        }
                    }
                    printf("\n");
                }
                printf("-------------------------------------------------\n");
                printf("               🎬 SCREEN THIS WAY 🎬              \n");
                break;

            case 2: 
                printf("\nEnter total number of tickets to book: ");
                scanf("%d", &tickets_to_book);

                if (tickets_to_book <= 0) {
                    printf("❌ Error: Invalid quantity specified.\n");
                    break;
                }

                total_bill = 0;
                int successful_bookings = 0;

                for (int k = 0; k < tickets_to_book; k++) {
                    printf("\n[Ticket %d] Enter Row Number (1-%d): ", k + 1, ROWS);
                    scanf("%d", &r);
                    printf("[Ticket %d] Enter Column Number (1-%d): ", k + 1, COLS);
                    scanf("%d", &c);

                    
                    int target_row = r - 1;
                    int target_col = c - 1;

                    if (target_row < 0 || target_row >= ROWS || target_col < 0 || target_col >= COLS) {
                        printf("❌ Invalid coordinates! This seat does not exist. Try again for this ticket.\n");
                        k--; 
                        continue;
                    }

                    if (seats[target_row][target_col] == 1) {
                        printf("❌ Seat choice Row %d, Col %d is already taken! Pick another.\n", r, c);
                        k--; 
                    } else {
                        seats[target_row][target_col] = 1; 
                        total_bill += TICKET_PRICE;
                        successful_bookings++;
                        printf("✅ Seat booked successfully: Row %d, Col %d\n", r, c);
                    }
                }

                if (successful_bookings > 0) {
                    printf("\n🎉 TRANSACTION SUMMARY:\n");
                    printf("Total Seats Locked : %d\n", successful_bookings);
                    printf("Total Amount Due   : ₹%.2f\n", total_bill);
                }
                break;

            case 3: 
                printf("\nEnter Row Number (1-%d) to check: ", ROWS);
                scanf("%d", &r);
                printf("Enter Column Number (1-%d) to check: ", COLS);
                scanf("%d", &c);

                int check_row = r - 1;
                int check_col = c - 1;

                if (check_row < 0 || check_row >= ROWS || check_col < 0 || check_col >= COLS) {
                    printf("❌ Invalid selection coordinate bounds.\n");
                } else if (seats[check_row][check_col] == 0) {
                    printf("🟢 Seat Row %d, Col %d is wide open and AVAILABLE to book!\n", r, c);
                } else {
                    printf("❌ Seat Row %d, Col %d is RESERVED.\n", r, c);
                }
                break;

            case 4:
                printf("\nThank you for using Cineplex Booking. Goodbye!\n");
                return 0;

            default:
                printf("❌ Invalid selection. Please choose an option between 1 and 4.\n");
        }
    }

    return 0;
}
