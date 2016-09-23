#include "Solver.hpp"

bool sortBoardsByScore (Board *a, Board *b) {
	return a->score > b->score;
}

Solver::Solver() {
}

Solver::~Solver(void) {
}

bool Solver::isX(Board *b, int x, int y, int nb) {
	int i = 0;
	t_piece piece = b->getPiece(x, y);

	while (i < 8) {
		if (b->countConnectedPieces(x, y, piece, Board::orientation[i]) +
			b->countConnectedPieces(x, y, piece, Board::orientation[i + 1]) - 1 == nb &&
			(b->rowEndsWithPiece(x, y, EMPTY, Board::orientation[i]) ||
			b->rowEndsWithPiece(x, y, EMPTY, Board::orientation[i + 1]))) {
			return true;
		}
		i += 2;
	}
	return false;
}

bool Solver::isXStraight(Board *b, int x, int y, int nb) {
	int i = 0;
	t_piece piece = b->getPiece(x, y);

	while (i < 8) {
		if (b->countConnectedPieces(x, y, piece, Board::orientation[i]) +
			b->countConnectedPieces(x, y, piece, Board::orientation[i + 1]) - 1 == nb &&
			b->rowEndsWithPiece(x, y, EMPTY, Board::orientation[i]) &&
			b->rowEndsWithPiece(x, y, EMPTY, Board::orientation[i + 1])) {
			return true;
		}
		i += 2;
	}
	return false;
}

void 		Solver::findThreats(Board *b, int x, int y, unordered_map<string, int> *threats) {
	(*threats)["FIVE"] += isX(b, x, y, 5);
	(*threats)["STRAIGHT_FOUR"] += isXStraight(b, x, y, 4);
	(*threats)["FOUR"] += isX(b, x, y, 4);
	(*threats)["THREE"] += isXStraight(b, x, y, 3);
	(*threats)["TWO"] += isXStraight(b, x, y, 2);
}

void 		Solver::printThreats(Board *b) {
	cout << "-----WHITE------" << endl;
	cout << " FIVE: " << b->whiteThreats["FIVE"];
	cout << " FOUR: " << b->whiteThreats["FOUR"];
	cout << " STRAIGHT_FOUR: " << b->whiteThreats["STRAIGHT_FOUR"];
	cout << " THREE: " << b->whiteThreats["THREE"] << endl;
	cout << " -----BLACK------" << endl;
	cout << " FIVE: " << b->blackThreats["FIVE"];
	cout << " FOUR: " << b->blackThreats["FOUR"];
	cout << " STRAIGHT_FOUR: " << b->blackThreats["STRAIGHT_FOUR"];
	cout << " THREE: " << b->blackThreats["THREE"] << endl;
}

void 		Solver::computeScore(Board *b, t_player_color color) {
	int whiteScore = 0;
	int blackScore = 0;

	// b->whiteThreats["FIVE"] /= 5;
	// b->whiteThreats["FOUR"] /= 4;
	// b->whiteThreats["STRAIGHT_FOUR"] /= 4;
	// b->whiteThreats["THREE"] /= 3;
	// b->whiteThreats["TWO"] /= 2;
	//
	// b->blackThreats["FIVE"] /= 5;
	// b->blackThreats["FOUR"] /= 4;
	// b->blackThreats["STRAIGHT_FOUR"] /= 4;
	// b->blackThreats["THREE"] /= 3;
	// b->blackThreats["TWO"] /= 2;

	for (int i = 0; i < 7; i++) {
		whiteScore += b->whiteThreats[AThreat::threatsName[i]] * b->threatsScore[AThreat::threatsName[i]];
		blackScore += b->blackThreats[AThreat::threatsName[i]] * b->threatsScore[AThreat::threatsName[i]];
	}
	if (color == P_BLACK) {
		b->score = blackScore - whiteScore;
	} else {
		b->score = whiteScore - blackScore;
	}
}

void		Solver::computeThreats(Board *b, t_player_color color) {
	t_piece p;
	int x, y;

	b->clearThreats();
	x = get<0>(b->lastMove);
	y = get<1>(b->lastMove);
	p = b->getPiece(x, y);
	if (p == WHITE) {
		b->whiteThreats["FIVE"] += isX(b, x, y, 5);
		b->whiteThreats["STRAIGHT_FOUR"] += isXStraight(b, x, y, 4);
		b->whiteThreats["FOUR"] += isX(b, x, y, 4);
		b->whiteThreats["THREE"] += isXStraight(b, x, y, 3);
		b->whiteThreats["TWO"] += isXStraight(b, x, y, 2);
	} else if (p == BLACK) {
		b->blackThreats["FIVE"] += isX(b, x, y, 5);
		b->blackThreats["STRAIGHT_FOUR"] += isXStraight(b, x, y, 4);
		b->blackThreats["FOUR"] += isX(b, x, y, 4);
		b->blackThreats["THREE"] += isXStraight(b, x, y, 3);
		b->blackThreats["TWO"] += isXStraight(b, x, y, 2);
	}
	computeScore(b, color);
	printThreats(b);
}

vector<Board *> Solver::listAllMoves(Board *b, t_player_color color) {
	int x, y;
	vector <Board *> vec;
	unordered_map<string, bool> alreadyUsed;

	for (unordered_map<string, pair<int, int> >::iterator it = b->pieces.begin(); it != b->pieces.end(); ++it) {
		x = get<0>(it->second);
		y = get<1>(it->second);
		for (int yy = y - 2; yy <= y + 2; yy++) {
			for (int xx = x - 2; xx <= x + 2; xx++) {
				if (yy >= 0 && yy < BOARD_SIZE && xx >= 0 && xx < BOARD_SIZE && !alreadyUsed[myHash(xx, yy)] && b->board[yy][xx] == EMPTY) {
					Board *board = new Board(*b);
					board->placePiece(xx, yy, PIECE(color));
					computeThreats(board, color);
					vec.push_back(board);
					alreadyUsed[myHash(xx, yy)] = true;
				}
			}
		}
	}
	sort(vec.begin(), vec.end(), sortBoardsByScore);
	return vec;
}

pair<int, int> Solver::solve(Board *board, t_player_color color) {
	Board *move;
	pair<int, int> res;

	if (board->pieces.size() == 0) {
		return make_pair(BOARD_SIZE / 2, BOARD_SIZE / 2);
	}
	move = minMaxAlphaBeta(board, color, 2, -MAX_VALUE, MAX_VALUE);
	res = move->lastMove;
	delete move;
	return res;
}

bool Solver::isGameFinished(Board *board) {
	if (board->whiteThreats["FIVE"] != 0 || board->blackThreats["FIVE"] != 0)
		cout << "Five Detected"<< endl;
	return board->whiteThreats["FIVE"] != 0 || board->blackThreats["FIVE"] != 0;
}

Board *Solver::minMaxAlphaBeta(Board *board, t_player_color color, int depth, int alpha, int beta) {
	int bestMoveValue = -MAX_VALUE;
	Board *move = NULL;
	Board *bestMove = NULL;
	vector<Board *> moves;

	if (depth == 0 ) {
		return board;
	}
	moves = listAllMoves(board, color);
	for (vector<Board *>::iterator it = moves.begin(); it != moves.end(); it++) {
		if (isGameFinished(*it)) {
			return (*it);
		}
		move = minMaxAlphaBeta((*it), OPPONENT(color), depth - 1, -beta, -alpha);
		if (move) {
			if (isGameFinished(move))
				return (*it);
			if (-move->score > bestMoveValue) {
				bestMoveValue = -move->score;
				if (bestMoveValue > alpha) {
					alpha = bestMoveValue;
					bestMove = (*it);
					if (alpha >= beta) {
						return bestMove;
					}
				}
			}
		}
	}
	return bestMove;
}
