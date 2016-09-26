#include "Solver.hpp"
#include "utils.hpp"

Solver::Solver() {
}

Solver::~Solver(void) {
}

//TODO: shrink to one function
priority_queue<Board, vector<Board>, greater<Board> > Solver::listAllMoves(Board const &b) {
	int x, y;
	priority_queue<Board, vector<Board>, greater<Board> > queue;
	priority_queue<Board, vector<Board>, greater<Board> > queue2;
	unordered_map<string, bool> alreadyUsed;

	for (unordered_map<string, pair<int, int> >::const_iterator it = b.pieces.begin(); it != b.pieces.end(); ++it) {
		x = get<0>(it->second);
		y = get<1>(it->second);
		for (int yy = y - PADDING; yy <= y + PADDING; yy++) {
			for (int xx = x - PADDING; xx <= x + PADDING; xx++) {
				if (yy >= 0 && yy < BOARD_SIZE && xx >= 0 && xx < BOARD_SIZE && !alreadyUsed[myHash(xx, yy)] && b.board[yy][xx] == EMPTY_PIECE) {
					Board board = b;
					board.placePiece(xx, yy, b.turn);
					queue.push(board);
					alreadyUsed[myHash(xx, yy)] = true;
				}
			}
		}
	}
	return queue;
}

//TODO: shrink to one function
priority_queue<Board, vector<Board>, less<Board> > Solver::listAllMovesRev(Board const &b) {
	int x, y;
	priority_queue<Board, vector<Board>, less<Board> > queue;
	unordered_map<string, bool> alreadyUsed;

	for (unordered_map<string, pair<int, int> >::const_iterator it = b.pieces.begin(); it != b.pieces.end(); ++it) {
		x = get<0>(it->second);
		y = get<1>(it->second);
		for (int yy = y - PADDING; yy <= y + PADDING; yy++) {
			for (int xx = x - PADDING; xx <= x + PADDING; xx++) {
				if (yy >= 0 && yy < BOARD_SIZE && xx >= 0 && xx < BOARD_SIZE && !alreadyUsed[myHash(xx, yy)] && b.board[yy][xx] == EMPTY_PIECE) {
					Board board = b;
					board.placePiece(xx, yy, b.turn);
					queue.push(board);
					alreadyUsed[myHash(xx, yy)] = true;
				}
			}
		}
	}
	return queue;
}

pair<int, int> Solver::solve(Board const &board) {
	Board move;
	pair<int, int> res;

	if (board.pieces.size() == 0) {
		return make_pair(BOARD_SIZE / 2, BOARD_SIZE / 2);
	}
	move = AlphaBetaMaxMove(board, MAX_DEPTH, -MAX_VALUE, MAX_VALUE);
	res = move.lastMove;
	if (get<0>(res) == -1 || get<1>(res) == -1) {
		while (true) {
			res = make_pair(rand() % 19, rand() % 19);
			if (((Board &)board).getPiece(get<0>(res), get<1>(res) == EMPTY_PIECE))
				break ;
		}
	}
	return res;
}

bool Solver::isGameFinished(Board &board) {
	return board.threat.whiteThreats["FIVE"] != 0 || board.threat.blackThreats["FIVE"] != 0;
}

Board Solver::AlphaBetaMaxMove(Board const &board, short int depth, int alpha, int beta) {
	priority_queue<Board, vector<Board>, greater<Board> > moves;
	Board current;
	Board bestMove;
	Board move;

	if (depth == 0) {
		return board;;
	}
	moves = listAllMoves(board);
	while (!moves.empty()) {
		current = moves.top();
		moves.pop();
		if (isGameFinished(current)) {
			return current;
		}
		move = AlphaBetaMinMove(current, depth - 1, alpha, beta);
			if (move.score > alpha) {
			bestMove = current;
			alpha = move.score;
			if (beta < alpha) {
				return bestMove;
			}
		}
	}
	return bestMove;
}

Board Solver::AlphaBetaMinMove(Board const &board, short int depth, int alpha, int beta) {
	priority_queue<Board, vector<Board>, less<Board> > moves;
	Board current;
	Board bestMove;
	Board move;

	if (depth == 0) {
		return board;
	}
	moves = listAllMovesRev(board);
	while (!moves.empty()) {
		current = moves.top();
		moves.pop();
		if (isGameFinished(current)) {
			return current;
		}
		move = AlphaBetaMaxMove(current, depth - 1, alpha, beta);
		if (move.score < beta) {
			beta = move.score;
			bestMove = current;
			if (beta < alpha) {
				return bestMove;
			}
		}
	}
	return bestMove;
}
