#ifndef BOARD_HPP
# define BOARD_HPP

# define BOARD_SIZE 19

# include "Rectangle.hpp"
# include <vector>
using namespace std;

typedef enum 	e_piece {
	BLACK = 'x',
	WHITE = 'o',
	EMPTY = '.'
}				t_piece;

typedef enum 	s_orientation {
	N = 0,
	S,
	E,
	W,
	NW,
	NE,
	SW,
	SE
}				t_orientation;

class Rectangle;
class Board {
public:
	char					board[BOARD_SIZE][BOARD_SIZE];
	int						score;
	pair<int,int>			lastMove;
	std::vector<Rectangle *> *rectangles;

	Board(void);
	// Board(Board &rhs);
	~Board(void);

	void clear(void);
	void print(void);
	bool placePiece(int x, int y, t_piece piece);
	t_piece getPiece(int x, int y);
	bool hasXPiecesInRow(int x, int y, int nb);
	vector<Board *> listAllMoves();
	void computeRectangles(int x, int y);
};

#endif
