#include <iostream>
#include <cstring>

const int MAX_DIMENSION=100;


// Task 1: Implement the Matrix Transpose.
// Note: maxtrix_t is used for storing the result.
void transpose(const int matrix[][MAX_DIMENSION], const int& row, const int& col,
               int matrix_t[][MAX_DIMENSION]);

// Task 2: Implement the Matrix Addition.
// Note: maxtrixC is used for storing the result.
// Note: row is the number of rows of matrixA, and col is the number of columns of matrixA.
// Note: You can assume that the shape of matrixA is equal to the shape of the matrixB
void add(const int matrixA[][MAX_DIMENSION], const int matrixB[][MAX_DIMENSION], 
         int matrixC[][MAX_DIMENSION], const int& row, const int& col);

// Task 3: Implement the Matrix Multiplication.
// Note: maxtrixC is used for storing the result.
// Note: rowA is the number of rows of matrixA, and colA is the number of columns of matrixA.
// Note: rowB is the number of columns of matrixB.
// Note: You can assume that the number of columns of matrixA is equal to the number of rows of matrixB
void multiply(const int matrixA[][MAX_DIMENSION], const int matrixB[][MAX_DIMENSION], 
              int matrixC[][MAX_DIMENSION], const int& rowA, const int& colA, 
              const int& rowB);

// Task 4: Implementation of horizontally flipping 2D Array.
// Notes: matrix_f is used for storing the result.
void horizontal_flip_2D_array(const int matrix[][MAX_DIMENSION], 
                              const int& row, const int& col,
                              int matrix_f[][MAX_DIMENSION]);