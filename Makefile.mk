OS           := $(shell uname -s)

OPEN         := $(if $(filter Linux,$(OS)),xdg-open,open)
RUN          := $(if $(filter Linux,$(OS)),./,open )

VALGRIND     := valgrind --tool=memcheck --trace-children=yes --track-origins=yes --leak-check=full

LINT          := clang-format
LINT_CONF     := .clang-format
LINT_DIR      := materials/linters

CP           := cp -rf
TAR          := tar cvzf
RM           := rm -rf

MAKEFLAGS    += --no-print-directory
