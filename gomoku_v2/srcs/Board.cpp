#include "Board.hpp"

string *Board::orientation = initOrientation();
unordered_map<string, pair<int, int> >Board::orientationInc = initOrientationInc();

Board::Board() {
	threat = new AThreat();
	lastMove = make_pair(-1, -1);
	score = 0;
	turn = BLACK_PIECE;
	lastMoveIsCapture = false;
	clear();
}

Board::~Board(void) {
}

void Board::print() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			cout << board[j][i];
		}
		cout << endl;
	}
}

Board::Board(Board &rhs) {
	memcpy(board, rhs.board, sizeof(char[BOARD_SIZE][BOARD_SIZE]));
	lastMove = rhs.lastMove;
	turn = rhs.turn;
	lastMoveIsCapture = rhs.lastMoveIsCapture;
	for (unordered_map<string, pair<int, int> >::iterator it = rhs.pieces.begin(); it != rhs.pieces.end(); ++it) {
		pieces[(*it).first] = (*it).second;
	}
	threat = new AThreat();
	score = rhs.score;
}

void Board::removeCaptures() {
	pair<int, int> inc;
	int x = get<0>(lastMove);
	int y = get<1>(lastMove);

	lastMoveIsCapture = false;
	for (int i = 0; i < 8; i++) {
		inc = orientationInc[orientation[i]];
		if (countConnectedPieces(x + get<0>(inc), y + get<1>(inc), turn, orientation[i]) == 2 &&
			rowEndsWithPiece(x + get<0>(inc), y + get<1>(inc), turn, INV(turn), orientation[i])) {
			removePiece(x + get<0>(inc), y + get<1>(inc));
			removePiece(x + get<0>(inc) * 2, y + get<1>(inc) * 2);
			lastMoveIsCapture = true;
		}
	}
}

void Board::clear(void) {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			board[y][x] = EMPTY_PIECE;
		}
	}
}

int	 Board::countConnectedPieces(int x, int y, t_piece piece, string ori) {
	pair<int, int> inc = orientationInc[ori];

	if (x < 0 || y < 0 || x >= BOARD_SIZE || y >= BOARD_SIZE || getPiece(x, y) != piece) {
		return (0);
	}
	return (1 + countConnectedPieces(x + get<0>(inc), y + get<1>(inc), piece, ori));
}

bool Board::rowEndsWithPiece(int x, int y, t_piece initial, t_piece piece, string ori) {
	pair<int, int> inc = orientationInc[ori];

	if (getPiece(x, y) == piece) {
		return true;
	}
	else if (x < 0 || y < 0 || x >= BOARD_SIZE || y >= BOARD_SIZE || getPiece(x, y) != initial) {
		return false;
	}
	return (rowEndsWithPiece(x + get<0>(inc), y + get<1>(inc), initial, piece, ori));
}

bool Board::hasXPiecesInRow(int x, int y, int nb, bool (*f)(int, int)) {
	int i = 0;
	t_piece piece = getPiece(x, y);

	while (i < 8) {
		if ((*f)(countConnectedPieces(x, y, piece, orientation[i]) +
			countConnectedPieces(x, y, piece, orientation[i + 1]) - 1, nb)) {
			return true;
		}
		i += 2;
	}
	return false;
}

bool Board::placePiece(int x, int y, t_piece piece) {
	if (x < BOARD_SIZE && y < BOARD_SIZE && board[y][x] == EMPTY_PIECE) {
		board[y][x] = piece;
		if (threat->isBrokenThree(this, x, y) && threat->isXStraight(this, x, y, 3)) {
			board[y][x] = EMPTY_PIECE;
			return false;
		}
		lastMove = make_pair(x, y);
		pieces[myHash(x, y)] = make_pair(x, y);
		threat->computeThreats(this);
		turn = INV(turn);
		removeCaptures();
		return true;
	}
	return false;
}

void Board::removePiece(int x, int y) {
	unordered_map<string, pair <int, int> >::iterator it;

	board[y][x] = EMPTY_PIECE;
	it = pieces.find(myHash(x, y));
	pieces.erase(it);
}

t_piece Board::getPiece(int x, int y) {
	if (x < 0 ||  y < 0 || x >= BOARD_SIZE || y >= BOARD_SIZE)
		return OUT_OF_BOARD;
	return (t_piece)board[y][x];
}
