CC = clang++
CFLAGS = -Wextra -Wall -Werror -O3 -I./includes -I ~/.brew/include -I./SFML/include
LFLAGS = -L ./SFML -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp Board.cpp Solver.cpp Rectangle.cpp Render.cpp Player.cpp Game.cpp \
	Piece.cpp

NAME = gomoku

OBJ = $(SRCS:.cpp=.o)

SRCS = $(addprefix srcs/, $(SRC))

all : $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
		$(CC) -o $@ -c $< -I $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean
	make all

.PHONY: clean fclean all re make_minilibx
