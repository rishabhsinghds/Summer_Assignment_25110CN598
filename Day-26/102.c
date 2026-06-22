#include <stdio.h>

int main() {
    int age;

    printf("=========================================\n");
    printf("        VOTING ELIGIBILITY SYSTEM        \n");
    printf("=========================================\n");
    
    printf("Enter your age: ");

    if (scanf("%d", &age) != 1) {
        printf("Error: Please enter a valid numerical age.\n");
        return 1;
    }

   
    if (age < 0) {
        printf("Invalid Input: Age cannot be a negative number.\n");
    } 
    else if (age >= 18) {
        printf("\n🎉 Status: ELIGIBLE TO VOTE!\n");
        printf("You can officially register and cast your vote.\n");
    } 
    else {
        int years_left = 18 - age;
        printf("\n❌ Status: NOT ELIGIBLE TO VOTE.\n");
        printf("You must be at least 18 years old.\n");
        printf("You need to wait %d more year(s) to become eligible.\n", years_left);
    }

    return 0;
}
