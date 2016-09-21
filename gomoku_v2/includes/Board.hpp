#ifndef BOARD_HPP
# define BOARD_HPP

# define BOARD_SIZE 19
# include "Game.hpp"

typedef enum 	e_piece {
	BLACK = 'x',
	WHITE = 'o',
	EMPTY = '.'
}				t_piece;

class Board {

public:
	char	board[BOARD_SIZE][BOARD_SIZE];

	Board(void);
	// Board(Board &rhs);
	~Board(void);

	void clear(void);
	void print(void);

};
#endif
