# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atamano <atamano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 19:54:48 by atamano           #+#    #+#              #
#    Updated: 2015/05/18 15:39:07 by atamano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
T_NAME = exec_test

OUTPUT_TYPE = lib
C_DIR = srcs
O_DIR = .tmp/objects
T_DIR = tests

CC_FLAGS = -Wall -Wextra -Werror
CC_HEADERS = -I ./includes -I ./srcs/libft/includes
CC_TEST_HEADERS = -I ./tests/includes
CC_DEBUG =

C_FILES = $(shell find $(C_DIR) -type f -follow -print | grep ".*\.c$$" | grep -v "\.spec\.c")
C_DIRS = $(shell find $(C_DIR) -type d -follow -print)

T_FILES = $(shell find $(T_DIR) -type f -follow -print | grep ".*\.c$$" | grep -v "\.spec\.c")

H_FILES = $(shell find includes -type f -follow -print | grep ".*\.h$$")
O_DIRS = $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

COL_GRAY = \033[1;30m
COL_RESET = \033[0;0m
COL_RED = \033[0;31m
COL_GREEN = \033[0;32m
CC_OPTIONS = $(CC_FLAGS) $(CC_HEADERS)

DEBUG_FILE_NAME = /tmp/.debug.out

MAKE_PATHS = $(dir $(wildcard ./libs/*/))
MAKE = make -s

all:
	@$(foreach lib, $(MAKE_PATHS), $(MAKE) -C $(lib);)
	@$(MAKE) $(NAME)

$(NAME): $(O_FILES)
	@echo ""
	@echo "[info] compile $(OUTPUT_TYPE) ..."

ifeq ($(OUTPUT_TYPE), lib)
	@ar rcs $@ $^
endif
ifeq ($(OUTPUT_TYPE), exec)
	@gcc $(CC_OPTIONS) $(CONFIG_EXTRA_LIBS) $(CONFIG_EXTRA_H) $(CC_DEBUG) $^
endif
ifeq ($(OUTPUT_TYPE), so)
	@gcc $(CC_OPTIONS) $(CC_DEBUG) $^
endif
	@echo "$(COL_GREEN)$(NAME)$(COL_RESET)"
	$(POST_COMPILATION_CMD)

$(O_DIR)%.o: $(C_DIR)%.c $(H_FILES)
	@mkdir -p $(O_DIRS) $(O_DIR)
	@gcc $(CC_OPTIONS) $(CONFIG_EXTRA_H) $(CC_DEBUG) -o $@ -c $< \
		&& printf "."

test:
	@gcc $(CC_FLAGS) $(NAME) $(T_FILES) $(CC_HEADERS) $(CC_TEST_HEADERS) -o $(T_NAME)
	./$(T_NAME)

clean: _clean
	@$(foreach lib, $(MAKE_PATHS), $(MAKE) -C $(lib) clean;)

fclean: _fclean
	@$(foreach lib, $(MAKE_PATHS), $(MAKE) -C $(lib) fclean;)

_clean:
	$(info [info] $@ ...)
	@rm $(T_NAME)
	@rm -rf .tmp

_fclean: _clean
	$(info [info] $@ ...)
	@rm $(NAME) 2> /dev/null || echo "" > /dev/null

re:
	@$(MAKE) fclean
	@$(MAKE) all

run: all
	$(CONFIG_RUN_CMD)

.PHONY: all clean fclean re
