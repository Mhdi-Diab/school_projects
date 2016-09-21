#ifndef BOARD_HPP
# define BOARD_HPP

# define BOARD_SIZE 19
# include "Game.hpp"
# include <vector>

typedef enum 	e_piece {
	BLACK = 'x',
	WHITE = 'o',
	EMPTY = '.'
}				t_piece;

class Board {

public:
	char			board[BOARD_SIZE][BOARD_SIZE];
	int				score;
	pair<int,int>	previousMove;

	Board(void);
	// Board(Board &rhs);
	~Board(void);

	void clear(void);
	void print(void);
	bool placePiece(int x, int y, t_piece piece);
	vector<Board *> listAllMoves();

};
#endif
