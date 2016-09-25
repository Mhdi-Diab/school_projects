#include "Solver.hpp"

bool sortBoardsByScore (Board *a, Board *b) {
	return a->score > b->score;
}

Solver::Solver() {
}

Solver::~Solver(void) {
}

vector<Board *> Solver::listAllMoves(Board *b) {
	int x, y;
	vector <Board *> vec;
	unordered_map<string, bool> alreadyUsed;
	t_piece piece = INV(b->getPiece(get<0>(b->lastMove), get<1>(b->lastMove)));

	for (unordered_map<string, pair<int, int> >::iterator it = b->pieces.begin(); it != b->pieces.end(); ++it) {
		x = get<0>(it->second);
		y = get<1>(it->second);
		for (int yy = y - PADDING; yy <= y + PADDING; yy++) {
			for (int xx = x - PADDING; xx <= x + PADDING; xx++) {
				if (yy >= 0 && yy < BOARD_SIZE && xx >= 0 && xx < BOARD_SIZE && !alreadyUsed[myHash(xx, yy)] && b->board[yy][xx] == EMPTY_PIECE) {
					Board *board = new Board(*b);
					board->placePiece(xx, yy, piece);
					vec.push_back(board);
					alreadyUsed[myHash(xx, yy)] = true;
				}
			}
		}
	}
	sort(vec.begin(), vec.end(), sortBoardsByScore);
	return vec;
}

pair<int, int> Solver::solve(Board *board) {
	Board *move;
	pair<int, int> res;

	if (board->pieces.size() == 0) {
		return make_pair(BOARD_SIZE / 2, BOARD_SIZE / 2);
	}
	move = AlpaBetaMaxMove(board, 4, -MAX_VALUE, MAX_VALUE);
	res = move->lastMove;
	delete move;
	return res;
}

bool Solver::isGameFinished(Board *board) {
	if (board->threat->whiteThreats["FIVE"] != 0)
		cout << "White Five Detected"<< endl;
	if (board->threat->blackThreats["FIVE"] != 0)
		cout << "Black Five Detected"<< endl;
	return board->threat->whiteThreats["FIVE"] != 0 || board->threat->blackThreats["FIVE"] != 0;
}

Board *Solver::AlpaBetaMaxMove(Board *board, short int depth, int alpha, int beta) {
	vector<Board *> moves;
	Board *bestMove = NULL;
	Board *move = NULL;
	int count = 0;

	if (depth == 0) {
		return board;
	}
	moves = listAllMoves(board);
	for (vector<Board *>::iterator it = moves.begin(); it != moves.end(); it++) {
		cout << "depth: " << depth << " c: " << ++count << endl;
		if (isGameFinished(*it))
			return (*it);
		move = AlpaBetaMinMove(*it, depth - 1, alpha, beta);
		if (move) {
			cout << "Max, score: " << move->score << " alpha: " << alpha << endl;
 			if (move->score > alpha) {
				bestMove = *it;
				alpha = move->score;
				if (beta > alpha) {
					return bestMove;
				}
			}
		}
	}
	return bestMove;
}

Board *Solver::AlpaBetaMinMove(Board* board, short int depth, int alpha, int beta) {
	vector<Board*> moves;
	Board *bestMove = NULL;
	Board *move = NULL;
	int count = 0;

	if (depth == 0) {
		return board;
	}
	moves = listAllMoves(board);
	for (vector<Board*>::iterator it = moves.begin(); it != moves.end(); it++) {
		cout << "depth: " << depth << " c: " << ++count << endl;
		if (isGameFinished(*it)) {
			return (*it);
		}
		move = AlpaBetaMaxMove(*it, depth - 1, alpha, beta);
		if (move) {
			cout << "Min, score: " << move->score << " beta: " << beta << endl;
			if (-move->score < beta) {
				beta = -move->score;
				bestMove = *it;
				if (beta < alpha) {
					return bestMove;
				}
			}
		}
	}
	return bestMove;
}
