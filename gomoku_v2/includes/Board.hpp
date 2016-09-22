#ifndef BOARD_HPP
# define BOARD_HPP

# define BOARD_SIZE 19
# define INV(X) ((X) == (BLACK) ? (WHITE) : (BLACK))

# include "Rectangle.hpp"
# include <vector>
# include <map>
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
	bool					lastMoveIsCapture;
	char					board[BOARD_SIZE][BOARD_SIZE];
	int						score;
	pair<int,int>			lastMove;
	vector<Rectangle *> 	*rectangles;
	static map<t_orientation, pair<int, int> > orientationInc;

	Board(void);
	// Board(Board &rhs);
	~Board(void);

	void clear(void);
	void print(void);
	bool placePiece(int x, int y, t_piece piece);
	t_piece getPiece(int x, int y);
	bool hasXPiecesInRow(int x, int y, int nb, bool (*f)(int, int));
	vector<Board *> listAllMoves();
	void computeRectangles();
	int countConnectedPieces(int x, int y, t_piece piece, t_orientation ori);
	bool rowEndsWithPiece(int x, int y, t_piece piece, t_orientation ori);
	void removeCaptures();
	void removePiece(int x, int y);

	static map<t_orientation, pair<int, int > > initOrientationInc() {
		 map<t_orientation, pair<int, int > > myMap;
		 myMap[NW] = make_pair(-1, -1);
		 myMap[N] = make_pair(0, -1);
		 myMap[NE] = make_pair(1, -1);
		 myMap[E] = make_pair(1, 0);
		 myMap[SE] = make_pair(1, 1);
		 myMap[S] = make_pair(0, 1);
		 myMap[SW] = make_pair(-1, 1);
		 myMap[W] = make_pair(-1, 0);
		 return myMap;
	 }
};

#endif
