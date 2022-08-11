# include "header.h"

/*
    A function name menu() to print the menu to reduce redundancy.
*/

int menu() {   
    int num;                                // Used for input.

    // Menu for all possible operations.

    printf("Basic Operations.\n");
    printf("1) Addition.\n");
    printf("2) Subtraction.\n");
    printf("3) Multiplication.\n");
    printf("4) Division.\n");
    printf("\nQuadratic Formula.\n");
    printf("5) Root Calculation.\n");
    printf("\nMatrix Operations.\n");
    printf("6) Matrix Multiplication.\n");
    printf("7) Matrix Determinant.\n");
    printf("\nUnit Conversion.\n");
    printf("8) Temperature.\n");
    printf("9) Mass\n");
    printf("Quit: 0\n");
    scanf("%d", &num);

    // Return users selections.
    
    return num;
}