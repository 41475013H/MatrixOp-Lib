#include "matrix_op.h"
#include <stdio.h>

// Basic
// addition
void add_matrices(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result) {
	int i,j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}
// subtraction
void subtract_matrices(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result) {
	int i,j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}
// element-wise multiplication
void element_wise_multiply(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result) {
	int i,j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] * b[i][j];
        }
    }
}

// Linear
// transpose
void transpose_matrix(Matrix3x3 a, Matrix3x3 result) {
	int i,j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result[i][j] = a[j][i];
        }
    }
}
// matrix multiplication
void multiply_matrices(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result) {
	int i,j,k;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Advanced
// Determinant
float calculate_determinant(Matrix3x3 a) {
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
           a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
           a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}
// adjoint matrix
void adjoint_matrix(Matrix3x3 a, Matrix3x3 result) {
    result[0][0] =  (a[1][1] * a[2][2] - a[1][2] * a[2][1]);
    result[0][1] = -(a[0][1] * a[2][2] - a[0][2] * a[2][1]);
    result[0][2] =  (a[0][1] * a[1][2] - a[0][2] * a[1][1]);

    result[1][0] = -(a[1][0] * a[2][2] - a[1][2] * a[2][0]);
    result[1][1] =  (a[0][0] * a[2][2] - a[0][2] * a[2][0]);
    result[1][2] = -(a[0][0] * a[1][2] - a[0][2] * a[1][0]);

    result[2][0] =  (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
    result[2][1] = -(a[0][0] * a[2][1] - a[0][1] * a[2][0]);
    result[2][2] =  (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
}

// Inversed
// inverse matrix
void inverse_matrix(Matrix3x3 a, Matrix3x3 result) {
    float det = calculate_determinant(a);
    if (det == 0) {
        printf("Error: Determinant is 0, Inverse does not exist.\n");
        return;
    }
    Matrix3x3 adj;
    adjoint_matrix(a, adj);
    int i,j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            result[i][j] = adj[i][j] / det;
        }
    }
}
