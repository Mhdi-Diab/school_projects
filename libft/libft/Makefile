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

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
	  ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
	  ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
	  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
	  ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c\
	  ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c\
	  ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
	  ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c\
	  ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c\
	  ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c\
	  ft_strfjoin.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c\
	  ft_power.c ft_sqrt.c ft_swap.c ft_print_tab.c ft_tabdel.c ft_merge_sort.c\
	  ft_sort_params.c ft_str_swap.c ft_btree.c ft_btree2.c ft_lstadd_back.c \
	  ft_circular_list.c ft_tabsize.c ft_putcolor.c ft_tablen.c ft_lst_size.c \
	  get_next_line.c ft_atof.c

HEADERS = ./includes

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		@ gcc -O3 -c -Wall -Werror -Wextra $(SRC) -I $(HEADERS)
		@	ar rc libft.a $(OBJECTS)
		@	ranlib libft.a

clean:
		@ /bin/rm -f $(OBJECTS)

fclean: clean
		@ /bin/rm -f $(NAME)

re: fclean all
