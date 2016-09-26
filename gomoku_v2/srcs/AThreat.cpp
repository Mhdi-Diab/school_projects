#include "AThreat.hpp"
#include "Board.hpp"
#include "Game.hpp"

string AThreat::threatsName[] = {"CAPTURE", "THREE", "BROKEN_THREE", "FOUR", "STRAIGHT_FOUR", "FIVE"};
unordered_map<string, int>AThreat::threatsScore = initThreat();

AThreat::AThreat(void) {
	clearThreats();
}

AThreat::~AThreat(void) {
}

AThreat::AThreat(AThreat &rhs) {
	clearThreats();
}

void AThreat::clearThreats(void) {
	for (int i = 0; i < NUMBER_THREATS; i++) {
		this->blackThreats[threatsName[i]] = 0;
		this->whiteThreats[threatsName[i]] = 0;
	}
}

bool AThreat::isBrokenThree(Board &b, int x, int y) {
	int i = 0;
	string ori;
	t_piece piece = b.getPiece(x, y);
	pair<int, int> inc;

	while (i < 8) {
		ori = Board::orientation[i];
		inc = Board::orientationInc[ori];
		if (b.countConnectedPieces(x, y, piece, ori)  == 1 &&
			b.getPiece(x + get<0>(inc), y + get<1>(inc)) == EMPTY_PIECE &&
			b.getPiece(x + get<0>(inc) * -1, y + get<1>(inc) * -1) == EMPTY_PIECE &&
			b.countConnectedPieces(x + get<0>(inc) * 2, y + get<1>(inc) * 2, piece, ori) == 2 &&
			b.rowEndsWithPiece(x + get<0>(inc) * 2, y + get<1>(inc) * 2, piece, EMPTY_PIECE, ori)) {
			return true;
		}
		i++;
	}
	return false;
}

void 		AThreat::printThreats(Board &b) {
	cout << "WHITE";
	for (int i = 0; i < NUMBER_THREATS; i++) {
		cout << " " << AThreat::threatsName[i] << ": " << whiteThreats[AThreat::threatsName[i]];
	}
	cout << endl << "BLACK";
	for (int i = 0; i < NUMBER_THREATS; i++) {
		cout << " " << AThreat::threatsName[i] << ": " << blackThreats[AThreat::threatsName[i]];
	}
	cout << endl;
}

bool AThreat::isXStraight(Board &b, int x, int y, int nb) {
	int i = 0;
	t_piece piece = b.getPiece(x, y);

	while (i < 8) {
		if (b.countConnectedPieces(x, y, piece, Board::orientation[i]) +
			b.countConnectedPieces(x, y, piece, Board::orientation[i + 1]) - 1 == nb &&
			b.rowEndsWithPiece(x, y, piece, EMPTY_PIECE, Board::orientation[i]) &&
			b.rowEndsWithPiece(x, y, piece, EMPTY_PIECE, Board::orientation[i + 1])) {
			return true;
		}
		i += 2;
	}
	return false;
}

void 		AThreat::computeScore(Board &b) {
	int whiteScore = 0;
	int blackScore = 0;

	for (int i = 0; i < NUMBER_THREATS; i++) {
		whiteScore += whiteThreats[AThreat::threatsName[i]] * threatsScore[AThreat::threatsName[i]];
		blackScore += blackThreats[AThreat::threatsName[i]] * threatsScore[AThreat::threatsName[i]];
	}
	b.score = blackScore - whiteScore;
	if (Game::currentPlayer != P_BLACK)
		b.score *= -1;
}

void 		AThreat::countThreats(Board &b, int x, int y, unordered_map<string, int> *t) {
	int i = 0, maxV = 0, value = 0, oriIndex = 0;
	bool isStraightLeft = false, isStraightRight = false;

	t_piece piece = b.getPiece(x, y);
	while (i < 8) {
		value = b.countConnectedPieces(x, y, piece, Board::orientation[i]) +
			b.countConnectedPieces(x, y, piece, Board::orientation[i + 1]) - 1;
		if (value > maxV) {
			maxV = value;
			oriIndex = i;
		}
		i += 2;
	}
	isStraightLeft = b.rowEndsWithPiece(x, y, piece, EMPTY_PIECE, Board::orientation[oriIndex]);
	isStraightRight = b.rowEndsWithPiece(x, y, piece, EMPTY_PIECE, Board::orientation[oriIndex + 1]);
	if (maxV >= 5) {
		(*t)["FIVE"] += 1;
	} else if (maxV == 4 && isStraightLeft && isStraightRight) {
		(*t)["STRAIGHT_FOUR"]++;
	} else if (maxV == 4 && (isStraightLeft || isStraightRight)) {
		(*t)["FOUR"]++;
	} else if (maxV == 3 && isStraightLeft && isStraightRight) {
		(*t)["THREE"]++;
	} else if (isBrokenThree(b, x, y)) {
		(*t)["BROKEN_THREE"]++;
	}
	if (b.lastMoveIsCapture) {
		(*t)["CAPTURE"] += 1;
	}

}

void 		AThreat::arrangeThreats(Board &b, unordered_map<string, int> *t) {
	(*t)["FIVE"] /= 5;
	(*t)["STRAIGHT_FOUR"] /= 4;
	(*t)["FOUR"] /= 4;
	(*t)["THREE"] /= 3;
}

void		AThreat::computeThreats(Board &b) {
	t_piece p;
	int x, y;

	clearThreats();
	for (unordered_map<string, pair<int, int> >::iterator it = b.pieces.begin(); it != b.pieces.end(); ++it) {
		x = get<0>((*it).second);
		y = get<1>((*it).second);
		p = b.getPiece(x, y);
		if (p == WHITE_PIECE) {
			countThreats(b, x, y, &whiteThreats);
		} else if (p == BLACK_PIECE) {
			countThreats(b, x, y, &blackThreats);
		}
	}
	arrangeThreats(b, &whiteThreats);
	arrangeThreats(b, &blackThreats);
	computeScore(b);
}
