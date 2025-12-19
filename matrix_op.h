#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

typedef float Matrix3x3[SIZE][SIZE];

void add_matrices(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result);    
void subtract_matrices(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result); 
void transpose_matrix(Matrix3x3 a, Matrix3x3 result);  
void element_wise_multiply(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result);
void multiply_matrices(Matrix3x3 a, Matrix3x3 b, Matrix3x3 result);
float calculate_determinant(Matrix3x3 a);
void adjoint_matrix(Matrix3x3 a, Matrix3x3 result);
void inverse_matrix(Matrix3x3 a, Matrix3x3 result);

#endif
