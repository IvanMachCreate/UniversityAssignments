#include <iostream>
#include <iomanip>
using namespace std;

#include "lab6_functions.h" // Include the declearation of the functions.


/* Helper function for output */
void print2DArray(int matrix[][MAX_DIMENSION], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}


/* YOU MUST NOT MODIFY THE MAIN FUNCTION BELOW */
int main() {
    cout << "Welcome to the Lab 6!" << endl;
    cout << "There are 3 required tasks" << endl;
    int task;
    while (true) {
        cout << "==========================================================="<< endl;
        cout << "Task 1: Implement Matrix Transpose function!" << endl;
        cout << "Task 2: Implement Matrix Addition function!" << endl;
        cout << "Task 3: Implement Matrix Multiplication function!" << endl;
        cout << "Task 4: Implement Print Out the 2D Array in a horizontally flipped way function!" << endl;
       
        cout << "\nSelect the task (Enter 1, 2, 3 or 4) or Enter -1 to quit (Other invalid value will be ignored.): ";
        cin >> task;

        if (task == -1) {
            cout << "Bye!" << endl;
            break; 
        }
        
        switch (task) {
            case 1:
                {
                // Task 1: Implement Matrix Transpose function. 
                cout << "Task 1: Implement Matrix Transpose function!!" << endl;
                int arr[MAX_DIMENSION][MAX_DIMENSION];
                int res[MAX_DIMENSION][MAX_DIMENSION];
                int row;
                int col;
                cout << "Enter the row and column of the matrix: ";
                cin >> row >> col;
                if (row < 0 || col < 0) {
                    cout << "Invalid input!" << endl;
                    break;
                }
                cout << "Enter the elements of the matrix: "<< endl;
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        cin >> arr[i][j];
                    }
                }
                // Transpose the matrix
                cout << "The transpose of the matrix is: " << endl;
                transpose(arr, row, col, res);
                print2DArray(res, col, row);
                break;
                }
            case 2:
                {
                // Task 2: Implement Matrix Addition function.
                cout << "Task 2: Implement Matrix Addition function!" << endl;
                int rowA, colA, rowB, colB;
                int matA[MAX_DIMENSION][MAX_DIMENSION];
                int matB[MAX_DIMENSION][MAX_DIMENSION];
                int resAB[MAX_DIMENSION][MAX_DIMENSION];

                cout << "Enter the row and column of the matrix A: " << endl;
                cin >> rowA >> colA;
                if (rowA < 0 || colA < 0) {
                    cout << "Invalid input!" << endl;
                    break;
                }
                cout << "Enter the elements of the matrix: "<< endl;
                for (int i = 0; i < rowA; i++) {
                    for (int j = 0; j < colA; j++) {
                        cin >> matA[i][j];
                    }
                }

                cout << "Enter the row and column of the matrix B: ";
                cin >> rowB >> colB;
                if (rowB < 0 || colB < 0) {
                    cout << "Invalid input!" << endl;
                    break;
                }
                if (!((rowA == rowB) && (colA == colB))) {
                    cout << "Row and Column of matrix B must the same as matrix A" << endl;
                    break;
                }

                cout << "Enter the elements of the matrix: "<< endl;
                for (int i = 0; i < rowB; i++) {
                    for (int j = 0; j < colB; j++) {
                        cin >> matB[i][j];
                    }
                }

                // Add the matrix
                add(matA, matB, resAB, rowA, colA);

                cout << "The sum of the matrix A and matrix B is: " << endl;
                print2DArray(resAB, rowA, colA);
                break;
                }
            case 3:
                {
                // Task 3: Implement Matrix Multiplication function.
                cout << "Task 3: Implement Matrix Multiplication function!" << endl;
                int rowA, colA, rowB, colB;
                int matA[MAX_DIMENSION][MAX_DIMENSION];
                int matB[MAX_DIMENSION][MAX_DIMENSION];
                int res[MAX_DIMENSION][MAX_DIMENSION];

                cout << "Enter the row and column of the matrix A: " << endl;
                cin >> rowA >> colA;
                if (rowA < 0 || colA < 0) {
                    cout << "Invalid input!" << endl;
                    break;
                }
                cout << "Enter the elements of the matrix: "<< endl;
                for (int i = 0; i < rowA; i++) {
                    for (int j = 0; j < colA; j++) {
                        cin >> matA[i][j];
                    }
                }

                cout << "Enter the row and column of the matrix B: ";
                cin >> rowB >> colB;
                if (rowB < 0 || colB < 0) {
                    cout << "Invalid input!" << endl;
                    break;
                }
                if (!(rowB == colA)) {
                    cout << "Row of matrix B must be equal to column of matrix A" << endl;
                    break;
                }

                cout << "Enter the elements of the matrix: "<< endl;
                for (int i = 0; i < rowB; i++) {
                    for (int j = 0; j < colB; j++) {
                        cin >> matB[i][j];
                    }
                }

                // Multiply the matrix
                multiply(matA, matB, res, rowA, colA, colB);

                cout << "The product of the matrix A and B is: " << endl;
                print2DArray(res, rowA, colB);
                break;
                }
            case 4:
                {
                // Task 4: Implement Print Horizontal Flip 2D Array. 
                cout << "Task 4: Implement Implement Print Horizontal Flip 2D Array!" << endl;
                int arr[MAX_DIMENSION][MAX_DIMENSION];
                int res[MAX_DIMENSION][MAX_DIMENSION];
                int row;
                int col;
                cout << "Enter the row and column of the matrix: ";
                cin >> row >> col;
                if (row < 0 || col < 0) {
                    cout << "Invalid input!" << endl;
                    break;
                }
                cout << "Enter the elements of the matrix: "<< endl;
                for (int i = 0; i < row; i++) {
                    for (int j = 0; j < col; j++) {
                        cin >> arr[i][j];
                    }
                }
                // Flip the 2D Array.
                horizontal_flip_2D_array(arr, row, col, res);  
                cout << "The horizontally flipped array is:" << endl;
                print2DArray(res, row, col);
                break;
            }
            default:
                continue;
         }
    }
    return 0;
}
