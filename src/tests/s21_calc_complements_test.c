#include "s21_matrix_test.h"

START_TEST(s21_calc_complements_null_pointer) {
  // INVALID_MATRIX
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(NULL, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements_null_pointer_res) {
  // INVALID_MATRIX
  matrix_t A;
  ck_assert_int_eq(s21_calc_complements(&A, NULL), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements_null_pointer_matrix) {
  // INVALID_MATRIX
  matrix_t A;
  A.matrix = NULL;
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(&A, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements_null_pointer_rows) {
  // INVALID_MATRIX
  matrix_t A;
  A.rows = 3;
  A.columns = 3;
  A.matrix = (double**)malloc(3 * sizeof(double*));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  A.matrix[2] = NULL;
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(&A, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_calc_complements_normal) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  matrix_t result;
  matrix_t check;
  s21_create_matrix(3, 3, &check);
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
}
END_TEST

START_TEST(s21_calc_complements_normal2) {
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
  check.matrix[0][0] = -1;
  check.matrix[0][1] = 2;
  check.matrix[0][2] = -1;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = -4;
  check.matrix[1][2] = 2;
  check.matrix[2][0] = -1;
  check.matrix[2][1] = 2;
  check.matrix[2][2] = -1;
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
}
END_TEST

START_TEST(s21_calc_complements_normal3) {
  // CALCULATION_ERROR
  matrix_t A;
  s21_create_matrix(3, 4, &A);
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_calc_complements_inf) {
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
  check.matrix[0][0] = -1;
  check.matrix[0][1] = INFINITY;
  check.matrix[0][2] = -INFINITY;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = -INFINITY;
  check.matrix[1][2] = INFINITY;
  check.matrix[2][0] = -1;
  check.matrix[2][1] = 2;
  check.matrix[2][2] = -1;
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
}
END_TEST

START_TEST(s21_calc_complements_inf_neg) {
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
  check.matrix[0][0] = -1;
  check.matrix[0][1] = -INFINITY;
  check.matrix[0][2] = INFINITY;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = INFINITY;
  check.matrix[1][2] = -INFINITY;
  check.matrix[2][0] = -1;
  check.matrix[2][1] = 2;
  check.matrix[2][2] = -1;
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
}
END_TEST

Suite *s21_calc_complements_cases(void) {
  Suite *c = suite_create("s21_calc_complements_cases");
  TCase *tc = tcase_create("s21_calc_complements_tc");
  tcase_add_test(tc, s21_calc_complements_null_pointer);
  tcase_add_test(tc, s21_calc_complements_null_pointer_res);
  tcase_add_test(tc, s21_calc_complements_null_pointer_matrix);
  tcase_add_test(tc, s21_calc_complements_null_pointer_rows);
  tcase_add_test(tc, s21_calc_complements_normal);
  tcase_add_test(tc, s21_calc_complements_normal2);
  tcase_add_test(tc, s21_calc_complements_normal3);
  tcase_add_test(tc, s21_calc_complements_inf);
  tcase_add_test(tc, s21_calc_complements_inf_neg);
  suite_add_tcase(c, tc);
  return c;
}
