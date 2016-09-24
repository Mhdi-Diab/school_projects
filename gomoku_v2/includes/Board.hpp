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
	EMPTY_PIECE = '.'
}				t_piece;

class Board {
public:
	AThreat 					*threat;
	bool						lastMoveIsCapture;
	char						board[BOARD_SIZE][BOARD_SIZE];
	int							score;
	pair<int,int>				lastMove;
	unordered_map<string, pair<int, int> >	pieces;

	static string *orientation;
	static unordered_map<string, pair<int, int> > orientationInc;

	Board(void);
	Board(Board &rhs);
	virtual ~Board(void);

	void clear(void);
	void print();
	bool placePiece(int x, int y, t_piece piece);
	t_piece getPiece(int x, int y);
	bool hasXPiecesInRow(int x, int y, int nb, bool (*f)(int, int));
	bool isBrokenRow(int x, int y, t_piece piece, string ori);
	int countConnectedPieces(int x, int y, t_piece piece, string ori);
	bool rowEndsWithPiece(int x, int y, t_piece initial, t_piece piece, string ori);
	void removeCaptures();
	void removePiece(int x, int y);

	static string *initOrientation() {
		string *names = new string[8];
		string orientation[8] = {"NW", "SE", "N", "S", "W", "E", "SW", "NE"};

		for (int i = 0; i < 8; i++) {
			names[i] = orientation[i];
		}
		return names;
	}

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
