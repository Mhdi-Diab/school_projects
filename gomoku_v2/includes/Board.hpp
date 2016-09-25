#ifndef BOARD_HPP
# define BOARD_HPP

# define BOARD_SIZE 19
# define INV(X) ((X) == (BLACK_PIECE) ? (WHITE_PIECE) : (BLACK_PIECE))
# define PIECE(X) ((X) == (P_BLACK) ? (BLACK_PIECE) : (WHITE_PIECE))

# include "Player.hpp"
# include "AThreat.hpp"
# include "utils.hpp"
# include <vector>
# include <unordered_map>
using namespace std;

typedef enum 	e_piece {
	BLACK_PIECE = 'x',
	WHITE_PIECE = 'o',
	EMPTY_PIECE = '.',
	OUT_OF_BOARD = '\0'
}				t_piece;

class Board {
public:
	AThreat 					*threat;
	bool						lastMoveIsCapture;
	char						board[BOARD_SIZE][BOARD_SIZE];
	int							score;
	pair<int,int>				lastMove;
	t_piece						turn;
	unordered_map<string, pair<int, int> >	pieces;

	static string orientation[8];
	static unordered_map<string, pair<int, int> > orientationInc;

	Board(void);
	Board(Board &rhs);
	virtual ~Board(void);

	void clear(void);
	void print();
	bool placePiece(int x, int y, t_piece piece);
	t_piece getPiece(int x, int y);
	bool hasXPiecesInRow(int x, int y, int nb, bool (*f)(int, int));
	int countConnectedPieces(int x, int y, t_piece piece, string ori);
	bool rowEndsWithPiece(int x, int y, t_piece initial, t_piece piece, string ori);
	void removeCaptures();
	void removePiece(int x, int y);

	static unordered_map<string, pair<int, int > > initOrientationInc() {
		 unordered_map<string, pair<int, int > > myMap;
		 myMap["NW"] = make_pair(-1, -1);
		 myMap["N"] = make_pair(0, -1);
		 myMap["NE"] = make_pair(1, -1);
		 myMap["E"] = make_pair(1, 0);
		 myMap["SE"] = make_pair(1, 1);
		 myMap["S"] = make_pair(0, 1);
		 myMap["SW"] = make_pair(-1, 1);
		 myMap["W"] = make_pair(-1, 0);
		 return myMap;
	 }
};

#endif
