#include "Board.hpp"
#include "Solver.hpp"

Solver::Solver() {
}

Solver::~Solver(void) {
}


/************************************************************************/
/************************     AlphaBeta MinxMAX *************************/
/************************************************************************/

bool				Solver::isDirectThreat(Board *board, t_color color) {
	return (board->threats[std::make_pair(INV(color), FOUR)] != 0 ||
		board->threats[std::make_pair(INV(color), STRAIGHT_FOUR)] != 0 ||
		board->threats[std::make_pair(INV(color), TWO_TWO)] != 0 ||
		board->threats[std::make_pair(INV(color), BROKEN_FOUR)] != 0);
}

std::pair<int,int> Solver::solve(Board *board, t_color color) {
	Board *b;
	if (board->rectangles.size() == 0)
		return std::make_pair(SIZE / 2, SIZE / 2);
	if (this->isDirectThreat(board, color) || DEPTH_LIMIT < 3)
		b = this->defendDirectThreat(board, color, 2, -MAX_VALUE, MAX_VALUE);
	else
		b = this->AlpaBetaMaxMove(board, color, 1, -MAX_VALUE, MAX_VALUE);
	if (!b) {
		b = this->getOneMove(board, color);
	}
	return b->lastMove;
}

void  Solver::deleteAll(std::vector<Board*> moves) {
	for (std::vector<Board *>::iterator it = moves.begin(); it != moves.end(); it++) {
		delete (*it);
	}
}

Board *Solver::AlpaBetaMaxMove(Board *board, t_color color, short int depth, int alpha, int beta) {
	std::vector<Board *> moves;
	Board *bestMove = NULL;
	Board *bestRealMove = NULL;
	Board *move = NULL;
	int moveValue;
	int bestMoveValue = MAX_VALUE;

	if (depth >= DEPTH_LIMIT) {
		return board;
	} else {
		moves = board->listAllMoves(color);
		for (std::vector<Board *>::iterator it = moves.begin(); it != moves.end(); it++) {
			if (*it)
				move = AlpaBetaMinMove(*it, color, depth + 1, -alpha, -beta);
			if (move && *it)
			{
				if((*it)->isGameFinished(std::get<0>((*it)->lastMove), std::get<1>((*it)->lastMove)))
					return (*it);
				moveValue = move->score;
				if (bestMove == NULL || moveValue > bestMoveValue) {
					bestMove = move;
					bestMoveValue = moveValue;
					bestRealMove = *it;
					alpha = moveValue;
				}
				if (beta > alpha) {
					this->deleteAll(moves);
					return bestRealMove;
				}
			}
		}
		this->deleteAll(moves);
		return bestRealMove;
	}
}

Board *Solver::AlpaBetaMinMove(Board* board, t_color color, short int depth, int alpha, int beta) {
	std::vector<Board*> moves;
	Board *bestMove = NULL;
	Board *bestRealMove = NULL;
	Board *move = NULL;
	int moveValue;
	int bestMoveValue = -1;

	t_color eColor = INV(color);
	if (depth >= DEPTH_LIMIT) {
		return board;
	} else {
		moves = board->listAllMoves(eColor);
		for (std::vector<Board*>::iterator it = moves.begin(); it != moves.end(); it++) {
			if (*it)
				move = AlpaBetaMaxMove(*it, color, depth + 1, -alpha, -beta);
			if (move && *it)
			{
				if((*it)->isGameFinished(std::get<0>((*it)->lastMove), std::get<1>((*it)->lastMove)))
					return (*it);
				moveValue = -move->score;
				if (bestMove == NULL || moveValue < bestMoveValue) {
					bestMove = move;
					bestMoveValue = moveValue;
					bestRealMove = *it;
					beta = bestMoveValue;
				}
				if (beta <= alpha) {
					this->deleteAll(moves);
					return bestRealMove;
				}
			}
		}
		this->deleteAll(moves);
		return bestRealMove;
	}
}

Board *Solver::getOneMove(Board *board, t_color color) {
	std::vector<Board*> moves;

	moves = board->listAllMoves(color);
	for (std::vector<Board*>::iterator it = moves.begin(); it != moves.end(); it++) {
		if (*it)
			return (*it);
	}
	return (board);
}

Board *Solver::defendDirectThreat(Board *board, t_color color, int depth, int alpha, int beta) {
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
				move = defendDirectThreat((*it), invColor, depth - 1, -beta, -alpha);
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
