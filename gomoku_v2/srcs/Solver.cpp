#include "Solver.hpp"

bool sortBoardsByScore (Board *a, Board *b) {
	return a->score > b->score;
}

Solver::Solver() {
}

Solver::~Solver(void) {
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
	move = minMaxAlphaBeta(board, color, 1, -MAX_VALUE, MAX_VALUE);
	res = move->lastMove;
	delete move;
	return res;
}

bool Solver::isGameFinished(Board *board) {
	if (board->threat->whiteThreats["FIVE"] != 0 || board->threat->blackThreats["FIVE"] != 0)
		cout << "Five Detected"<< endl;
	return board->threat->whiteThreats["FIVE"] != 0 || board->threat->blackThreats["FIVE"] != 0;
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
