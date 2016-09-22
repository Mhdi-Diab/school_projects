#include "Piece.hpp"

Piece::Piece(int x, int y, t_piece piece) {
	this->x = x;
	this->y = y;
	this->piece = piece;
}

Piece::~Piece(void) {
}
