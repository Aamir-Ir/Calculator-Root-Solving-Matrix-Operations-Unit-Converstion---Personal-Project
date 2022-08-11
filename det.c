#include "header.h"

int det(int N[100][100], int n)   {
            int i, j, k;
            int min[100][100];
            int determinant = 0;
            int c1, c2;  
            int O = 1;

            // Base Case: If the square matrix has a order of 2. Perform the most basic operation.

            if (n == 2) {
                determinant = N[0][0] * N[1][1] - N[0][1] * N[1][0];
                return determinant;
            }

            // Recursive Case: Use the strategy to solve a square matrix by using the formula.

            else    {
                for (i = 0; i < n; i++) {
                    c1 = 0;
                    c2 = 0;
                    for (j = 0; j < n; j++) {
                        for (k = 0; k < n; k++) {
                            if ((j != 0) && (k != i))   {
                                min[c1][c2] = N[j][k];
                                c2++;
                                if(c2 > (n-2))  {
                                    c1++;
                                    c2 = 0;
                                }
                            }
                        }
                    }

                    determinant = determinant + (O * (N[0][i] * det(min, n - 1)));
                    O = -1 * O;
                }
            }

            return determinant;
}