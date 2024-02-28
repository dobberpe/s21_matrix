#include "s21_matrix_test.h"

START_TEST(s21_create_null_pointer) {
  // INVALID_MATRIX
  ck_assert_int_eq(s21_create_matrix(3, 3, NULL), INVALID_MATRIX);
}
END_TEST

START_TEST(s21_create_zero_rows) {
  // INVALID_MATRIX
  // A.matrix = NULL
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(0, 3, &A), INVALID_MATRIX);
  ck_assert_ptr_eq(A.matrix, NULL);
}
END_TEST

START_TEST(s21_create_zero_columns) {
  // INVALID_MATRIX
  // A.matrix = NULL
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(3, 0, &A), INVALID_MATRIX);
  ck_assert_ptr_eq(A.matrix, NULL);
}
END_TEST

START_TEST(s21_create_normal) {
  // OK
  matrix_t A;
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_create_cases(void) {
  Suite *c = suite_create("s21_create_cases");
  TCase *tc = tcase_create("s21_create_tc");
  tcase_add_test(tc, s21_create_null_pointer);
  tcase_add_test(tc, s21_create_zero_rows);
  tcase_add_test(tc, s21_create_zero_columns);
  tcase_add_test(tc, s21_create_normal);
  suite_add_tcase(c, tc);
  return c;
}
