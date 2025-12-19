#include <stdio.h>
#include "matrix_op.h"

// 輔助函式：用來印出 3x3 矩陣
void print_matrix(const char* name, Matrix3x3 m) {
    printf("%s\n", name);
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%5.1f ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // 定義測試用的矩陣 A 和 B
    Matrix3x3 A = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };
    
    Matrix3x3 B = {
        {7, 8, 9},
        {4, 5, 6},
        {1, 2, 3}
    };
    
    Matrix3x3 res;
    float det;

    printf("Matrix Operations Library Test\n\n");
    print_matrix("Matrix A", A);
    print_matrix("Matrix B", B);

    // basic
    add_matrices(A, B, res);
    print_matrix("Addition (A + B)", res);

    subtract_matrices(A, B, res);
    print_matrix("Subtraction (A - B)", res);

    element_wise_multiply(A, B, res);
    print_matrix("Element-wise Multiplication", res);

    // linear
    transpose_matrix(A, res);
    print_matrix("Transpose of A", res);

    multiply_matrices(A, B, res);
    print_matrix("Matrix Multiplication (A * B)", res);

    // advanced
    det = calculate_determinant(A);
    printf("--- Determinant of A ---\nDet = %.2f\n\n", det);

    adjoint_matrix(A, res);
    print_matrix("Adjoint Matrix of A", res);

	//inverse
    if (det != 0) {
        inverse_matrix(A, res);
        print_matrix("Inverse Matrix of A", res);
    } else {
        printf("Inverse Matrix of A: Does not exist (Det = 0)\n\n");
    }

    return 0;
}
