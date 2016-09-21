#include "Board.hpp"
#include "Solver.hpp"

Solver::Solver() {
}

Solver::~Solver(void) {
}


/************************************************************************/
/************************     AlphaBeta MinxMAX *************************/
/************************************************************************/

std::pair<int,int> Solver::solve(Board *board) {
	if (board->rectangles.size() == 0)
		return std::make_pair(SIZE / 2, SIZE / 2);
	board = this->alphaBetaMinMax(board, board->curTurn, 2, -MAX_VALUE, MAX_VALUE);
}

void  Solver::deleteAll(std::vector<Board*> moves) {
	for (std::vector<Board *>::iterator it = moves.begin(); it != moves.end(); it++) {
		delete (*it);
	}
}

Board *Solver::alphaBetaMinMax(Board *board, t_color color, int depth, int alpha, int beta) {
	if (depth == 0) {
		return board;
	}
	else {
		int bestMoveValue = -MAX_VALUE;
		Board *move = NULL;
		Board *bestMove = NULL;
		std::vector<Board*> moves;
		t_color invColor = INV(color);

		moves = board->listAllMoves(color);
		for (std::vector<Board *>::iterator it = moves.begin(); it != moves.end(); it++) {
			if (*it)
				move = alphaBetaMinMax((*it), invColor, depth - 1, -beta, -alpha);
			if (move && *it)
			{
				if((*it)->isGameFinished(std::get<0>((*it)->lastMove), std::get<1>((*it)->lastMove)))
					return (*it);
				if (-move->score > bestMoveValue) {
					bestMoveValue = -move->score;
					if((*it)->isGameFinished(std::get<0>((*it)->lastMove), std::get<1>((*it)->lastMove)))
						return (*it);
					if (bestMoveValue > alpha) {
						alpha = bestMoveValue;
						bestMove = (*it);
						if (alpha >= beta) {
							this->deleteAll(moves);
							return bestMove;
						}
					}
				}
			}
		}
		this->deleteAll(moves);
		return bestMove;
	}
}
