CC := g++
CXX_FLAGS := -Wall -Werror -Wextra -std=c++17
LIBS := -lgtest -lgtest_main
GCOV_FLAGS := --coverage
TESTS_SRCS:= ./tests/*.cc  ./tests/*/*.cc

OS := $(shell uname -s)

ifeq ($(OS), Linux)
	OPEN := google-chrome
else
	OPEN = open
endif

.PHONY: all valgrind gcov_report clang_check clean

all: matrix_oop.a gcov_report

matrix_oop.a: matrix_oop.o
	ar rcs $@ $^
	ranlib $@

%.o: %.cc %.h
	$(CC) $(CXX_FLAGS) -o $@ $<

test: matrix_oop.h tests/matrix_oop_tests.h
	$(CC) $(CXX_FLAGS) -o $@ matrix_oop.cc $(TESTS_SRCS) $(LIBS)
	./$@

valgrind: test
	CK_FORK=no valgrind -s  --track-origins=yes --tool=memcheck --leak-check=full --show-leak-kinds=all --log-file=RESULT_VALGRIND.txt ./test

gcov_report: matrix_oop.h tests/matrix_oop_tests.h
	$(CC) $(CXX_FLAGS) $(GCOV_FLAGS) -o gcov_test matrix_oop.cc $(TESTS_SRCS) $(LIBS)
	./gcov_test
	lcov -t "matrix_oop_tests" -o coverage.info --no-external -c -d .
	genhtml -o report coverage.info
	rm *.info *.gcda *.gcno gcov_test
	$(OPEN) report/index.html

clang_check:
	clang-format -style=Google -n *.cc *.h tests/*.cc tests/*.h tests/*/*.cc

clean:
	rm -rf *.a test RESULT_VALGRIND.txt report