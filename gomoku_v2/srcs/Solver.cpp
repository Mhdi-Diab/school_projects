#include "Solver.hpp"
#include "utils.hpp"

Solver::Solver() {
}

Solver::~Solver(void) {
}

vector<Board *> Solver::listAllMoves(Board *b) {
	int x, y;
	vector <Board *> vec;
	unordered_map<string, bool> alreadyUsed;

	for (unordered_map<string, pair<int, int> >::iterator it = b->pieces.begin(); it != b->pieces.end(); ++it) {
		x = get<0>(it->second);
		y = get<1>(it->second);
		for (int yy = y - PADDING; yy <= y + PADDING; yy++) {
			for (int xx = x - PADDING; xx <= x + PADDING; xx++) {
				if (yy >= 0 && yy < BOARD_SIZE && xx >= 0 && xx < BOARD_SIZE && !alreadyUsed[myHash(xx, yy)] && b->board[yy][xx] == EMPTY_PIECE) {
					Board *board = new Board(*b);
					board->placePiece(xx, yy, b->turn);
					vec.push_back(board);
					alreadyUsed[myHash(xx, yy)] = true;
				}
			}
		}
	}
	return vec;
}

pair<int, int> Solver::solve(Board *board) {
	Board *move;
	pair<int, int> res;

	if (board->pieces.size() == 0) {
		return make_pair(BOARD_SIZE / 2, BOARD_SIZE / 2);
	}
	move = AlphaBetaMaxMove(board, MAX_DEPTH, -MAX_VALUE, MAX_VALUE);
	if (move) {
		res = move->lastMove;
		delete move;
	} else {
		while (42) {
			res = make_pair(rand() % 19, rand() % 19);
			if (board->getPiece(get<0>(res), get<1>(res) == EMPTY_PIECE))
				break ;
		}
	}
	return res;
}

bool Solver::isGameFinished(Board *board) {
	return board->threat->whiteThreats["FIVE"] != 0 || board->threat->blackThreats["FIVE"] != 0;
}

Board *Solver::deleteMovesAndReturn(vector<Board *> moves, Board *save) {
	Board *copy;

	if (!save)
		return save;
	copy = new Board(*save);
	for (vector<Board *>::iterator it = moves.begin(); it != moves.end(); it++) {
		delete *it;
	}
	return copy;
}

Board *Solver::AlphaBetaMaxMove(Board *board, short int depth, int alpha, int beta) {
	vector<Board *> moves;
	Board *bestMove = NULL;
	Board *move = NULL;

	if (depth == 0) {
		return new Board(*board);
	}
	moves = listAllMoves(board);
	sort(moves.begin(), moves.end(), sortBoardsByScore);
	for (vector<Board *>::iterator it = moves.begin(); it != moves.end(); it++) {
		if (isGameFinished(*it)) {
			// (*it)->print();
			return deleteMovesAndReturn(moves, *it);
		}
		move = AlphaBetaMinMove(*it, depth - 1, alpha, beta);
		if (move) {
 			if (move->score > alpha) {
				bestMove = *it;
				alpha = move->score;
				if (beta < alpha) {
					// cout << " max depth "<< depth << " beta: " << beta << " alpha: " << alpha << endl;
					return deleteMovesAndReturn(moves, bestMove);
				}
			}
			delete move;
		}
	}
	return deleteMovesAndReturn(moves, bestMove);
}

Board *Solver::AlphaBetaMinMove(Board* board, short int depth, int alpha, int beta) {
	vector<Board*> moves;
	Board *bestMove = NULL;
	Board *move = NULL;

	if (depth == 0) {
		return new Board(*board);
	}
	moves = listAllMoves(board);
	sort(moves.begin(), moves.end(), sortBoardsByScoreRev);
	for (vector<Board*>::iterator it = moves.begin(); it != moves.end(); it++) {
		if (isGameFinished(*it)) {
			// (*it)->print();
			return deleteMovesAndReturn(moves, *it);
		}
		move = AlphaBetaMaxMove(*it, depth - 1, alpha, beta);
		if (move) {
			if (move->score < beta) {
				beta = move->score;
				bestMove = *it;
				if (beta < alpha) {
					// cout << " min depth "<< depth << " beta: " << beta << " alpha: " << alpha << endl;
					return deleteMovesAndReturn(moves, bestMove);
				}
			}
			delete move;
		}
	}
	return deleteMovesAndReturn(moves, bestMove);
}
