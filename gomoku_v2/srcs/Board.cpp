#include "Board.hpp"

Board::Board() {
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

bool Board::placePiece(int x, int y, t_piece piece) {
	if (x < BOARD_SIZE && y < BOARD_SIZE && board[y][x] == EMPTY) {
		board[y][x] = piece;
		return true;
	}
	return false;
}
