#include "s21_matrix_test.h"

START_TEST(s21_transpose_null_pointer) {
  // INVALID_MATRIX
  matrix_t result;
  ck_assert_int_eq(s21_transpose(NULL, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_transpose_null_pointer_res) {
  // INVALID_MATRIX
  matrix_t A;
  ck_assert_int_eq(s21_transpose(&A, NULL), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_transpose_null_pointer_matrix) {
  // INVALID_MATRIX
  matrix_t A;
  A.matrix = NULL;
  matrix_t result;
  ck_assert_int_eq(s21_transpose(&A, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_transpose_null_pointer_rows) {
  // INVALID_MATRIX
  matrix_t A;
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double **)malloc(3 * sizeof(double *));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  A.matrix[2] = NULL;
  matrix_t result;
  ck_assert_int_eq(s21_transpose(&A, &result), INVALID_MATRIX);
  free(A.matrix);
}
END_TEST

START_TEST(s21_transpose_normal) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t result;
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_normal2) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
    }
  }
  check.matrix[0][0] = 2;
  check.matrix[0][1] = 3;
  check.matrix[0][2] = 4;
  check.matrix[1][0] = 3;
  check.matrix[1][1] = 4;
  check.matrix[1][2] = 5;
  check.matrix[2][0] = 4;
  check.matrix[2][1] = 5;
  check.matrix[2][2] = 6;
  matrix_t result;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_normal3) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 4, &A);
  matrix_t check;
  s21_create_matrix(4, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      check.matrix[j][i] = i + j + 2;
    }
  }
  matrix_t result;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_inf) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
    }
  }
  A.matrix[2][0] = INFINITY;
  check.matrix[0][0] = 2;
  check.matrix[0][1] = 3;
  check.matrix[0][2] = INFINITY;
  check.matrix[1][0] = 3;
  check.matrix[1][1] = 4;
  check.matrix[1][2] = 5;
  check.matrix[2][0] = 4;
  check.matrix[2][1] = 5;
  check.matrix[2][2] = 6;
  matrix_t result;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_transpose_inf_neg) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
    }
  }
  A.matrix[2][0] = -INFINITY;
  check.matrix[0][0] = 2;
  check.matrix[0][1] = 3;
  check.matrix[0][2] = -INFINITY;
  check.matrix[1][0] = 3;
  check.matrix[1][1] = 4;
  check.matrix[1][2] = 5;
  check.matrix[2][0] = 4;
  check.matrix[2][1] = 5;
  check.matrix[2][2] = 6;
  matrix_t result;
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

Suite *s21_transpose_cases(void) {
  Suite *c = suite_create("s21_transpose_cases");
  TCase *tc = tcase_create("s21_transpose_tc");
  tcase_add_test(tc, s21_transpose_null_pointer);
  tcase_add_test(tc, s21_transpose_null_pointer_res);
  tcase_add_test(tc, s21_transpose_null_pointer_matrix);
  tcase_add_test(tc, s21_transpose_null_pointer_rows);
  tcase_add_test(tc, s21_transpose_normal);
  tcase_add_test(tc, s21_transpose_normal2);
  tcase_add_test(tc, s21_transpose_normal3);
  tcase_add_test(tc, s21_transpose_inf);
  tcase_add_test(tc, s21_transpose_inf_neg);
  suite_add_tcase(c, tc);
  return c;
}
