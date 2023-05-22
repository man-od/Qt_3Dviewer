include ../../Makefile.mk

NAME         := obj.a
LCOV_NAME    := obj.info
TEST_NAME    := obj_test

SRCS         := obj_data.c affine_transform.c
TEST_SRCS    := obj_test.c
OBJS         := $(SRCS:.c=.o)
REPORT_DIR   := report

CC           := gcc
CFLAGS       := -Wall -Wextra -Werror -std=c11

GCOV         := --coverage
LCOV         := lcov
LCOVFLAGS    := --no-external -c

AR           := ar
ARFLAGS      := -r -c -s

TEST_LIB     := -lcheck
LDFLAGS       = $(addprefix -L. , $(NAME))
LDFLAGS      += $(if $(filter Linux,$(OS)),-lm -lsubunit)

all: $(NAME)

test: $(NAME)
	$(CC) $(CFLAGS) $(TEST_SRCS) $(TEST_LIB) $(LDFLAGS) -o $(TEST_NAME)
	./$(TEST_NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

gcov_report: $(NAME)
	$(CC) $(CFLAGS) $(GCOV) $(TEST_SRCS) $(SRCS) $(TEST_LIB) $(LDFLAGS) -o $(TEST_NAME)
	./$(TEST_NAME)
	$(LCOV) -t $(TEST_NAME) $(LCOVFLAGS) -d . -o $(LCOV_NAME)
	genhtml $(LCOV_NAME) -o $(REPORT_DIR)
	$(OPEN) $(REPORT_DIR)/index.html

check-valgrind: test
	CK_FORK=NO $(VALGRIND) ./$(TEST_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	$(RM) $(TEST_NAME)
	$(RM) *.gcno *.gcda

fclean: clean
	$(RM) $(NAME)
	$(RM) $(REPORT_DIR)
	$(RM) *.info

rebuild:
	$(MAKE) fclean
	$(MAKE) all