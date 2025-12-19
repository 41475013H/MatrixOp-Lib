#include "matrix_op.h"
#include <stdio.h>

// 1. 矩陣加法 (Addition)
void add_matrices(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// 2. 矩陣乘法 (Matrix Multiplication)
void multiply_matrices(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// 3. 行列式計算 (Determinant for 3x3)
float calculate_determinant(Matrix3x3 a) {
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
           a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
           a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

// 4. 轉置矩陣 (Transpose)
void transpose_matrix(Matrix3x3 a, Matrix3x3 result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = a[j][i];
        }
    }
}

// 5. 逆矩陣 (Inverse Matrix) - 簡化版邏輯
void inverse_matrix(Matrix3x3 a, Matrix3x3 result) {
    float det = calculate_determinant(a);
    if (det == 0) {
        printf("Matrix is singular, cannot find inverse.\n");
        return;
    }
    // 這裡應包含伴隨矩陣除以行列式的計算
    // 為求簡潔，此處僅示範架構，實作時需計算各項代數餘子式
}