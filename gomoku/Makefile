CC = clang++
CFLAGS = -Wextra -Wall -Werror -O3 -I./includes -I ~/.brew/include `sdl2-config --cflags`
LFLAGS = `sdl2-config --libs` -lSDL2_image -ljpeg -lpng -lSDL2_ttf
#export LD_LIBRARY_PATH=~/.brew/lib
SRC = main.cpp Window.cpp Board.cpp Render.cpp Solver.cpp UI.cpp Rectangle.cpp

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
.PHONY: clean fclean all re
