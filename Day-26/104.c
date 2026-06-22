#include <stdio.h>

struct Question {
    char text[150];       
    char options[4][50];  
    char correct_option;  
};

int main() {
    int score = 0;
    char user_answer;

    struct Question quiz[3] = {
        {
            "Which programming language is known as the mother of all languages?",
            {"A. Java", "B. Python", "C. C Language", "D. C++"},
            'C'
        },
        {
            "What is the time complexity to search an element in a balanced Binary Search Tree?",
            {"A. O(1)", "B. O(log n)", "C. O(n)", "D. O(n log n)"},
            'B'
        },
        {
            "Which of the following is not a valid storage class specifier in C?",
            {"A. register", "B. static", "C. auto", "D. volatile"},
            'D'
        }
    };

    int total_questions = sizeof(quiz) / sizeof(quiz[0]);

    printf("=========================================\n");
    printf("       WELCOME TO THE TECH QUIZ          \n");
    printf("=========================================\n");
    printf("Instructions: Enter A, B, C, or D for each question.\n\n");

    for (int i = 0; i < total_questions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].text);
        
        // Print the 4 multiple choice options
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        // Prompt user and read input character
        printf("Your Answer: ");
        scanf(" %c", &user_answer); // Note the leading space to skip previous newline characters

        // Convert lowercase answers to uppercase for standardization
        if (user_answer >= 'a' && user_answer <= 'z') {
            user_answer -= 32;
        }

        // Validate the answer
        if (user_answer == quiz[i].correct_option) {
            printf("✅ Correct Answer!\n\n");
            score++;
        } else {
            printf("❌ Incorrect. The correct answer was %c.\n\n", quiz[i].correct_option);
        }
    }

    printf("=========================================\n");
    printf("             QUIZ OVER!                  \n");
    printf("=========================================\n");
    printf("Your Final Score: %d out of %d\n", score, total_questions);
    
    float percentage = ((float)score / total_questions) * 100;
    printf("Percentage scored: %.2f%%\n", percentage);

    return 0;
}