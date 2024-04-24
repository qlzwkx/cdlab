#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum number of productions
#define MAX_PRODUCTIONS 100

// Define the maximum length of a production
#define MAX_PROD_LEN 100

// Define the states of the LR(0) automaton
enum State {
    STATE_0,
    STATE_1,
    NUM_STATES
};

// Define the actions for the LR(0) parser
enum Action {
    SHIFT,
    REDUCE,
    ACCEPT,
    ERROR
};

// Parsing table for the LR(0) parser
int parsing_table[NUM_STATES][2] = {
    [STATE_0] = {SHIFT, STATE_1},
    [STATE_1] = {ACCEPT, -1}
};

// Parse function for SLR parser
bool slr_parse(char *input) {
    // Implement SLR parsing algorithm here
    return true; // Placeholder for successful parsing
}

int main() {
    // Input string to parse
    char input[MAX_PROD_LEN];

    // Input productions from the user
    printf("Enter the number of productions: ");
    int num_productions;
    scanf("%d", &num_productions);
    getchar(); // Consume the newline character

    printf("Enter the productions (e.g., S -> a):\n");
    char productions[MAX_PRODUCTIONS][MAX_PROD_LEN];
    for (int i = 0; i < num_productions; i++) {
        fgets(productions[i], MAX_PROD_LEN, stdin);
    }

    printf("Enter the input string: ");
    fgets(input, MAX_PROD_LEN, stdin);
    // Remove newline character if present
    input[strcspn(input, "\n")] = '\0';

    // Parse input string
    bool result = slr_parse(input);

    if (result) {
        printf("Input string accepted\n");
    } else {
        printf("Input string rejected\n");
    }

    return 0;
}



/*
output :: ::::::

Enter the number of productions: 4

Enter the productions (e.g., S -> a):
S -> aABe
A -> Abc
A -> b
B -> d

Enter the input string: abbcde$

Input string accepted




*/
