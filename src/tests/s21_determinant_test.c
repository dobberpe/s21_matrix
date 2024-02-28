#include "s21_matrix_test.h"

START_TEST(s21_determinant_null_pointer) {
  // INVALID_MATRIX
  double result;
  ck_assert_int_eq(s21_determinant(NULL, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_determinant_null_pointer_res) {
  // INVALID_MATRIX
  matrix_t A;
  ck_assert_int_eq(s21_determinant(&A, NULL), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_determinant_null_pointer_matrix) {
  // INVALID_MATRIX
  matrix_t A;
  A.matrix = NULL;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_determinant_null_pointer_rows) {
  // INVALID_MATRIX
  matrix_t A;
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double**)malloc(3 * sizeof(double*));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  A.matrix[2] = NULL;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_determinant_normal) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
}
END_TEST

START_TEST(s21_determinant_normal2) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-198, result, S21_EPS);
}
END_TEST

START_TEST(s21_determinant_normal3) {
  // CALCULATION_ERROR
  matrix_t A;
  s21_create_matrix(3, 4, &A);
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_determinant_inf) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
    }
  }
  A.matrix[0][0] = INFINITY;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq(-INFINITY, result);
}
END_TEST

START_TEST(s21_determinant_inf_neg) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
    }
  }
  A.matrix[0][0] = -INFINITY;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq(INFINITY, result);
}
END_TEST

Suite *s21_determinant_cases(void) {
  Suite *c = suite_create("s21_determinant_cases");
  TCase *tc = tcase_create("s21_determinant_tc");
  tcase_add_test(tc, s21_determinant_null_pointer);
  tcase_add_test(tc, s21_determinant_null_pointer_res);
  tcase_add_test(tc, s21_determinant_null_pointer_matrix);
  tcase_add_test(tc, s21_determinant_null_pointer_rows);
  tcase_add_test(tc, s21_determinant_normal);
  tcase_add_test(tc, s21_determinant_normal2);
  tcase_add_test(tc, s21_determinant_normal3);
  tcase_add_test(tc, s21_determinant_inf);
  tcase_add_test(tc, s21_determinant_inf_neg);
  suite_add_tcase(c, tc);
  return c;
}
