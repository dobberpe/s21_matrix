#include "s21_matrix_test.h"

START_TEST(s21_remove_null_pointer) {
  // INVALID_MATRIX
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(s21_remove_null_pointer_matrix) {
  // A.matrix = NULL
  matrix_t A;
  A.matrix = NULL;
  s21_remove_matrix(&A);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(s21_remove_null_pointer_rows) {
  // INVALID_MATRIX
  // A.matrix = NULL
  matrix_t A;
  A.rows = 1;
  A.matrix = (double**)malloc(sizeof(double*));
  A.matrix[0] = NULL;
  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
  free(A.matrix);
}
END_TEST

START_TEST(s21_remove_normal) {
  // OK
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  s21_remove_matrix(&A);
  ck_assert_ptr_eq(A.matrix, NULL);
}
END_TEST

Suite *s21_remove_cases(void) {
  Suite *c = suite_create("s21_remove_cases");
  TCase *tc = tcase_create("s21_remove_tc");
  tcase_add_test(tc, s21_remove_null_pointer);
  tcase_add_test(tc, s21_remove_null_pointer_matrix);
  tcase_add_test(tc, s21_remove_null_pointer_rows);
  tcase_add_test(tc, s21_remove_normal);
  suite_add_tcase(c, tc);
  return c;
}
