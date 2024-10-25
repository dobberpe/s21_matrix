#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define S21_EPS 1E-7
#define OK 0
#define INVALID_MATRIX 1
#define CALCULATION_ERROR 2
#define SUCCESS 1  // s21_eq_matrix
#define FAILURE 0  // s21_eq_matrix

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
matrix_t s21_create_minor(matrix_t *A, int i, int j);
int s21_determinant(matrix_t *A, double *result);
bool s21_is_triangle(matrix_t *A, int *errno);
int s21_null_column(matrix_t *A, int j);
int s21_swap_rows(matrix_t *A, int j);
double calculate_determinant(matrix_t *A);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif
