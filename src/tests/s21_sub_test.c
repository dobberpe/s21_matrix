#include "s21_matrix_test.h"

START_TEST(s21_sub_null_pointer) {
  // INVALID_MATRIX
  matrix_t A;
  matrix_t result;
  ck_assert_int_eq(s21_sub_matrix(&A, NULL, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_sub_null_pointer_res) {
  // INVALID_MATRIX
  matrix_t A;
  matrix_t B;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_sub_null_pointer_matrix) {
  // INVALID_MATRIX
  matrix_t A;
  A.matrix = NULL;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INVALID_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_null_pointer_rows) {
  // INVALID_MATRIX
  matrix_t A;
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double**)malloc(3 * sizeof(double*));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  A.matrix[2] = NULL;
  matrix_t B;
  matrix_t result;
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), INVALID_MATRIX);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_normal) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  matrix_t result;
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
}
END_TEST

START_TEST(s21_sub_normal2) {
  // CALCULATION_ERROR
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 4, &B);
  matrix_t result;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_sub_normal3) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      B.matrix[i][j] = i + j + 4;
      check.matrix[i][j] = -2;
    }
  }
  matrix_t result;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
}
END_TEST

START_TEST(s21_sub_normal4) {
  // INVALID_MATRIX
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 3, &B);
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
      B.matrix[i][j] = i + j + 4;
      check.matrix[i][j] = -2;
    }
  }
  B.matrix[0][2] = -1;
  check.matrix[0][2] = 5;
  matrix_t result;
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
}
END_TEST

Suite *s21_sub_cases(void) {
  Suite *c = suite_create("s21_sub_cases");
  TCase *tc = tcase_create("s21_sub_tc");
  tcase_add_test(tc, s21_sub_null_pointer);
  tcase_add_test(tc, s21_sub_null_pointer_res);
  tcase_add_test(tc, s21_sub_null_pointer_matrix);
  tcase_add_test(tc, s21_sub_null_pointer_rows);
  tcase_add_test(tc, s21_sub_normal);
  tcase_add_test(tc, s21_sub_normal2);
  tcase_add_test(tc, s21_sub_normal3);
  tcase_add_test(tc, s21_sub_normal4);
  suite_add_tcase(c, tc);
  return c;
}
