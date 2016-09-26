#ifndef SOLVER_HPP
# define SOLVER_HPP

#include "Board.hpp"
#include <queue>

#define PADDING 1
#define MAX_DEPTH 2

class Solver {

public:
	Solver(void);
	~Solver(void);

	bool isGameFinished(Board const &board);
	Board minMaxAlphaBeta(Board const &board, int depth, int alpha, int beta);
	pair<int, int> solve(Board const &board);
	priority_queue<Board, vector<Board>, greater<Board> > listAllMoves(Board const &b);
	priority_queue<Board, vector<Board>, less<Board> > listAllMovesRev(Board const &b);
	Board AlphaBetaMaxMove(Board const &board, short int depth, int alpha, int beta);
	Board AlphaBetaMinMove(Board const &board, short int depth, int alpha, int beta);
};

#endif
