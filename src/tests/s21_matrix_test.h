#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

Suite *s21_create_cases(void);
Suite *s21_remove_cases(void);
Suite *s21_eq_cases(void);
Suite *s21_sum_cases(void);
Suite *s21_sub_cases(void);
Suite *s21_mult_matrix_cases(void);
Suite *s21_transpose_cases(void);
Suite *s21_calc_complements_cases(void);
Suite *s21_determinant_cases(void);
Suite *s21_inverse_matrix_cases(void);

#endif