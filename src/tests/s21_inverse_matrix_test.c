#include "s21_matrix_test.h"

START_TEST(s21_inverse_matrix_null_pointer) {
  // INVALID_MATRIX
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(NULL, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix_null_pointer_res) {
  // INVALID_MATRIX
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_inverse_matrix(&A, NULL), INVALID_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_null_pointer_matrix) {
  // INVALID_MATRIX
  matrix_t A;
  A.matrix = NULL;
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_inverse_matrix_null_pointer_rows) {
  // INVALID_MATRIX
  matrix_t A;
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double **)malloc(3 * sizeof(double *));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  A.matrix[2] = NULL;
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), INVALID_MATRIX);
  free(A.matrix);
}
END_TEST

START_TEST(s21_inverse_matrix_normal) {
  // CALCULATION_ERROR
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_normal2) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  check.matrix[0][0] = -13.0 / 198.0;
  check.matrix[0][1] = 29.0 / 198.0;
  check.matrix[0][2] = -7.0 / 198.0;
  check.matrix[1][0] = 5.0 / 22.0;
  check.matrix[1][1] = -1.0 / 22.0;
  check.matrix[1][2] = 1.0 / 22.0;
  check.matrix[2][0] = -2.0 / 9.0;
  check.matrix[2][1] = 1.0 / 9.0;
  check.matrix[2][2] = 1.0 / 9.0;
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_normal3) {
  // CALCULATION_ERROR
  matrix_t A;
  s21_create_matrix(3, 4, &A);
  matrix_t result;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_inverse_matrix_cases(void) {
  Suite *c = suite_create("s21_inverse_matrix_cases");
  TCase *tc = tcase_create("s21_inverse_matrix_tc");
  tcase_add_test(tc, s21_inverse_matrix_null_pointer);
  tcase_add_test(tc, s21_inverse_matrix_null_pointer_res);
  tcase_add_test(tc, s21_inverse_matrix_null_pointer_matrix);
  tcase_add_test(tc, s21_inverse_matrix_null_pointer_rows);
  tcase_add_test(tc, s21_inverse_matrix_normal);
  tcase_add_test(tc, s21_inverse_matrix_normal2);
  tcase_add_test(tc, s21_inverse_matrix_normal3);
  suite_add_tcase(c, tc);
  return c;
}
