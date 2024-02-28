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
  A.matrix = (double **)malloc(3 * sizeof(double *));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  A.matrix[2] = NULL;
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(&A, &result), INVALID_MATRIX);
  free(A.matrix);
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
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
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
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_normal3) {
  // CALCULATION_ERROR
  matrix_t A;
  s21_create_matrix(3, 4, &A);
  matrix_t result;
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
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
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
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
  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_calc_complements_02) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  s21_calc_complements(&A, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = -30.0;
  X.matrix[0][2] = -108.0;
  X.matrix[0][3] = 106.0;
  X.matrix[1][0] = 138.0;
  X.matrix[1][1] = -726.0;
  X.matrix[1][2] = -1137.0;
  X.matrix[1][3] = 1061.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 12.0;
  X.matrix[2][2] = 57.0;
  X.matrix[2][3] = -47.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 6.0;
  X.matrix[3][2] = -75.0;
  X.matrix[3][3] = 57.0;

  res = s21_eq_matrix(&X, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
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
  tcase_add_test(tc, s21_calc_complements_02);
  suite_add_tcase(c, tc);
  return c;
}
