#include "lab6_functions.h" // Include the declearation of the function


// Task 1: Implement the Matrix Transpose.
void transpose(const int matrix[][MAX_DIMENSION], const int& row,
               const int& col, int matrix_t[][MAX_DIMENSION]) {
  /***************Start your code here***************/
  for (int i = 0; i < row ; i++) {
    for (int j = 0; j < col; j++) {
        matrix_t[j][i] = matrix[i][j];
    }
  }
  /***************End your code here***************/
}