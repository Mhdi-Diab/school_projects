#include "Solver.hpp"

static bool superiorCmp(int a, int b) {
	return a >= b;
}

Solver::Solver() {
}

Solver::~Solver(void) {
}

pair<int, int> Solver::solve(Board *board, t_player_color color) {
	Board *move;

	move = minMaxAlphaBeta(board, color, 2, -MAX_VALUE, MAX_VALUE);
	return move->lastMove;
}

bool Solver::isGameFinished(Board *board) {
	return board->hasXPiecesInRow(get<0>(board->lastMove), get<1>(board->lastMove), 5, superiorCmp);
}

Board *Solver::minMaxAlphaBeta(Board *board, t_player_color color, int depth, int alpha, int beta) {
	int bestMoveValue = -MAX_VALUE;
	Board *move = NULL;
	Board *bestMove = NULL;
	vector<Board *> moves;

	if (depth == 0 ) {
		return board;
	}
	else {
		moves = board->listAllMoves(color);
		for (vector<Board *>::iterator it = moves.begin(); it != moves.end(); it++) {
			if (isGameFinished(*it)) {
				return (*it);
			}
			move = minMaxAlphaBeta((*it), color, depth - 1, -beta, -alpha);
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
