#include "Solver.hpp"

bool sortBoardsByScore (Board *a, Board *b) {
	return a->score > b->score;
}

Solver::Solver() {
}

Solver::~Solver(void) {
}

vector<Board *> Solver::listAllMoves(Board *b, t_player_color color) {
	vector <Board *> vec;
	int x = 0;
	int y = 0;
//TODO: a changer
	if (b->board[y][x] == EMPTY) {
		Board *board = new Board(*b);
		if (board->placePiece(x, y, PIECE(color))) {
			vec.push_back(board);
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
	move = minMaxAlphaBeta(board, color, 3, -MAX_VALUE, MAX_VALUE);
	res = move->lastMove;
	delete move;
	return res;
}

bool Solver::isGameFinished(Board *board) {
	if (board->threatsCount["FIVE"] != 0)
		cout << "Five Detected"<< endl;
	return board->threatsCount["FIVE"] != 0;
}

Board *Solver::minMaxAlphaBeta(Board *board, t_player_color color, int depth, int alpha, int beta) {
	int bestMoveValue = -MAX_VALUE;
	Board *move = NULL;
	Board *bestMove = NULL;
	vector<Board *> moves;
	// clock_t start, end;

	if (depth == 0 ) {
		return board;
	}
	// start = clock();
	moves = listAllMoves(board, color);
	// end = clock();
	// cout << "listAllMoves" << (double)(end-start)/CLOCKS_PER_SEC << " seconds." << endl;
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
