CC = gcc
CFLAGS = -Wall -Wextra -Werror
TFLAGS = -lcheck -lsubunit -lm
GFLAGS = -fprofile-arcs -ftest-coverage
LIB_NAME = s21_matrix.a
LIB_SRC = s21_matrix.c
LIB_OBJ = $(LIB_SRC:.c=.o)
TEST_SRC = $(wildcard ./tests/*.c)
TEST_GCDA = $(LIB_SRC:.c=.gcda)
TEST_OBJ = $(TEST_SRC:.c=.o)

all: $(LIB_NAME)

test: $(TEST_OBJ) $(LIB_NAME)
	$(CC) $(CFLAGS) $(TEST_OBJ) -o test -L. -l:$(LIB_NAME) $(TFLAGS)
	rm -f $(TEST_OBJ)
	./test


gcov_report: clean
	gcc -o s21_decimal_arithmetic.o -c $(GFLAGS) s21_decimal_arithmetic.c
	gcc -o s21_decimal_converter.o -c $(GFLAGS) s21_decimal_converter.c
	gcc -o s21_common.o -c $(GFLAGS) s21_common.c
	gcc -o s21_dectostr.o -c $(GFLAGS) s21_dectostr.c
	gcc -o s21_decimal_compare.o -c $(GFLAGS) s21_decimal_compare.c
	gcc -o s21_decimal_other.o -c $(GFLAGS) s21_decimal_other.c
	ar rcs $(LIB_NAME) $(LIB_OBJ)
	ranlib $(LIB_NAME)
	rm -f $(LIB_OBJ)
	$(CC) $(CFLAGS) -o gcov_r $(GFLAGS) $(TEST_SRC) -L. -l:$(LIB_NAME) $(TFLAGS)
	mkdir -p html_report
	./gcov_r
	python3 -m gcovr -r . --html --html-details -o html_report/coverage_report.html --exclude test
	open html_report/coverage_report.html

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_NAME): $(LIB_OBJ)
	ar rcs $(LIB_NAME) $(LIB_OBJ)
	ranlib $(LIB_NAME)
	rm -f $(LIB_OBJ)

clean:
	rm -f $(LIB_OBJ) $(LIB_NAME) $(TEST_OBJ) test gcov* coverage.info *.gcda *.gcno tests/*.gcno
	rm -rf coverage_report

re: clean all
