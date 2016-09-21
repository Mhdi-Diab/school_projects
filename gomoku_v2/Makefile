CC = clang++
CFLAGS = -Wextra -Wall -Werror -O3 -I./includes -I ~/.brew/include -I./minilibx_macos
SRC = main.cpp Board.cpp Solver.cpp Rectangle.cpp Render.cpp Player.cpp Game.cpp

NAME = gomoku

OBJ = $(SRCS:.cpp=.o)

SRCS = $(addprefix srcs/, $(SRC))

all : make_minilibx $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
		$(CC) -o $@ -c $< -I $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean
	make all

.PHONY: clean fclean all re make_minilibx
