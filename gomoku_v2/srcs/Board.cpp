#include "Board.hpp"

Board::Board() {
	previousMove = make_pair(-1, -1);
	score = 0;
	this->clear();
}

Board::~Board(void) {
}

void Board::clear(void) {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			board[y][x] = EMPTY;
		}
	}
}

void Board::print(void) {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			cout << board[y][x];
		}
		cout << endl;
	}
}

vector<Board *> Board::listAllMoves() {
	vector<Board *> moves;

	return moves;
}

bool Board::placePiece(int x, int y, t_piece piece) {
	if (x < BOARD_SIZE && y < BOARD_SIZE && board[y][x] == EMPTY) {
		board[y][x] = piece;
		previousMove = make_pair(x, y);
		return true;
	}
	return false;
}
