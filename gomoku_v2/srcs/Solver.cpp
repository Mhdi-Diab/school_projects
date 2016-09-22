#include "Solver.hpp"

static bool superiorCmp(int a, int b) {
	return a >= b;
}

bool sortBoardsByScore (Board *a, Board *b) {
	return a->score > b->score;
}

Solver::Solver() {
}

Solver::~Solver(void) {
}

int	Solver::computeScore(Board *board) {
	(void)board;
	return (0);
}

vector<Board *> Solver::listAllMoves(Board *b, t_player_color color) {
	vector <Board *> vec;

	for (vector<Rectangle *>::iterator iter = b->rectangles->begin(); iter != b->rectangles->end(); iter++) {
		for (int y = (*iter)->getTopLeftY(); y <= (*iter)->getBottomRightY(); y++) {
			for (int x = (*iter)->getTopLeftX(); x <= (*iter)->getBottomRightX(); x++) {
				if (b->board[y][x] == EMPTY) {
					Board *board = new Board(*b);
					if (board->placePiece(x, y, PIECE(color))) {
						board->score = computeScore(board);
						vec.push_back(board);
					}
					else
						delete board;
				}
			}
		}
	}
	sort(vec.begin(), vec.end(), sortBoardsByScore);
	return vec;
}

pair<int, int> Solver::solve(Board *board, t_player_color color) {
	Board *move;
	if (board->pieces.size() == 0) {
		return make_pair(BOARD_SIZE / 2, BOARD_SIZE / 2);
	}
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
		moves = listAllMoves(board, color);
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
