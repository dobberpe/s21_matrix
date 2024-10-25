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
  A.matrix = (double **)malloc(3 * sizeof(double *));
  A.matrix[0] = NULL;
  A.matrix[1] = NULL;
  A.matrix[2] = NULL;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), INVALID_MATRIX);
  free(A.matrix);
}
END_TEST

START_TEST(s21_determinant_normal) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
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
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal3) {
  // CALCULATION_ERROR
  matrix_t A;
  s21_create_matrix(3, 4, &A);
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal4) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
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
  ck_assert_double_eq_tol(-224, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal5) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-18, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal6) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-154, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal7) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(5, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal8) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-225, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal9) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-176, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal10) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-177, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal11) {
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
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-153, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal12) {
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
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-66, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal13) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-44, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal14) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-180, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal15) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-21, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal16) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-215, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal17) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-212, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal18) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-203, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal19) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-189, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal20) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-56, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal21) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(26, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal22) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(17, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal23) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-45, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal24) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-8, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal25) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal26) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(27, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal27) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-54, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal28) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(14, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal29) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-190, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal30) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-132, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal31) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-142, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal32) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-144, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal33) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-22, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal34) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-22, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal35) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(27, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal36) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(26, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal37) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(15, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal38) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-31, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal39) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-203, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal40) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-213, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal41) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-180, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal42) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-57, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal43) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-167, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal44) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-141, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal45) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-44, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal46) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-132, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal47) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-45, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal48) {
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
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-21, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal49) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal50) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal51) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal52) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-44, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal53) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal54) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal55) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-44, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal56) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal57) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-180, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal58) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal59) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal60) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-180, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal61) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal62) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal63) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal64) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal65) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-21, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal66) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-21, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal67) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-203, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal68) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-203, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal69) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-180, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal70) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-47, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal71) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-203, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal72) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-177, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal73) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-44, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal74) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal75) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal76) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-21, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal77) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(26, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal78) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal79) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal80) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(26, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal81) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal82) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal83) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal84) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(27, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal85) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(26, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal86) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(27, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal87) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-19, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal88) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal89) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-45, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal90) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal91) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-45, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal92) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(1, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal93) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(27, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal94) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-44, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal95) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal96) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-45, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal97) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal98) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-22, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal99) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal100) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(26, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal101) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(24, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal102) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-22, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal103) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal104) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-178, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal105) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-180, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal106) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-22, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal107) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-132, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal108) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-132, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal109) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal110) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-132, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal510) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal111) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal112) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal113) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal114) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal115) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-22, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal116) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal117) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(27, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal118) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal119) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal120) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal121) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-21, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal122) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-203, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal123) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal124) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal125) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal126) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-45, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal127) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal128) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-132, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal129) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal130) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal131) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal132) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal133) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal134) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal135) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal136) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal137) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal138) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal139) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal140) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal141) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal142) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal143) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal144) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal145) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal146) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal147) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal148) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal149) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-44, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal150) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal151) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal152) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal153) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal154) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal155) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal156) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal157) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal158) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal159) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal160) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-180, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal161) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal162) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal163) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal164) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal165) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal166) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal167) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal168) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal169) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal170) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal171) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal172) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal173) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal174) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal175) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal176) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal177) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-21, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal178) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-203, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal179) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal180) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal181) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal182) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal183) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal184) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal185) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal186) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal187) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal188) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal189) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal190) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(26, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal191) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal192) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal193) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal194) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal195) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal196) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal197) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal198) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal199) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal200) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal201) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal202) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal203) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal204) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal205) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal206) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal207) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal208) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(27, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal209) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal210) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal211) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal212) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal213) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal214) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal215) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal216) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal217) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-45, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal218) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal219) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal220) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal221) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal222) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal223) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal224) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal225) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal226) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-22, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal227) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal228) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal229) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal230) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal231) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal232) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal233) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal234) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal235) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal236) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal237) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal238) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal239) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-132, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal240) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal241) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal242) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal243) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal244) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal245) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal246) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal247) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal248) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal249) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal250) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal251) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal252) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal253) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal502) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal503) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal504) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal505) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal254) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal255) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal256) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal257) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal258) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal259) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal260) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal261) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal262) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal263) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal264) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal265) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal266) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal267) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal268) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal269) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal270) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal271) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal272) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal273) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal274) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal275) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal276) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal277) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal278) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal279) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal280) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal281) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal282) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal283) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal284) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal285) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal286) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal287) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal288) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal289) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal290) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal291) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal292) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal293) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal294) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal295) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal296) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal297) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal298) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal299) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal300) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal301) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal302) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal303) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal304) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal305) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal306) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal307) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal308) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal309) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal310) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal311) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal312) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal313) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal314) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal315) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal316) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal317) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal318) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal319) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal320) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal321) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal322) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal323) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal324) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal325) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal326) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal327) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal328) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal329) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal330) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal331) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal332) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal333) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal334) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal335) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal336) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal337) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal338) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal339) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal340) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal341) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal342) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal343) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal344) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal345) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal346) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal347) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal348) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal349) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal350) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal351) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal352) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal353) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal354) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal355) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal356) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal357) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal358) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal359) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal360) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal361) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal362) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal363) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal364) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal365) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal366) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal367) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal368) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal369) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal370) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal371) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal372) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal373) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal374) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal375) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal376) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal377) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal378) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal379) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal380) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal381) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal382) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal383) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal384) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal385) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal386) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal387) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal388) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal389) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal390) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal391) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal392) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal393) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal394) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal395) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal396) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal511) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal397) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal398) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal399) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal400) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal401) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal402) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal403) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal404) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal405) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal406) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal407) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-9, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal408) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal409) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal410) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-35, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal411) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal412) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal413) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal414) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal415) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal416) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal417) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal418) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal419) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-12, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal420) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal421) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal422) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal423) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal424) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-168, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal425) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal426) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal427) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal428) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal429) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal430) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal431) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal432) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal433) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal434) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal435) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal436) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal437) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal438) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal439) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(-10, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal440) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal441) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(36, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal442) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal443) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal444) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal445) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal446) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal447) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal448) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal449) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal450) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal451) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal452) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal453) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal454) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal455) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal456) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal506) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal507) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal508) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal509) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal512) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal513) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal457) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal458) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal459) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal460) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal461) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal462) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal463) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal464) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal465) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal466) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal467) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal468) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal469) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal470) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal471) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal472) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal473) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal474) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal475) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal476) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal477) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal478) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal479) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal480) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal481) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal482) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal483) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal484) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal485) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal486) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal487) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal488) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal489) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal490) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal491) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal492) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal493) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 6;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal494) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal495) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = -3;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal496) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal497) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal498) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 7;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal499) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = -1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal500) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 4;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_normal501) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;
  double result;
  ck_assert_int_eq(s21_determinant(&A, &result), OK);
  ck_assert_double_eq_tol(0, result, S21_EPS);
  s21_remove_matrix(&A);
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
  s21_remove_matrix(&A);
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
  s21_remove_matrix(&A);
}
END_TEST

void s21_init_matrix(double number, matrix_t *A) {
  for (int x = 0; x < A->rows; x += 1) {
    for (int y = 0; y < A->columns; number += 1.0, y += 1)
      A->matrix[x][y] = number;
  }
}

START_TEST(s21_determinant_06) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(8, 8, &A);
  s21_init_matrix(1.0, &A);

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 0.0);
  s21_remove_matrix(&A);
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
  tcase_add_test(tc, s21_determinant_normal4);
  tcase_add_test(tc, s21_determinant_normal5);
  tcase_add_test(tc, s21_determinant_normal6);
  tcase_add_test(tc, s21_determinant_normal7);
  tcase_add_test(tc, s21_determinant_normal8);
  tcase_add_test(tc, s21_determinant_normal9);
  tcase_add_test(tc, s21_determinant_normal10);
  tcase_add_test(tc, s21_determinant_normal11);
  tcase_add_test(tc, s21_determinant_normal12);
  tcase_add_test(tc, s21_determinant_normal13);
  tcase_add_test(tc, s21_determinant_normal14);
  tcase_add_test(tc, s21_determinant_normal15);
  tcase_add_test(tc, s21_determinant_normal16);
  tcase_add_test(tc, s21_determinant_normal17);
  tcase_add_test(tc, s21_determinant_normal18);
  tcase_add_test(tc, s21_determinant_normal19);
  tcase_add_test(tc, s21_determinant_normal20);
  tcase_add_test(tc, s21_determinant_normal21);
  tcase_add_test(tc, s21_determinant_normal22);
  tcase_add_test(tc, s21_determinant_normal23);
  tcase_add_test(tc, s21_determinant_normal24);
  tcase_add_test(tc, s21_determinant_normal25);
  tcase_add_test(tc, s21_determinant_normal26);
  tcase_add_test(tc, s21_determinant_normal27);
  tcase_add_test(tc, s21_determinant_normal28);
  tcase_add_test(tc, s21_determinant_normal29);
  tcase_add_test(tc, s21_determinant_normal30);
  tcase_add_test(tc, s21_determinant_normal31);
  tcase_add_test(tc, s21_determinant_normal32);
  tcase_add_test(tc, s21_determinant_normal33);
  tcase_add_test(tc, s21_determinant_normal34);
  tcase_add_test(tc, s21_determinant_normal35);
  tcase_add_test(tc, s21_determinant_normal36);
  tcase_add_test(tc, s21_determinant_normal37);
  tcase_add_test(tc, s21_determinant_normal38);
  tcase_add_test(tc, s21_determinant_normal39);
  tcase_add_test(tc, s21_determinant_normal40);
  tcase_add_test(tc, s21_determinant_normal41);
  tcase_add_test(tc, s21_determinant_normal42);
  tcase_add_test(tc, s21_determinant_normal43);
  tcase_add_test(tc, s21_determinant_normal44);
  tcase_add_test(tc, s21_determinant_normal45);
  tcase_add_test(tc, s21_determinant_normal46);
  tcase_add_test(tc, s21_determinant_normal47);
  tcase_add_test(tc, s21_determinant_normal48);
  tcase_add_test(tc, s21_determinant_normal49);
  tcase_add_test(tc, s21_determinant_normal50);
  tcase_add_test(tc, s21_determinant_normal51);
  tcase_add_test(tc, s21_determinant_normal52);
  tcase_add_test(tc, s21_determinant_normal53);
  tcase_add_test(tc, s21_determinant_normal54);
  tcase_add_test(tc, s21_determinant_normal55);
  tcase_add_test(tc, s21_determinant_normal56);
  tcase_add_test(tc, s21_determinant_normal57);
  tcase_add_test(tc, s21_determinant_normal58);
  tcase_add_test(tc, s21_determinant_normal59);
  tcase_add_test(tc, s21_determinant_normal60);
  tcase_add_test(tc, s21_determinant_normal61);
  tcase_add_test(tc, s21_determinant_normal62);
  tcase_add_test(tc, s21_determinant_normal63);
  tcase_add_test(tc, s21_determinant_normal64);
  tcase_add_test(tc, s21_determinant_normal65);
  tcase_add_test(tc, s21_determinant_normal66);
  tcase_add_test(tc, s21_determinant_normal67);
  tcase_add_test(tc, s21_determinant_normal68);
  tcase_add_test(tc, s21_determinant_normal69);
  tcase_add_test(tc, s21_determinant_normal70);
  tcase_add_test(tc, s21_determinant_normal71);
  tcase_add_test(tc, s21_determinant_normal72);
  tcase_add_test(tc, s21_determinant_normal73);
  tcase_add_test(tc, s21_determinant_normal74);
  tcase_add_test(tc, s21_determinant_normal75);
  tcase_add_test(tc, s21_determinant_normal76);
  tcase_add_test(tc, s21_determinant_normal77);
  tcase_add_test(tc, s21_determinant_normal78);
  tcase_add_test(tc, s21_determinant_normal79);
  tcase_add_test(tc, s21_determinant_normal80);
  tcase_add_test(tc, s21_determinant_normal81);
  tcase_add_test(tc, s21_determinant_normal82);
  tcase_add_test(tc, s21_determinant_normal83);
  tcase_add_test(tc, s21_determinant_normal84);
  tcase_add_test(tc, s21_determinant_normal85);
  tcase_add_test(tc, s21_determinant_normal86);
  tcase_add_test(tc, s21_determinant_normal87);
  tcase_add_test(tc, s21_determinant_normal88);
  tcase_add_test(tc, s21_determinant_normal89);
  tcase_add_test(tc, s21_determinant_normal90);
  tcase_add_test(tc, s21_determinant_normal91);
  tcase_add_test(tc, s21_determinant_normal92);
  tcase_add_test(tc, s21_determinant_normal93);
  tcase_add_test(tc, s21_determinant_normal94);
  tcase_add_test(tc, s21_determinant_normal95);
  tcase_add_test(tc, s21_determinant_normal96);
  tcase_add_test(tc, s21_determinant_normal97);
  tcase_add_test(tc, s21_determinant_normal98);
  tcase_add_test(tc, s21_determinant_normal99);
  tcase_add_test(tc, s21_determinant_normal100);
  tcase_add_test(tc, s21_determinant_normal101);
  tcase_add_test(tc, s21_determinant_normal102);
  tcase_add_test(tc, s21_determinant_normal103);
  tcase_add_test(tc, s21_determinant_normal104);
  tcase_add_test(tc, s21_determinant_normal105);
  tcase_add_test(tc, s21_determinant_normal106);
  tcase_add_test(tc, s21_determinant_normal107);
  tcase_add_test(tc, s21_determinant_normal108);
  tcase_add_test(tc, s21_determinant_normal109);
  tcase_add_test(tc, s21_determinant_normal110);
  tcase_add_test(tc, s21_determinant_normal111);
  tcase_add_test(tc, s21_determinant_normal112);
  tcase_add_test(tc, s21_determinant_normal113);
  tcase_add_test(tc, s21_determinant_normal114);
  tcase_add_test(tc, s21_determinant_normal115);
  tcase_add_test(tc, s21_determinant_normal116);
  tcase_add_test(tc, s21_determinant_normal117);
  tcase_add_test(tc, s21_determinant_normal118);
  tcase_add_test(tc, s21_determinant_normal119);
  tcase_add_test(tc, s21_determinant_normal120);
  tcase_add_test(tc, s21_determinant_normal121);
  tcase_add_test(tc, s21_determinant_normal122);
  tcase_add_test(tc, s21_determinant_normal123);
  tcase_add_test(tc, s21_determinant_normal124);
  tcase_add_test(tc, s21_determinant_normal125);
  tcase_add_test(tc, s21_determinant_normal126);
  tcase_add_test(tc, s21_determinant_normal127);
  tcase_add_test(tc, s21_determinant_normal128);
  tcase_add_test(tc, s21_determinant_normal129);
  tcase_add_test(tc, s21_determinant_normal130);
  tcase_add_test(tc, s21_determinant_normal131);
  tcase_add_test(tc, s21_determinant_normal132);
  tcase_add_test(tc, s21_determinant_normal133);
  tcase_add_test(tc, s21_determinant_normal134);
  tcase_add_test(tc, s21_determinant_normal135);
  tcase_add_test(tc, s21_determinant_normal136);
  tcase_add_test(tc, s21_determinant_normal137);
  tcase_add_test(tc, s21_determinant_normal138);
  tcase_add_test(tc, s21_determinant_normal139);
  tcase_add_test(tc, s21_determinant_normal140);
  tcase_add_test(tc, s21_determinant_normal141);
  tcase_add_test(tc, s21_determinant_normal142);
  tcase_add_test(tc, s21_determinant_normal143);
  tcase_add_test(tc, s21_determinant_normal144);
  tcase_add_test(tc, s21_determinant_normal145);
  tcase_add_test(tc, s21_determinant_normal146);
  tcase_add_test(tc, s21_determinant_normal147);
  tcase_add_test(tc, s21_determinant_normal148);
  tcase_add_test(tc, s21_determinant_normal149);
  tcase_add_test(tc, s21_determinant_normal150);
  tcase_add_test(tc, s21_determinant_normal151);
  tcase_add_test(tc, s21_determinant_normal152);
  tcase_add_test(tc, s21_determinant_normal153);
  tcase_add_test(tc, s21_determinant_normal154);
  tcase_add_test(tc, s21_determinant_normal155);
  tcase_add_test(tc, s21_determinant_normal156);
  tcase_add_test(tc, s21_determinant_normal157);
  tcase_add_test(tc, s21_determinant_normal158);
  tcase_add_test(tc, s21_determinant_normal159);
  tcase_add_test(tc, s21_determinant_normal160);
  tcase_add_test(tc, s21_determinant_normal161);
  tcase_add_test(tc, s21_determinant_normal162);
  tcase_add_test(tc, s21_determinant_normal163);
  tcase_add_test(tc, s21_determinant_normal164);
  tcase_add_test(tc, s21_determinant_normal165);
  tcase_add_test(tc, s21_determinant_normal166);
  tcase_add_test(tc, s21_determinant_normal167);
  tcase_add_test(tc, s21_determinant_normal168);
  tcase_add_test(tc, s21_determinant_normal169);
  tcase_add_test(tc, s21_determinant_normal170);
  tcase_add_test(tc, s21_determinant_normal171);
  tcase_add_test(tc, s21_determinant_normal172);
  tcase_add_test(tc, s21_determinant_normal173);
  tcase_add_test(tc, s21_determinant_normal174);
  tcase_add_test(tc, s21_determinant_normal175);
  tcase_add_test(tc, s21_determinant_normal176);
  tcase_add_test(tc, s21_determinant_normal177);
  tcase_add_test(tc, s21_determinant_normal178);
  tcase_add_test(tc, s21_determinant_normal179);
  tcase_add_test(tc, s21_determinant_normal180);
  tcase_add_test(tc, s21_determinant_normal181);
  tcase_add_test(tc, s21_determinant_normal182);
  tcase_add_test(tc, s21_determinant_normal183);
  tcase_add_test(tc, s21_determinant_normal184);
  tcase_add_test(tc, s21_determinant_normal185);
  tcase_add_test(tc, s21_determinant_normal186);
  tcase_add_test(tc, s21_determinant_normal187);
  tcase_add_test(tc, s21_determinant_normal188);
  tcase_add_test(tc, s21_determinant_normal189);
  tcase_add_test(tc, s21_determinant_normal190);
  tcase_add_test(tc, s21_determinant_normal191);
  tcase_add_test(tc, s21_determinant_normal192);
  tcase_add_test(tc, s21_determinant_normal193);
  tcase_add_test(tc, s21_determinant_normal194);
  tcase_add_test(tc, s21_determinant_normal195);
  tcase_add_test(tc, s21_determinant_normal196);
  tcase_add_test(tc, s21_determinant_normal197);
  tcase_add_test(tc, s21_determinant_normal198);
  tcase_add_test(tc, s21_determinant_normal199);
  tcase_add_test(tc, s21_determinant_normal200);
  tcase_add_test(tc, s21_determinant_normal200);
  tcase_add_test(tc, s21_determinant_normal201);
  tcase_add_test(tc, s21_determinant_normal202);
  tcase_add_test(tc, s21_determinant_normal203);
  tcase_add_test(tc, s21_determinant_normal204);
  tcase_add_test(tc, s21_determinant_normal205);
  tcase_add_test(tc, s21_determinant_normal206);
  tcase_add_test(tc, s21_determinant_normal207);
  tcase_add_test(tc, s21_determinant_normal208);
  tcase_add_test(tc, s21_determinant_normal209);
  tcase_add_test(tc, s21_determinant_normal210);
  tcase_add_test(tc, s21_determinant_normal211);
  tcase_add_test(tc, s21_determinant_normal212);
  tcase_add_test(tc, s21_determinant_normal213);
  tcase_add_test(tc, s21_determinant_normal214);
  tcase_add_test(tc, s21_determinant_normal215);
  tcase_add_test(tc, s21_determinant_normal216);
  tcase_add_test(tc, s21_determinant_normal217);
  tcase_add_test(tc, s21_determinant_normal218);
  tcase_add_test(tc, s21_determinant_normal219);
  tcase_add_test(tc, s21_determinant_normal220);
  tcase_add_test(tc, s21_determinant_normal221);
  tcase_add_test(tc, s21_determinant_normal222);
  tcase_add_test(tc, s21_determinant_normal223);
  tcase_add_test(tc, s21_determinant_normal224);
  tcase_add_test(tc, s21_determinant_normal225);
  tcase_add_test(tc, s21_determinant_normal226);
  tcase_add_test(tc, s21_determinant_normal227);
  tcase_add_test(tc, s21_determinant_normal228);
  tcase_add_test(tc, s21_determinant_normal229);
  tcase_add_test(tc, s21_determinant_normal230);
  tcase_add_test(tc, s21_determinant_normal231);
  tcase_add_test(tc, s21_determinant_normal232);
  tcase_add_test(tc, s21_determinant_normal233);
  tcase_add_test(tc, s21_determinant_normal234);
  tcase_add_test(tc, s21_determinant_normal235);
  tcase_add_test(tc, s21_determinant_normal236);
  tcase_add_test(tc, s21_determinant_normal237);
  tcase_add_test(tc, s21_determinant_normal238);
  tcase_add_test(tc, s21_determinant_normal239);
  tcase_add_test(tc, s21_determinant_normal240);
  tcase_add_test(tc, s21_determinant_normal241);
  tcase_add_test(tc, s21_determinant_normal242);
  tcase_add_test(tc, s21_determinant_normal243);
  tcase_add_test(tc, s21_determinant_normal244);
  tcase_add_test(tc, s21_determinant_normal245);
  tcase_add_test(tc, s21_determinant_normal246);
  tcase_add_test(tc, s21_determinant_normal247);
  tcase_add_test(tc, s21_determinant_normal248);
  tcase_add_test(tc, s21_determinant_normal249);
  tcase_add_test(tc, s21_determinant_normal250);
  tcase_add_test(tc, s21_determinant_normal251);
  tcase_add_test(tc, s21_determinant_normal252);
  tcase_add_test(tc, s21_determinant_normal253);
  tcase_add_test(tc, s21_determinant_normal254);
  tcase_add_test(tc, s21_determinant_normal255);
  tcase_add_test(tc, s21_determinant_normal256);
  tcase_add_test(tc, s21_determinant_normal257);
  tcase_add_test(tc, s21_determinant_normal258);
  tcase_add_test(tc, s21_determinant_normal259);
  tcase_add_test(tc, s21_determinant_normal260);
  tcase_add_test(tc, s21_determinant_normal261);
  tcase_add_test(tc, s21_determinant_normal262);
  tcase_add_test(tc, s21_determinant_normal263);
  tcase_add_test(tc, s21_determinant_normal264);
  tcase_add_test(tc, s21_determinant_normal265);
  tcase_add_test(tc, s21_determinant_normal266);
  tcase_add_test(tc, s21_determinant_normal267);
  tcase_add_test(tc, s21_determinant_normal268);
  tcase_add_test(tc, s21_determinant_normal269);
  tcase_add_test(tc, s21_determinant_normal270);
  tcase_add_test(tc, s21_determinant_normal271);
  tcase_add_test(tc, s21_determinant_normal272);
  tcase_add_test(tc, s21_determinant_normal273);
  tcase_add_test(tc, s21_determinant_normal274);
  tcase_add_test(tc, s21_determinant_normal275);
  tcase_add_test(tc, s21_determinant_normal276);
  tcase_add_test(tc, s21_determinant_normal277);
  tcase_add_test(tc, s21_determinant_normal278);
  tcase_add_test(tc, s21_determinant_normal279);
  tcase_add_test(tc, s21_determinant_normal280);
  tcase_add_test(tc, s21_determinant_normal281);
  tcase_add_test(tc, s21_determinant_normal282);
  tcase_add_test(tc, s21_determinant_normal283);
  tcase_add_test(tc, s21_determinant_normal284);
  tcase_add_test(tc, s21_determinant_normal285);
  tcase_add_test(tc, s21_determinant_normal286);
  tcase_add_test(tc, s21_determinant_normal287);
  tcase_add_test(tc, s21_determinant_normal288);
  tcase_add_test(tc, s21_determinant_normal289);
  tcase_add_test(tc, s21_determinant_normal290);
  tcase_add_test(tc, s21_determinant_normal291);
  tcase_add_test(tc, s21_determinant_normal292);
  tcase_add_test(tc, s21_determinant_normal293);
  tcase_add_test(tc, s21_determinant_normal294);
  tcase_add_test(tc, s21_determinant_normal295);
  tcase_add_test(tc, s21_determinant_normal296);
  tcase_add_test(tc, s21_determinant_normal297);
  tcase_add_test(tc, s21_determinant_normal298);
  tcase_add_test(tc, s21_determinant_normal299);
  tcase_add_test(tc, s21_determinant_normal300);
  tcase_add_test(tc, s21_determinant_normal300);
  tcase_add_test(tc, s21_determinant_normal301);
  tcase_add_test(tc, s21_determinant_normal302);
  tcase_add_test(tc, s21_determinant_normal303);
  tcase_add_test(tc, s21_determinant_normal304);
  tcase_add_test(tc, s21_determinant_normal305);
  tcase_add_test(tc, s21_determinant_normal306);
  tcase_add_test(tc, s21_determinant_normal307);
  tcase_add_test(tc, s21_determinant_normal308);
  tcase_add_test(tc, s21_determinant_normal309);
  tcase_add_test(tc, s21_determinant_normal310);
  tcase_add_test(tc, s21_determinant_normal311);
  tcase_add_test(tc, s21_determinant_normal312);
  tcase_add_test(tc, s21_determinant_normal313);
  tcase_add_test(tc, s21_determinant_normal314);
  tcase_add_test(tc, s21_determinant_normal315);
  tcase_add_test(tc, s21_determinant_normal316);
  tcase_add_test(tc, s21_determinant_normal317);
  tcase_add_test(tc, s21_determinant_normal318);
  tcase_add_test(tc, s21_determinant_normal319);
  tcase_add_test(tc, s21_determinant_normal320);
  tcase_add_test(tc, s21_determinant_normal321);
  tcase_add_test(tc, s21_determinant_normal322);
  tcase_add_test(tc, s21_determinant_normal323);
  tcase_add_test(tc, s21_determinant_normal324);
  tcase_add_test(tc, s21_determinant_normal325);
  tcase_add_test(tc, s21_determinant_normal326);
  tcase_add_test(tc, s21_determinant_normal327);
  tcase_add_test(tc, s21_determinant_normal328);
  tcase_add_test(tc, s21_determinant_normal329);
  tcase_add_test(tc, s21_determinant_normal330);
  tcase_add_test(tc, s21_determinant_normal331);
  tcase_add_test(tc, s21_determinant_normal332);
  tcase_add_test(tc, s21_determinant_normal333);
  tcase_add_test(tc, s21_determinant_normal334);
  tcase_add_test(tc, s21_determinant_normal335);
  tcase_add_test(tc, s21_determinant_normal336);
  tcase_add_test(tc, s21_determinant_normal337);
  tcase_add_test(tc, s21_determinant_normal338);
  tcase_add_test(tc, s21_determinant_normal339);
  tcase_add_test(tc, s21_determinant_normal340);
  tcase_add_test(tc, s21_determinant_normal341);
  tcase_add_test(tc, s21_determinant_normal342);
  tcase_add_test(tc, s21_determinant_normal343);
  tcase_add_test(tc, s21_determinant_normal344);
  tcase_add_test(tc, s21_determinant_normal345);
  tcase_add_test(tc, s21_determinant_normal346);
  tcase_add_test(tc, s21_determinant_normal347);
  tcase_add_test(tc, s21_determinant_normal348);
  tcase_add_test(tc, s21_determinant_normal349);
  tcase_add_test(tc, s21_determinant_normal350);
  tcase_add_test(tc, s21_determinant_normal351);
  tcase_add_test(tc, s21_determinant_normal352);
  tcase_add_test(tc, s21_determinant_normal353);
  tcase_add_test(tc, s21_determinant_normal354);
  tcase_add_test(tc, s21_determinant_normal355);
  tcase_add_test(tc, s21_determinant_normal356);
  tcase_add_test(tc, s21_determinant_normal357);
  tcase_add_test(tc, s21_determinant_normal358);
  tcase_add_test(tc, s21_determinant_normal359);
  tcase_add_test(tc, s21_determinant_normal360);
  tcase_add_test(tc, s21_determinant_normal361);
  tcase_add_test(tc, s21_determinant_normal362);
  tcase_add_test(tc, s21_determinant_normal363);
  tcase_add_test(tc, s21_determinant_normal364);
  tcase_add_test(tc, s21_determinant_normal365);
  tcase_add_test(tc, s21_determinant_normal366);
  tcase_add_test(tc, s21_determinant_normal367);
  tcase_add_test(tc, s21_determinant_normal368);
  tcase_add_test(tc, s21_determinant_normal369);
  tcase_add_test(tc, s21_determinant_normal370);
  tcase_add_test(tc, s21_determinant_normal371);
  tcase_add_test(tc, s21_determinant_normal372);
  tcase_add_test(tc, s21_determinant_normal373);
  tcase_add_test(tc, s21_determinant_normal374);
  tcase_add_test(tc, s21_determinant_normal375);
  tcase_add_test(tc, s21_determinant_normal376);
  tcase_add_test(tc, s21_determinant_normal377);
  tcase_add_test(tc, s21_determinant_normal378);
  tcase_add_test(tc, s21_determinant_normal379);
  tcase_add_test(tc, s21_determinant_normal380);
  tcase_add_test(tc, s21_determinant_normal381);
  tcase_add_test(tc, s21_determinant_normal382);
  tcase_add_test(tc, s21_determinant_normal383);
  tcase_add_test(tc, s21_determinant_normal384);
  tcase_add_test(tc, s21_determinant_normal385);
  tcase_add_test(tc, s21_determinant_normal386);
  tcase_add_test(tc, s21_determinant_normal387);
  tcase_add_test(tc, s21_determinant_normal388);
  tcase_add_test(tc, s21_determinant_normal389);
  tcase_add_test(tc, s21_determinant_normal390);
  tcase_add_test(tc, s21_determinant_normal391);
  tcase_add_test(tc, s21_determinant_normal392);
  tcase_add_test(tc, s21_determinant_normal393);
  tcase_add_test(tc, s21_determinant_normal394);
  tcase_add_test(tc, s21_determinant_normal395);
  tcase_add_test(tc, s21_determinant_normal396);
  tcase_add_test(tc, s21_determinant_normal397);
  tcase_add_test(tc, s21_determinant_normal398);
  tcase_add_test(tc, s21_determinant_normal399);
  tcase_add_test(tc, s21_determinant_normal400);
  tcase_add_test(tc, s21_determinant_normal400);
  tcase_add_test(tc, s21_determinant_normal401);
  tcase_add_test(tc, s21_determinant_normal402);
  tcase_add_test(tc, s21_determinant_normal403);
  tcase_add_test(tc, s21_determinant_normal404);
  tcase_add_test(tc, s21_determinant_normal405);
  tcase_add_test(tc, s21_determinant_normal406);
  tcase_add_test(tc, s21_determinant_normal407);
  tcase_add_test(tc, s21_determinant_normal408);
  tcase_add_test(tc, s21_determinant_normal409);
  tcase_add_test(tc, s21_determinant_normal410);
  tcase_add_test(tc, s21_determinant_normal411);
  tcase_add_test(tc, s21_determinant_normal412);
  tcase_add_test(tc, s21_determinant_normal413);
  tcase_add_test(tc, s21_determinant_normal414);
  tcase_add_test(tc, s21_determinant_normal415);
  tcase_add_test(tc, s21_determinant_normal416);
  tcase_add_test(tc, s21_determinant_normal417);
  tcase_add_test(tc, s21_determinant_normal418);
  tcase_add_test(tc, s21_determinant_normal419);
  tcase_add_test(tc, s21_determinant_normal420);
  tcase_add_test(tc, s21_determinant_normal421);
  tcase_add_test(tc, s21_determinant_normal422);
  tcase_add_test(tc, s21_determinant_normal423);
  tcase_add_test(tc, s21_determinant_normal424);
  tcase_add_test(tc, s21_determinant_normal425);
  tcase_add_test(tc, s21_determinant_normal426);
  tcase_add_test(tc, s21_determinant_normal427);
  tcase_add_test(tc, s21_determinant_normal428);
  tcase_add_test(tc, s21_determinant_normal429);
  tcase_add_test(tc, s21_determinant_normal430);
  tcase_add_test(tc, s21_determinant_normal431);
  tcase_add_test(tc, s21_determinant_normal432);
  tcase_add_test(tc, s21_determinant_normal433);
  tcase_add_test(tc, s21_determinant_normal434);
  tcase_add_test(tc, s21_determinant_normal435);
  tcase_add_test(tc, s21_determinant_normal436);
  tcase_add_test(tc, s21_determinant_normal437);
  tcase_add_test(tc, s21_determinant_normal438);
  tcase_add_test(tc, s21_determinant_normal439);
  tcase_add_test(tc, s21_determinant_normal440);
  tcase_add_test(tc, s21_determinant_normal441);
  tcase_add_test(tc, s21_determinant_normal442);
  tcase_add_test(tc, s21_determinant_normal443);
  tcase_add_test(tc, s21_determinant_normal444);
  tcase_add_test(tc, s21_determinant_normal445);
  tcase_add_test(tc, s21_determinant_normal446);
  tcase_add_test(tc, s21_determinant_normal447);
  tcase_add_test(tc, s21_determinant_normal448);
  tcase_add_test(tc, s21_determinant_normal449);
  tcase_add_test(tc, s21_determinant_normal450);
  tcase_add_test(tc, s21_determinant_normal451);
  tcase_add_test(tc, s21_determinant_normal452);
  tcase_add_test(tc, s21_determinant_normal453);
  tcase_add_test(tc, s21_determinant_normal454);
  tcase_add_test(tc, s21_determinant_normal455);
  tcase_add_test(tc, s21_determinant_normal456);
  tcase_add_test(tc, s21_determinant_normal457);
  tcase_add_test(tc, s21_determinant_normal458);
  tcase_add_test(tc, s21_determinant_normal459);
  tcase_add_test(tc, s21_determinant_normal460);
  tcase_add_test(tc, s21_determinant_normal461);
  tcase_add_test(tc, s21_determinant_normal462);
  tcase_add_test(tc, s21_determinant_normal463);
  tcase_add_test(tc, s21_determinant_normal464);
  tcase_add_test(tc, s21_determinant_normal465);
  tcase_add_test(tc, s21_determinant_normal466);
  tcase_add_test(tc, s21_determinant_normal467);
  tcase_add_test(tc, s21_determinant_normal468);
  tcase_add_test(tc, s21_determinant_normal469);
  tcase_add_test(tc, s21_determinant_normal470);
  tcase_add_test(tc, s21_determinant_normal471);
  tcase_add_test(tc, s21_determinant_normal472);
  tcase_add_test(tc, s21_determinant_normal473);
  tcase_add_test(tc, s21_determinant_normal474);
  tcase_add_test(tc, s21_determinant_normal475);
  tcase_add_test(tc, s21_determinant_normal476);
  tcase_add_test(tc, s21_determinant_normal477);
  tcase_add_test(tc, s21_determinant_normal478);
  tcase_add_test(tc, s21_determinant_normal479);
  tcase_add_test(tc, s21_determinant_normal480);
  tcase_add_test(tc, s21_determinant_normal481);
  tcase_add_test(tc, s21_determinant_normal482);
  tcase_add_test(tc, s21_determinant_normal483);
  tcase_add_test(tc, s21_determinant_normal484);
  tcase_add_test(tc, s21_determinant_normal485);
  tcase_add_test(tc, s21_determinant_normal486);
  tcase_add_test(tc, s21_determinant_normal487);
  tcase_add_test(tc, s21_determinant_normal488);
  tcase_add_test(tc, s21_determinant_normal489);
  tcase_add_test(tc, s21_determinant_normal490);
  tcase_add_test(tc, s21_determinant_normal491);
  tcase_add_test(tc, s21_determinant_normal492);
  tcase_add_test(tc, s21_determinant_normal493);
  tcase_add_test(tc, s21_determinant_normal494);
  tcase_add_test(tc, s21_determinant_normal495);
  tcase_add_test(tc, s21_determinant_normal496);
  tcase_add_test(tc, s21_determinant_normal497);
  tcase_add_test(tc, s21_determinant_normal498);
  tcase_add_test(tc, s21_determinant_normal499);
  tcase_add_test(tc, s21_determinant_normal500);
  tcase_add_test(tc, s21_determinant_normal501);
  tcase_add_test(tc, s21_determinant_normal502);
  tcase_add_test(tc, s21_determinant_normal503);
  tcase_add_test(tc, s21_determinant_normal504);
  tcase_add_test(tc, s21_determinant_normal505);
  tcase_add_test(tc, s21_determinant_normal506);
  tcase_add_test(tc, s21_determinant_normal507);
  tcase_add_test(tc, s21_determinant_normal508);
  tcase_add_test(tc, s21_determinant_normal509);
  tcase_add_test(tc, s21_determinant_normal510);
  tcase_add_test(tc, s21_determinant_normal511);
  tcase_add_test(tc, s21_determinant_normal512);
  tcase_add_test(tc, s21_determinant_normal513);
  tcase_add_test(tc, s21_determinant_inf);
  tcase_add_test(tc, s21_determinant_inf_neg);
  tcase_add_test(tc, s21_determinant_06);
  suite_add_tcase(c, tc);
  return c;
}
