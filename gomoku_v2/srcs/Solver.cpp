#include "Solver.hpp"

Solver::Solver() {
}

Solver::~Solver(void) {
}

pair<int, int> Solver::solve(Board *board) {
	// Board *move;

	// move = minMaxAlphaBeta(board, 1, -MAX_VALUE, MAX_VALUE);
	cout << "SOLVER" << endl;
	return make_pair(rand() % 19, rand() % 19);
	// return move->previousMove;
}

bool Solver::isGameFinished(Board *board) {
	(void)board;

	return false;
}

Board *Solver::minMaxAlphaBeta(Board *board, int depth, int alpha, int beta) {
	int bestMoveValue = -MAX_VALUE;
	Board *move = NULL;
	Board *bestMove = NULL;
	vector<Board *> moves;

	if (depth == 0 ) {
		return board;
	}
	else {
		moves = board->listAllMoves();
		for (vector<Board *>::iterator it = moves.begin(); it != moves.end(); it++) {
			if (isGameFinished(*it)) {
				return (*it);
			}
			move = minMaxAlphaBeta((*it), depth - 1, -beta, -alpha);
			if (move)
			{
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
}
