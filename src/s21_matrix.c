#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double**)malloc(rows * sizeof(double*));

    for (int i = 0; i < rows; ++i) result->matrix[i] = (double*)malloc(columns * sizeof(double));

    return OK;
}

void s21_remove_matrix(matrix_t *A) {
    for (int i = 0; i < A->rows; ++i) free(A->matrix[i]);
    free(A->matrix);
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int res = SUCCESS;

    if (!A->matrix || !B->matrix || A->rows != B->rows || A->columns != B->columns) res = FAILURE;
    else {
        int i = -1;
        while (++i < A->rows && res == SUCCESS) {
            int j = -1;
            while (++j < A->columns && res == SUCCESS) res = fabs(A->matrix[i][j] - B->matrix[i][j]) < S21_EPS ? SUCCESS : FAILURE;
        }
    }

    return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int res = OK;

    if (!A->matrix || !B->matrix) res = INVALID_MATRIX;
    else if (A->rows != B->rows || A->columns != B->columns) res = CALCULATION_ERROR;
    else {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; ++i) for (int j = 0; j < A->columns; ++j) result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }

    return res;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int res = OK;

    if (!A->matrix || !B->matrix) res = INVALID_MATRIX;
    else if (A->rows != B->rows || A->columns != B->columns) res = CALCULATION_ERROR;
    else {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; ++i) for (int j = 0; j < A->columns; ++j) result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }

    return res;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int res = OK;

    if (!A->matrix) res = INVALID_MATRIX;
    else {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; ++i) for (int j = 0; j < A->columns; ++j) result->matrix[i][j] = A->matrix[i][j] * number;
    }

    return res;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int res = OK;

    if (!A->matrix || !B->matrix) res = INVALID_MATRIX;
    else if (A->columns != B->rows) res = CALCULATION_ERROR;
    else {
        s21_create_matrix(A->rows, B->columns, result);
        1, 1 * 1, 1 + 1, 2 * 2, 1 + 1, 3 * 3, 1
        for (int i = 0; i < A->rows; ++i) {
            for (int j = 0; j < B->columns; ++j) {
                double sum = 0;
                for (int k = 0; k < A->columns; ++k) sum += A->matrix[i][k] * B->matrix[k][j];
                result->matrix[i][j] = sum;
            }
        }
    }

    return res;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
    int res = OK;

    if (!A->matrix) res = INVALID_MATRIX;
    else {
        s21_create_matrix(A->columns, A->rows, result);
        for (int i = 0; i < A->rows; ++i) for (int j = 0; j < A->columns; ++j) result->matrix[j][i] = A->matrix[i][j];
    }

    return res;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
    int res = OK;

    if (!A->matrix || A->rows != A->columns) res = INVALID_MATRIX;
    else {
        s21_create_matrix(A->rows, A->columns, result);
        for (int i = 0; i < A->rows; ++i) {
            for (int j = 0; j < A->columns; ++j) {
                matrix_t minor = s21_create_minor(A, i, j);
                s21_determinant(&minor, result->matrix[i][j]);
                s21_remove_matrix(&minor);
            }
        }
    }
}

matrix_t s21_create_minor(matrix_t *A, int i, int j) {
    matrix_t minor;
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor);

    for (int k = 0; k < minor.rows; ++k) {
        for (int l = 0; l < minor.columns; ++l) {
            minor.matrix[k][l] = k == i || l == j ? minor.matrix[k][i] : A->matrix[k > i ? i + 1 : i][l > j ? j + 1 : j];
        }
    }
}

int s21_determinant(matrix_t *A, double *result) {
    int res = OK;
    matrix_t A_triangle = {NULL, 0, 0};

    if (!A->matrix || A->rows != A->columns) res = INVALID_MATRIX;
    else if (!s21_is_triangle(A)) {
        s21_create_matrix(A->rows, A->columns, &A_triangle);
        for (int i = 0; i < A->rows; ++i) for (int j = 0; j < A->columns; ++j) A_triangle.matrix[i][j] = A->matrix[i][j];
        for (int i = 0; i < A->rows; ++i) s21_null_column(&A_triangle, i);
    }

    *result = calculate_determinant(A_triangle.matrix ? &A_triangle : A);
    if (A_triangle.matrix) s21_remove_matrix(&A_triangle);;
}

bool s21_is_triangle(matrix_t *A) {
    bool res = true;

    if (!A->matrix || A->rows != A->columns) res = false;
    else {
        int i = -1;
        while (++i < A->rows && res) {
            int j = -1;
            while (++j < i && res) res = A->matrix[i][j] ? false : true;
        }
    }

    return res;
}

void s21_null_column(matrix_t *A, int j) {
    for (int i = j + 1; i < A->rows; ++i) {
        double coef = A->matrix[i][j] / A->matrix[j][j];
        for (int k = j; k < A->columns; ++k) {
            A->matrix[i][k] -= coef * A->matrix[j][k];
        }
    }
}

double calculate_determinant(matrix_t *A) {
    double result = 1;
    for (int i = 0; i < A->rows; ++i) result *= A->matrix[i][i];
    return result;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
    int res = OK;
    double det;

    if ((res = s21_determinant(A, &det)) || !det) res = !det ? CALCULATION_ERROR : res;
    else {
        matrix_t T;
        s21_transpose(A, &T);
        s21_mult_number(T, 1 / det, result);
    }

    return res;
}