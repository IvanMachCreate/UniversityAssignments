#include "lab6_functions.h" // Include the declearation of the function


// Task 4: Implementation of horizontally flipping 2D Array.
// Notes: matrix_f is used for storing the result.
void horizontal_flip_2D_array(const int matrix[][MAX_DIMENSION], 
                              const int& row, const int& col, 
                              int matrix_f[][MAX_DIMENSION]) {
    /***************Start your code here***************/
    for ( int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix_f[i][col - 1 - j] = matrix[i][j];
        }
    }
    /***************End your code here***************/
}