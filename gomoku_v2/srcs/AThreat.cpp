#include "AThreat.hpp"
#include "Board.hpp"

string *AThreat::threatsName = initThreatsNames();
unordered_map<string, int>AThreat::threatsScore = initThreat();

AThreat::AThreat() {
	clearThreats();
}

AThreat::~AThreat(void) {
}

AThreat::AThreat(AThreat &rhs) {
	blackThreats = rhs.blackThreats;
	whiteThreats = rhs.whiteThreats;
}

void AThreat::clearThreats(void) {
	for (int i = 0; i <= 7; i++) {
		this->blackThreats[threatsName[i]] = 0;
		this->whiteThreats[threatsName[i]] = 0;
	}
}

bool AThreat::isX(Board *b, int x, int y, int nb) {
	int i = 0;
	t_piece piece = b->getPiece(x, y);

	while (i < 8) {
		if (b->countConnectedPieces(x, y, piece, Board::orientation[i]) +
			b->countConnectedPieces(x, y, piece, Board::orientation[i + 1]) - 1 == nb &&
			(b->rowEndsWithPiece(x, y, piece, EMPTY_PIECE, Board::orientation[i]) ||
			b->rowEndsWithPiece(x, y, piece, EMPTY_PIECE, Board::orientation[i + 1]))) {
			return true;
		}
		i += 2;
	}
	return false;
}

bool AThreat::isXStraight(Board *b, int x, int y, int nb) {
	int i = 0;
	t_piece piece = b->getPiece(x, y);
	while (i < 8) {
		// if (piece == WHITE_PIECE) {
		// 	cout << b->countConnectedPieces(x, y, piece, Board::orientation[i]) +
		// 		b->countConnectedPieces(x, y, piece, Board::orientation[i + 1]) - 1 << endl;
		// }
		if (b->countConnectedPieces(x, y, piece, Board::orientation[i]) +
			b->countConnectedPieces(x, y, piece, Board::orientation[i + 1]) - 1 == nb &&
			b->rowEndsWithPiece(x, y, piece, EMPTY_PIECE, Board::orientation[i]) &&
			b->rowEndsWithPiece(x, y, piece, EMPTY_PIECE, Board::orientation[i + 1])) {
			return true;
		}
		i += 2;
	}
	return false;
}

void 		AThreat::printThreats(Board *b) {
	cout << "WHITE: FIVE: " << whiteThreats["FIVE"];
	cout << " FOUR: " << whiteThreats["FOUR"];
	cout << " STRAIGHT_FOUR: " << whiteThreats["STRAIGHT_FOUR"];
	cout << " THREE: " << whiteThreats["THREE"];
	cout << " TWO: " << whiteThreats["TWO"] << endl;
	cout << "BLACK: FIVE: " << blackThreats["FIVE"];
	cout << " FOUR: " << blackThreats["FOUR"];
	cout << " STRAIGHT_FOUR: " << blackThreats["STRAIGHT_FOUR"];
	cout << " THREE: " << blackThreats["THREE"];
	cout << " TWO: " << blackThreats["TWO"] << endl;
}

void 		AThreat::computeScore(Board *b) {
	int whiteScore = 0;
	int blackScore = 0;
	t_piece piece = b->getPiece(get<0>(b->lastMove), get<1>(b->lastMove));

	for (int i = 0; i < 7; i++) {
		whiteScore += whiteThreats[AThreat::threatsName[i]] * threatsScore[AThreat::threatsName[i]];
		blackScore += blackThreats[AThreat::threatsName[i]] * threatsScore[AThreat::threatsName[i]];
	}
	if (piece == BLACK_PIECE) {
		b->score = blackScore - whiteScore;
	} else {
		b->score = whiteScore - blackScore;
	}
}

void		AThreat::computeThreats(Board *b) {
	t_piece p;
	int x, y;

	// clearThreats();
	// for (unordered_map<string, pair<int, int> >::iterator it = b->pieces.begin(); it != b->pieces.end(); ++it) {
		x = get<0>(b->lastMove);
		y = get<1>(b->lastMove);
		p = b->getPiece(x, y);
		if (p == WHITE_PIECE) {
			whiteThreats["FIVE"] += isX(b, x, y, 5);
			whiteThreats["STRAIGHT_FOUR"] += isXStraight(b, x, y, 4);
			whiteThreats["FOUR"] += isX(b, x, y, 4);
			whiteThreats["THREE"] += isXStraight(b, x, y, 3);
			whiteThreats["TWO"] += isXStraight(b, x, y, 2);
		} else if (p == BLACK_PIECE) {
			blackThreats["FIVE"] += isX(b, x, y, 5);
			blackThreats["STRAIGHT_FOUR"] += isXStraight(b, x, y, 4);
			blackThreats["FOUR"] += isX(b, x, y, 4);
			blackThreats["THREE"] += isXStraight(b, x, y, 3);
			blackThreats["TWO"] += isXStraight(b, x, y, 2);
		}
	// }
	printThreats(b);
	computeScore(b);
}
