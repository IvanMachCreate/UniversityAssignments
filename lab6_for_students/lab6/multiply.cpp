#include "lab6_functions.h" // Include the declearation of the function


// Task 3: Implement the Matrix Multiplication.
// Note: maxtrixC is used for storing the result.
// Note: You need to intialize the matrixC to all zeros before mutiplying matrixA and matrixB.
// Note: rowA is the number of rows of matrixA, and colA is the number of columns of matrixA.
// Note: rowB is the number of columns of matrixB.
// Note: You can assume that the number of columns of matrixA is equal to the number of rows of matrixB
void multiply(const int matrixA[][MAX_DIMENSION], const int matrixB[][MAX_DIMENSION], 
              int matrixC[][MAX_DIMENSION], const int& rowA, const int& colA, 
              const int& colB) {
    /***************Start your code here***************/
    for (int i = 0; i < rowA ; i++) {
        for (int j = 0; j < colB; j++) {
            matrixC[i][j] = 0;
            for ( int k = 0; k < colA; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    
    }

    /***************End your code here***************/
}