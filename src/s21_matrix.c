#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = OK;

  if (!result || rows < 1 || columns < 1) {
    res = INVALID_MATRIX;
    if (result) result->matrix = NULL;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * sizeof(double *));

    for (int i = 0; i < rows; ++i)
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
  }

  return res;
}

void s21_remove_matrix(matrix_t *A) {
  if (A && A->matrix) {
    for (int i = 0; i < A->rows; ++i)
      if (A->matrix[i]) free(A->matrix[i]);
    free(A->matrix);
    A->matrix = NULL;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;

  if (!A || !B || !A->matrix || !B->matrix || A->rows != B->rows ||
      A->columns != B->columns || !A->rows || !A->columns)
    res = FAILURE;
  else {
    int i = -1;
    while (++i < A->rows && A->matrix[i] && B->matrix[i] && res == SUCCESS) {
      int j = -1;
      while (++j < A->columns && res == SUCCESS) {
        res = A->matrix[i][j] == B->matrix[i][j] ||
                      fabs(A->matrix[i][j] - B->matrix[i][j]) < S21_EPS
                  ? SUCCESS
                  : FAILURE;
      }
    }
    if (i < A->rows && (!A->matrix[i] || !B->matrix[i])) res = FAILURE;
  }

  return res;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;

  if (!A || !B || !result || !A->matrix || !B->matrix || !A->rows ||
      !A->columns || !B->rows || !B->columns)
    res = INVALID_MATRIX;
  else if (A->rows != B->rows || A->columns != B->columns)
    res = CALCULATION_ERROR;
  else {
    s21_create_matrix(A->rows, A->columns, result);
    int i = -1;
    while (++i < A->rows && A->matrix[i] && B->matrix[i]) {
      int j = -1;
      while (++j < A->columns)
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
    if (i < A->rows) {
      res = INVALID_MATRIX;
      s21_remove_matrix(result);
    }
  }

  return res;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;

  if (!A || !B || !result || !A->matrix || !B->matrix || !A->rows ||
      !A->columns || !B->rows || !B->columns)
    res = INVALID_MATRIX;
  else if (A->rows != B->rows || A->columns != B->columns)
    res = CALCULATION_ERROR;
  else {
    s21_create_matrix(A->rows, A->columns, result);
    int i = -1;
    while (++i < A->rows && A->matrix[i] && B->matrix[i]) {
      int j = -1;
      while (++j < A->columns)
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
    if (i < A->rows) {
      res = INVALID_MATRIX;
      s21_remove_matrix(result);
    }
  }

  return res;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = OK;

  if (!A || !result || !A->matrix || !A->rows || !A->columns)
    res = INVALID_MATRIX;
  else {
    s21_create_matrix(A->rows, A->columns, result);
    int i = -1;
    while (++i < A->rows && A->matrix[i])
      for (int j = 0; j < A->columns; ++j)
        result->matrix[i][j] = A->matrix[i][j] * number;
    if (i < A->rows) {
      res = INVALID_MATRIX;
      s21_remove_matrix(result);
    }
  }

  return res;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;

  if (!A || !B || !result || !A->matrix || !B->matrix || !A->rows ||
      !A->columns || !B->rows || !B->columns)
    res = INVALID_MATRIX;
  else if (A->columns != B->rows)
    res = CALCULATION_ERROR;
  else {
    s21_create_matrix(A->rows, B->columns, result);
    int i = -1;
    while (++i < A->rows && A->matrix[i] && !res) {
      for (int j = 0; j < B->columns; ++j) {
        double sum = 0;
        int k = -1;
        while (++k < A->columns && B->matrix[k])
          sum += A->matrix[i][k] * B->matrix[k][j];
        if (k < A->columns) res = INVALID_MATRIX;
        result->matrix[i][j] = sum;
      }
    }
    if (i < A->rows || res) {
      res = INVALID_MATRIX;
      s21_remove_matrix(result);
    }
  }

  return res;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = OK;

  if (!A || !result || !A->matrix || !A->rows || !A->columns)
    res = INVALID_MATRIX;
  else {
    s21_create_matrix(A->columns, A->rows, result);
    int i = -1;
    while (++i < A->rows && A->matrix[i])
      for (int j = 0; j < A->columns; ++j)
        result->matrix[j][i] = A->matrix[i][j];
    if (i < A->rows) {
      res = INVALID_MATRIX;
      s21_remove_matrix(result);
    }
  }

  return res;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;

  if (!A || !result || !A->matrix || !A->rows || !A->columns)
    res = INVALID_MATRIX;
  else if (A->rows != A->columns)
    res = CALCULATION_ERROR;
  else if (A->rows == 1) {
    s21_create_matrix(1, 1, result);
    result->matrix[0][0] = A->matrix[0][0];
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    int i = -1;
    while (++i < A->rows && A->matrix[i]) {
      for (int j = 0; j < A->columns; ++j) {
        matrix_t minor = s21_create_minor(A, i, j);
        s21_determinant(&minor, &(result->matrix[i][j]));
        result->matrix[i][j] *= pow(-1, i + j);
        s21_remove_matrix(&minor);
      }
    }
    if (i < A->rows) {
      res = INVALID_MATRIX;
      s21_remove_matrix(result);
    }
  }

  return res;
}

matrix_t s21_create_minor(matrix_t *A, int i, int j) {
  matrix_t minor;
  s21_create_matrix(A->rows - 1, A->columns - 1, &minor);

  for (int k = 0; k < minor.rows; ++k) {
    for (int l = 0; l < minor.columns; ++l) {
      minor.matrix[k][l] = A->matrix[k < i ? k : k + 1][l < j ? l : l + 1];
    }
  }

  return minor;
}

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;

  if (!A || !result || !A->matrix || !A->rows || !A->columns)
    res = INVALID_MATRIX;
  else if (A->rows != A->columns)
    res = CALCULATION_ERROR;
  else {
    matrix_t A_triangle = {NULL, 0, 0};

    if (!s21_is_triangle(A, &res) && !res) {
      s21_create_matrix(A->rows, A->columns, &A_triangle);
      for (int i = 0; i < A->rows; ++i)
        for (int j = 0; j < A->columns; ++j)
          A_triangle.matrix[i][j] = A->matrix[i][j];
      for (int i = 0; i < A->rows; ++i) s21_null_column(&A_triangle, i);
    }

    if (!res) {
      *result = calculate_determinant(A_triangle.matrix ? &A_triangle : A);
      if (A_triangle.matrix) s21_remove_matrix(&A_triangle);
    }
  }

  return res;
}

bool s21_is_triangle(matrix_t *A, int *errno) {
  bool res = true;

  int i = -1;
  while (++i < A->rows && A->matrix[i] && res) {
    int j = -1;
    while (++j < i && res) res = A->matrix[i][j] ? false : true;
  }

  if (i < A->rows && !A->matrix[i]) *errno = INVALID_MATRIX;

  return res;
}

void s21_null_column(matrix_t *A, int j) {
  for (int i = j + 1; i < A->rows; ++i) {
    if (A->matrix[j][j]) {
      double coef = A->matrix[i][j] / A->matrix[j][j];
      for (int k = j; k < A->columns; ++k) {
        A->matrix[i][k] -= coef * A->matrix[j][k];
      }
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

  if ((res = s21_determinant(A, &det)) || !det || !result)
    res = res == INVALID_MATRIX || !result ? INVALID_MATRIX : CALCULATION_ERROR;
  else if (A->rows == 1) {
    s21_create_matrix(1, 1, result);
    result->matrix[0][0] = 1.0 / A->matrix[0][0];
  } else {
    matrix_t comp;
    matrix_t T;
    s21_calc_complements(A, &comp);
    s21_transpose(&comp, &T);
    s21_remove_matrix(&comp);
    s21_mult_number(&T, 1.0 / det, result);
    s21_remove_matrix(&T);
  }

  return res;
}