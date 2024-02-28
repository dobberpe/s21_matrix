#include "s21_matrix_test.h"

int main() {
  int number_failed;
  Suite *suite = NULL;
  SRunner *runner = srunner_create(suite);

  Suite *suits_list[] = { s21_create_cases(), s21_remove_cases(), s21_eq_cases(), s21_sum_cases(), s21_sub_cases(), s21_mult_matrix_cases(), s21_transpose_cases(), s21_calc_complements_cases(), s21_determinant_cases(), s21_inverse_matrix_cases(), NULL};

  for (Suite **current = suits_list; *current != NULL; current++)
    srunner_add_suite(runner, *current);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}