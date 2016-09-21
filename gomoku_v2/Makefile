CC = clang++
CFLAGS = -Wextra -Wall -Werror -O3 -I./includes -I ~/.brew/include
SRC = main.cpp Board.cpp Solver.cpp Rectangle.cpp Render.cpp Player.cpp Game.cpp
LFLAGS = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

NAME = gomoku

OBJ = $(SRCS:.cpp=.o)

SRCS = $(addprefix srcs/, $(SRC))

all : make_minilibx $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
		$(CC) -o $@ -c $< -I $(CFLAGS)

make_minilibx:
		make -C minilibx_macos/

clean:
		rm -f $(OBJ)
		make clean -C minilibx_macos

fclean: clean
		rm -f $(NAME)
		make fclean -C minilibx_macos

re: fclean
	make all

.PHONY: clean fclean all re make_minilibx
