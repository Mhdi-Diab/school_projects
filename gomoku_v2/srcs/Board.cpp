#include "Board.hpp"

map<t_orientation, pair<int, int> >Board::orientationInc = initOrientationInc();
map<t_threat, int>AThreat::threatsScore = initThreat();

Board::Board() {
	lastMove = make_pair(-1, -1);
	rectangles = new vector<Rectangle *>();
	score = 0;
	lastMoveIsCapture = false;
	clear();
}

Board::~Board(void) {
}

Board::Board(Board &rhs) {
	rectangles = new vector<Rectangle *>();

	memcpy(board, rhs.board, sizeof(char[BOARD_SIZE][BOARD_SIZE]));
	for (vector<Rectangle *>::iterator iter = rhs.rectangles->begin(); iter != rhs.rectangles->end(); iter++) {
		rectangles->push_back(new Rectangle(**iter));
	}
	lastMove = rhs.lastMove;
	lastMoveIsCapture = rhs.lastMoveIsCapture;
}

void Board::removeCaptures() {
	pair<int, int> inc;
	int x = get<0>(lastMove);
	int y = get<1>(lastMove);
	t_piece piece = getPiece(x, y);
	t_orientation ori[8] = {NW, SE, N, S, W, E, SW, NE};

	lastMoveIsCapture = false;
	for (int i = 0; i < 8; i++) {
		inc = orientationInc[ori[i]];
		if (countConnectedPieces(x + get<0>(inc), y + get<1>(inc), INV(piece), ori[i]) == 2 &&
			rowEndsWithPiece(x + get<0>(inc), y + get<1>(inc), piece, ori[i])) {
			removePiece(x + get<0>(inc), y + get<1>(inc));
			removePiece(x + get<0>(inc) * 2, y + get<1>(inc) * 2);
			lastMoveIsCapture = true;
		}
	}
}

void Board::clear(void) {
	for (int y = 0; y < BOARD_SIZE; y++) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			board[y][x] = EMPTY;
		}
	}
}

int	 Board::countConnectedPieces(int x, int y, t_piece piece, t_orientation ori) {
	pair<int, int> inc = orientationInc[ori];

	if (x < 0 || y < 0 || x >= BOARD_SIZE || y >= BOARD_SIZE || getPiece(x, y) != piece) {
		return (0);
	}
	return (1 + countConnectedPieces(x + get<0>(inc), y + get<1>(inc), piece, ori));
}

bool Board::rowEndsWithPiece(int x, int y, t_piece piece, t_orientation ori) {
	pair<int, int> inc = orientationInc[ori];

	if (getPiece(x, y) == piece) {
		return true;
	}
	else if (x < 0 || y < 0 || x >= BOARD_SIZE || y >= BOARD_SIZE || getPiece(x, y) != INV(piece)) {
		return false;
	}
	return (rowEndsWithPiece(x + get<0>(inc), y + get<1>(inc), piece, ori));
}

bool Board::hasXPiecesInRow(int x, int y, int nb, bool (*f)(int, int)) {
	int i = 0;
	t_piece piece = getPiece(x, y);
	t_orientation ori[8] = {NW, SE, N, S, W, E, SW, NE};

	while (i < 8) {
		if ((*f)(countConnectedPieces(x, y, piece, ori[i]) +
			countConnectedPieces(x, y, piece, ori[i + 1]) - 1, nb)) {
			return true;
		}
		i += 2;
	}
	return false;
}

bool Board::placePiece(int x, int y, t_piece piece) {
	if (x < BOARD_SIZE && y < BOARD_SIZE && board[y][x] == EMPTY) {
		board[y][x] = piece;
		lastMove = make_pair(x, y);
		pieces[make_pair(x, y)] = new Piece(x, y, piece);
		computeRectangles(x, y);
		computeThreats(x, y);
		return true;
	}
	return false;
}

void Board::removePiece(int x, int y) {
	map< pair<int, int>, Piece *>::iterator it;

	board[y][x] = EMPTY;
	it = pieces.find(make_pair(x, y));
	pieces.erase(it);
}

t_piece Board::getPiece(int x, int y) {
	return (t_piece)board[y][x];
}

void		Board::computeThreats(int x, int y) {
	if (hasXPiecesInRow(x, y, 5, equalCmp)) {
		threatsCount[FIVE] += 1;
	}
	if (hasXPiecesInRow(x, y, 4, equalCmp)) {
		threatsCount[FOUR] += 1;
	}
	if (hasXPiecesInRow(x, y, 3, equalCmp)) {
		threatsCount[THREE] += 1;
	}
	score = threatsCount[FIVE] * threatsScore[FIVE] +
	threatsCount[FOUR] * threatsScore[FOUR] + threatsCount[THREE] * threatsCount[THREE];
}

void 		Board::computeRectangles(int x, int y) {
	vector<Rectangle *>	vec;
	Rectangle	*rect;

	rect = new Rectangle(x, y);
	if (rectangles->size() == 0) {
		rectangles->push_back(rect);
	} else {
		vec = rect->getConnectedRectangles(rectangles, x, y);
		if (vec.size() == 0) {
			rectangles->push_back(rect);
		} else if (vec.size() == 1) {
			// delete rect; TODO: check leaks
			rect = vec.front();
			rect->resize(x, y);
		} else if (vec.size() > 1) {
			rectangles->push_back(rect);
			rect->mergeRectangles(rectangles, vec, x, y);
		}
	}
}
