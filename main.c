#include "header.h"

int main(int argc, char * argv[]) {
    int input;                              // Keeps track of input.

    // Options 1 to 4.

    long double num1;                       // Keeps track of num1 for basic operations.
    long double num2;                       // Keeps track of num2 for basic operations.

    // Options 5.
    
    // Keeps track of all coeffcients for quadratic equations.

    long double a;
    long double b;
    long double c;

    // Used to calculate the Discriminant.

    long double discrim;

    // Used to calculate the roots if the Discriminant is greater than 0.

    long double xPlus;
    long double xMinus;

    // Used to calculate the roots if the Discriminant is less than 0.

    long double real;
    long double img;

    // Used to calculate the roots if the Discriminant is equal to 0.

    long double oneRoot;

    // Matrix Multipliation.

    int M;
    int N;
    int P;
    int i, j, k;

    // Determinant

    int n;
    int result;

    // Unit Conversion Part.
        //Temperature
    int tempChoice;
    int convert;
    int fToC;
    int cToF;

    // Greeting + Menu.

    printf("Welcome to a basic calculator.\n");
    input = menu();

    // Once input is given run the program until the user decides to exit.

    while (input != 0)  {

        // Possibility 1: Input is in the appropriate range of integers with simple operations (1 - 4).

        if ((input >= 0) && (input <= 4))   {
            
            // Collect two numbers for standard operations.

            printf("Number 1: ");
            scanf("%Lf", &num1);
            printf("Number 2: ");
            scanf("%Lf", &num2);

            // Swtich statment for different operations.

            switch(input)   {

                // Case 1: Addition.

                case 1:
                    printf("%.2Lf.\n", (num1 + num2));
                    break;

                // Case 2: Subtraction.

                case 2:
                    printf("%.2Lf.\n", (num1 - num2));
                    break;
                
                // Case 3: Multiplication.

                case 3:
                    printf("%.2Lf.\n", (num1 * num2));
                    break;
                
                // Case 4: Division.

                case 4:
                    printf("%.2Lf.\n", (num1 / num2));
                    break;
            }
            
            // Ask for the next operation.

            printf("\nPrevious operation complete.\n");
            input = menu();
        }

        // Possibility 2: Input is in the appropriate range of integers with root operations (5).

        else if (input == 5)    {

            // Ask for coeffcients.

            printf("Standard form for a quadratic equation: ax^2 + bx + c.\n");
            printf("Coefficient a: ");
            scanf("%Lf", &a);
            printf("Coefficient b: ");
            scanf("%Lf", &b);
            printf("Coefficient c: ");
            scanf("%Lf", &c);

            // Calculate Discriminant.

            discrim = pow(b, 2) + (-1 * 4 * a * c);

            // Case 1: Discriminant is positive calulate both roots.

            if (discrim > 0)   {

                // Quadratic formula process for two real roots.

                discrim = sqrt(discrim);
                xPlus = (-1*b + discrim) / (2 * a);
                xMinus = (-1*b - discrim) / (2 * a);
                printf("Root 1: %.2Lf.\n", xPlus);
                printf("Root 2: %.2Lf.\n", xMinus);
            }

            // Case 2: Discriminant is negative so there will be complex roots.

            else if (discrim < 0)   {

                // Quadratic formula process for complex roots.
                
                discrim = abs(discrim);
                real = (-1*b) / (2 * a);
                img = (long double)discrim / (2 * a);
                printf("Complex Root: %Lf +- %.2Lfi.\n", real, img);
            }

            // Case 3: Discriminant is 0 so there will be one root.

            else    {

                // Quadratic formula process for one real root.

                oneRoot = (-1*b + discrim) / (2 * a);
                printf("One root: %.2Lf.\n", oneRoot);
            }

            // Ask for the next operation.

            printf("\nPrevious operation complete.\n");
            input = menu();
        }

        // Possibility 3: Input is in the appropriate range of integer to conduct a matrix multiplication (6).

        else if (input == 6)    {

            // Get dimensions for matrix 1.

            printf("Matrix multiplication what are the dimensions of matrix 1.\n");
            printf("Matrix 1 Number of Rows: ");
            scanf("%d", &M);
            printf("Matrix 1 Number of Columns: ");
            scanf("%d", &N);
            printf("Now fill in matrix 1.\n");

            // Fill Matrix 1.

            int A[M][N];

            for (i = 0; i < M; i++)   {
                for (j = 0; j < N; j++)   {
                    printf("Position %d, %d: ", i + 1, j + 1);
                    scanf("%d", &A[i][j]);
                }
            }

            // Show user the matrix they made.

            printf("The matrix you created.\n[");
            for (i = 0; i < M; i++)   {
                for (j = 0; j < N; j++)   {
                    if (j == (N - 1))  {
                      printf("%d", A[i][j]);  
                    }
                    else    {
                        printf("%d, ", A[i][j]);
                    }
                }
                if (i != (M - 1))  {
                    printf("\n");
                }
            }
            printf("].\n");

            // Get dimensions for matrix 2.

            printf("Matrix multiplication what are the dimensions of matrix 2.\n");
            printf("The number of rows must be equivlent to the number of folumns from matrix 1 so there are %d rows in matrix 2.\n", N);
            printf("Matrix 2 Number of Columns: ");
            scanf("%d", &P);
            printf("\nNow fill in matrix 2.\n");

            // Fill Matrix 2.

            int B[N][P];

            for (i = 0; i < N; i++)   {
                for (j = 0; j < P; j++)   {
                    printf("Position %d, %d: ", i + 1, j + 1);
                    scanf("%d", &B[i][j]);
                }
            }

            // Show user the matrix they made.

            printf("[");
            for (i = 0; i < N; i++)   {
                for (j = 0; j < P; j++)   {
                    if (j == (P - 1))  {
                        printf("%d", B[i][j]);  
                    }
                    else    {
                        printf("%d, ", B[i][j]);
                    }
                }
                if (i != (N- 1))  {
                    printf("\n");
                }
            }
            printf("].\n");

            // Solve the matrix multiplication.

            int C[M][P];  

            for (i = 0; i < M; i++)    {
                for (j = 0; j < P; j++)    {
                    C[i][j] = 0;
                    for (k = 0; k < N; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            // Show the user the answer.

            printf("\nAnswer.\n[");
            for (i = 0; i < M; i++)   {
                for (j = 0; j < P; j++)   {
                    if (j == (P - 1))  {
                        printf("%d", C[i][j]);  
                    }
                    else    {
                        printf("%d, ", C[i][j]);
                    }
                }
                if (i != (M - 1))  {
                    printf("\n");
                }
            }
            printf("].\n");

            // Ask for the next operation.

            printf("\nPrevious operation complete.\n");
            input = menu();
        }

        // Possibility 4: Input is in the appropriate range of integer to find the determinant of a square matrix (7).

        else if (input == 7)    {
            int N[100][100];
            
            // Get the order of the square matrix.

            printf("Enter the order of the square matrix N (NxN): ");
            scanf("%d", &n);
            
            // Fill the suare matrix.

            printf("Fill the square matrix.\n");

            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++)   {
                    printf("Position %d, %d: ", i + 1, j + 1);
                    scanf("%d", &N[i][j]);
                }
            }

            // Show the square matrix.

            printf("The matrix you made.\n");
            printf("[");
            
            for (i = 0; i < n; i++)   {
                for (j = 0; j < n; j++)   {
                    if (j == (n - 1))  {
                        printf("%d", N[i][j]);  
                    }
                    else    {
                        printf("%d, ", N[i][j]);
                    }
                }
                if (i != (n - 1))  {
                    printf("\n");
                }
            }
            printf("].\n");

            // Get the determinant and show the result.

            result = det(N, n);
            printf("The determinant for the matix is %d.\n", result);
            
            // Ask for the next operation.

            printf("\nPrevious operation complete.\n");
            input = menu();
        }

        // Possibility 5: Input is in the appropriate range of integer to find the determinant of a square matrix (8 - 9).

        else if ((input >= 8) && (input <= 9))    {
            int mass;
            float oToP;
            float gToP;

            // Switch Statement for the appropriate category for conversion.

            switch (input)  {
                case 8:
                    printf("Welcome to Temperature Converter! \n");
                    printf("Here is a list of conversations to choose from: \n");
                    printf("Enter 1 for Fahrenheit to Celsius. \n");
                    printf("Enter 2 for Celsius to Fahrenheit. \n");
                    scanf("%d", &tempChoice);
                    
                    // Case 1: Fahrenheit to Celcius.

                    if(tempChoice == 1){
                        printf("Please enter the Fahrenheit degree: \n");
                        scanf("%d", &convert);
                        fToC =  ((convert - 32) * (5.0 / 9.0));
                        printf("Celcius: %d.\n", fToC);
                        break;
                    }

                    // Case 2: Celcius to Fahrenheit. 
                    
                    else if(tempChoice == 2){
                        printf("Please enter the Celcius degree: \n");
                        scanf("%d",&convert);
                        cToF = ((9.0 / 5.0) * convert + 32);
                        printf("Fahrenheit: %d.\n", cToF);
                        break;
                    }

                    // Case 3: Not a selection. 

                    else    {
                        printf("Please enter the correct choice next time.\n");
                    }
                    break;
               
                case 9:
                    printf("Welcome to Mass Converter! \n");
                    printf("Here is a list of conversations to choose from: \n");
                    printf("Enter 1 for Ounces to Pounds. \n");
                    printf("Enter 2 for Gram to Pounds. \n");
                    scanf("%d", &mass);

                    // Case 1: Ounce to Pounds.
                
                    if(mass == 1){
                        printf("Please enter the ounce amount: \n");
                        scanf("%d", &convert);
                        oToP = convert * 0.0625;
                        printf("Pounds: %.2f", oToP);
                    }

                    // Case 2: Grams to Pounds. 

                    else if(mass == 2) {
                        printf("Please enter the gram amount: \n");
                        scanf("%d", &convert);
                        gToP = convert * 0.00220462;
                        printf("Pounds: %.2f", gToP);
                    }

                    // Case 3: Not a selection. 

                    else    { 
                        printf("Please enter the correct choice next time. \n");
                    }
                    break;
            }

            // Ask for the next operation.

            printf("\nPrevious operation complete.\n");
            input = menu();
        }
        // Possibility 6: Input is not in the appropriate range of integers.
        
        else    {
            
            // Ask for valid input.
            
            printf("Invalid input, try again.\n");
            input = menu();
        }

    }
}
