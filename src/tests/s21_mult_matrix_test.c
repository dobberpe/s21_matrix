#include "s21_matrix_test.h"

START_TEST(s21_mult_matrix_null_pointer) {
  // INVALID_MATRIX
  matrix_t A;
  matrix_t result;
  ck_assert_int_eq(s21_mult_matrix(NULL, &A, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_mult_matrix_null_pointer_res) {
  // INVALID_MATRIX
  matrix_t A;
  matrix_t B;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_mult_matrix_null_pointer_matrix) {
  // INVALID_MATRIX
  matrix_t A;
  matrix_t B;
  A.matrix = NULL;
  matrix_t result;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_mult_matrix_null_pointer_rows) {
  // INVALID_MATRIX
  matrix_t A;
  A.rows = 2;
  A.columns = 3;
  A.matrix = (double**)malloc(2 * sizeof(double*));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  matrix_t B;
  s21_create_matrix(3, 1, &B);
  matrix_t result;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_mult_matrix_null_pointer_rows2) {
  // INVALID_MATRIX
  matrix_t A;
  A.rows = 2;
  A.columns = 3;
  A.matrix = (double**)malloc(2 * sizeof(double*));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  matrix_t B;
  s21_create_matrix(3, 2, &B);
  matrix_t result;
  ck_assert_int_eq(s21_mult_matrix(&B, &A, &result), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_mult_matrix_normal) {
  // OK
  matrix_t A;
  s21_create_matrix(2, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 1, &B);
  matrix_t result;
  matrix_t check;
  s21_create_matrix(2, 1, &check);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_normal2) {
  // CALCULATION_ERROR
  matrix_t A;
  s21_create_matrix(2, 3, &A);
  matrix_t B;
  s21_create_matrix(2, 1, &B);
  matrix_t result;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), CALCULATION_ERROR);
}
END_TEST

START_TEST(s21_mult_matrix_normal3) {
  // OK
  matrix_t A;
  s21_create_matrix(2, 3, &A);
  matrix_t B;
  s21_create_matrix(3, 1, &B);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
    }
  }
  for (int i = 0; i < B.rows; ++i) {
    for (int j = 0; j < B.columns; ++j) {
      B.matrix[i][j] = i + j + 2;
    }
  }
  matrix_t check;
  s21_create_matrix(2, 1, &check);
  check.matrix[0][0] = 29;
  check.matrix[1][0] = 38;
  matrix_t result;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_normal4) {
  // OK
  matrix_t A;
  s21_create_matrix(5, 10, &A);
  matrix_t B;
  s21_create_matrix(10, 2, &B);
  for (int i = 0; i < A.rows; ++i) {
    for (int j = 0; j < A.columns; ++j) {
      A.matrix[i][j] = i + j + 2;
    }
  }
  for (int i = 0; i < B.rows; ++i) {
    for (int j = 0; j < B.columns; ++j) {
      B.matrix[i][j] = i + j + 2;
    }
  }
  matrix_t check;
  s21_create_matrix(5, 2, &check);
  check.matrix[0][0] = 505;
  check.matrix[0][1] = 570;
  check.matrix[1][0] = 570;
  check.matrix[1][1] = 645;
  check.matrix[2][0] = 635;
  check.matrix[2][1] = 720;
  check.matrix[3][0] = 700;
  check.matrix[3][1] = 795;
  check.matrix[4][0] = 765;
  check.matrix[4][1] = 870;
  matrix_t result;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_inf) {
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
      B.matrix[i][j] = i + j + 2;
    }
  }
  B.matrix[2][0] = INFINITY;
  check.matrix[0][0] = INFINITY;
  check.matrix[0][1] = 38;
  check.matrix[0][2] = 47;
  check.matrix[1][0] = INFINITY;
  check.matrix[1][1] = 50;
  check.matrix[1][2] = 62;
  check.matrix[2][0] = INFINITY;
  check.matrix[2][1] = 62;
  check.matrix[2][2] = 77;
  matrix_t result;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
}
END_TEST

START_TEST(s21_mult_matrix_inf_neg) {
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
      B.matrix[i][j] = i + j + 2;
    }
  }
  B.matrix[2][0] = -INFINITY;
  check.matrix[0][0] = -INFINITY;
  check.matrix[0][1] = 38;
  check.matrix[0][2] = 47;
  check.matrix[1][0] = -INFINITY;
  check.matrix[1][1] = 50;
  check.matrix[1][2] = 62;
  check.matrix[2][0] = -INFINITY;
  check.matrix[2][1] = 62;
  check.matrix[2][2] = 77;
  matrix_t result;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);
}
END_TEST

Suite *s21_mult_matrix_cases(void) {
  Suite *c = suite_create("s21_mult_matrix_cases");
  TCase *tc = tcase_create("s21_mult_matrix_tc");
  tcase_add_test(tc, s21_mult_matrix_null_pointer);
  tcase_add_test(tc, s21_mult_matrix_null_pointer_res);
  tcase_add_test(tc, s21_mult_matrix_null_pointer_matrix);
  tcase_add_test(tc, s21_mult_matrix_null_pointer_rows);
  tcase_add_test(tc, s21_mult_matrix_null_pointer_rows2);
  tcase_add_test(tc, s21_mult_matrix_normal);
  tcase_add_test(tc, s21_mult_matrix_normal2);
  tcase_add_test(tc, s21_mult_matrix_normal3);
  tcase_add_test(tc, s21_mult_matrix_normal4);
  tcase_add_test(tc, s21_mult_matrix_inf);
  tcase_add_test(tc, s21_mult_matrix_inf_neg);
  suite_add_tcase(c, tc);
  return c;
}
