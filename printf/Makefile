include config.mk

NAME = $(CONFIG_NAME)
OUTPUT_TYPE = $(CONFIG_OUTPUT_TYPE)
CC_FLAGS_EXTRA = $(CONFIG_CC_FLAGS_EXTRA)
CC_FLAGS_EXTRA_POST = $(CONFIG_CC_FLAGS_EXTRA_POST)

LIBFT_PATH = ./libs/libft
LIBFT_INCLUDES = -I $(LIBFT_PATH)/includes
LIBFT_LD = $(LIBFT_PATH)/libft.a

C_DIR = srcs
O_DIR = .tmp/objects

CC_FLAGS = -g -Wall -Wextra -Werror
CC_HEADERS = -I ./includes $(LIBFT_INCLUDES)
CC_DEBUG =

C_FILES = $(shell find $(C_DIR) -type f -follow -print | grep ".*\.c$$" | grep -v "\.spec\.c")
C_DIRS = $(shell find $(C_DIR) -type d -follow -print)

H_FILES = $(shell find includes -type f -follow -print | grep ".*\.h$$")
O_DIRS = $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

COL_GRAY = \033[1;30m
COL_RESET = \033[0;0m
COL_RED = \033[0;31m
COL_GREEN = \033[0;32m
CC_OPTIONS = $(CC_FLAGS) $(CC_HEADERS) $(CC_FLAGS_EXTRA)

DEBUG_FILE_NAME = /tmp/.debug.out

MAKE_PATHS = $(dir $(wildcard ./libs/*/))
MAKE = make -s

all:
	@$(foreach lib, $(MAKE_PATHS), $(MAKE) -C $(lib);)
	@$(MAKE) $(NAME)

$(NAME): $(O_FILES) $(LIBFT_LD)
	@echo ""
	@echo "[info] compile $(OUTPUT_TYPE) ..."

ifeq ($(OUTPUT_TYPE), lib)
	@ar rcs $@ $^
endif
ifeq ($(OUTPUT_TYPE), exec)
	@gcc $(CC_OPTIONS) $(CONFIG_EXTRA_LIBS) $(CONFIG_EXTRA_H) $(LIBFT_INCLUDES) $(CC_DEBUG) $^ -o $@  $(CC_FLAGS_EXTRA_POST) $(LIBFT_LD)
endif
ifeq ($(OUTPUT_TYPE), so)
	@gcc $(CC_OPTIONS) $(LIBFT_INCLUDES) $(CC_DEBUG) $^ -shared -o $@  $(CC_FLAGS_EXTRA_POST) $(LIBFT_LD)
endif
	@echo "$(COL_GREEN)$(NAME)$(COL_RESET)"
	$(POST_COMPILATION_CMD)

$(O_DIR)%.o: $(C_DIR)%.c $(H_FILES)
	@mkdir -p $(O_DIRS) $(O_DIR)
	@gcc $(CC_OPTIONS) $(CONFIG_EXTRA_H) $(LIBFT_INCLUDES) $(CC_DEBUG) -o $@ -c $< \
		&& printf "."

clean: _clean
	@$(foreach lib, $(MAKE_PATHS), $(MAKE) -C $(lib) clean;)

fclean: _fclean
	@$(foreach lib, $(MAKE_PATHS), $(MAKE) -C $(lib) fclean;)

_clean:
	$(info [info] $@ ...)
	@rm -rf .tmp

_fclean: _clean
	$(info [info] $@ ...)
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

re:
	@$(MAKE) fclean
	@$(MAKE) all

check_log_error:
	! grep ERROR /tmp/.debug.out

log:
	touch $(DEBUG_FILE_NAME)
	tail -f $(DEBUG_FILE_NAME)

check:
	make -C tests/moulitest_tests ft_printf

test:
	@$(MAKE) -j
	@gcc $(CC_FLAGS) $(LIBFT_LD) $(NAME) tests/main.c $(CC_HEADERS)
	@./a.out && rm a.out && rm -rf a.out.dSYM

val: all
	valgrind --leak-check=full $(CONFIG_RUN_CMD)

.PHONY: all clean fclean re