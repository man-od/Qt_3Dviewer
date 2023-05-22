include Makefile.mk

NAME         := 3DViewer_v1.0
APP          := $(if $(filter Linux,$(OS)),$(NAME),$(NAME).app)

SRC_DIR      := src
BUILD_DIR    := .build
LIB_DIR      := src/libobj
DVI_DIR      := manual
DVI_FILE     := manual.texi

MAKEDVI      := makeinfo --html
BUILDER      := cmake

all: install run

install:
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR) && $(BUILDER) .. && $(MAKE)

uninstall:
	$(RM) $(BUILD_DIR)

run:
	$(RUN)$(BUILD_DIR)/$(APP)

dvi:
	$(MAKEDVI) $(DVI_FILE)
	$(OPEN) $(DVI_DIR)/index.html

dist:
	mkdir ../$(NAME)
	$(CP) * ../$(NAME)
	mv ../$(NAME) .
	$(TAR) $(NAME).tgz $(NAME)
	mv $(NAME).tgz $(HOME)/Desktop

check-style:
	$(CP) $(LINT_DIR)/$(LINT_CONF) $(SRC_DIR)
	find $(SRC_DIR) -name '*.cc' -o -name '*.c' -o -name '*.h' | xargs clang-format -n
	$(RM) $(SRC_DIR)/$(LINT_CONF)

.PHONY: test gcov_report check-valgrind

test gcov_report check-valgrind:
	$(MAKE) -C $(LIB_DIR) -f Makefile $@

clean: uninstall
	$(MAKE) -C $(LIB_DIR) -f Makefile $@

fclean: clean
	$(RM) $(NAME)
	$(RM) *.gif
	$(MAKE) -C $(LIB_DIR) -f Makefile $@
