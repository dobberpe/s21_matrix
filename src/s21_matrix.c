#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double**)malloc(rows * sizeof(double*));

    for (int i = 0; i < rows; ++i) result->matrix[i] = (double*)calloc(columns, sizeof(double));

    return OK;
}

void s21_remove_matrix(matrix_t *A) {
    for (int i = 0; i < rows; ++i) free(A->matrix[i]);
    free(A->matrix);
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {}

int s21_transpose(matrix_t *A, matrix_t *result) {}

int s21_calc_complements(matrix_t *A, matrix_t *result) {}

int s21_determinant(matrix_t *A, double *result) {}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {}