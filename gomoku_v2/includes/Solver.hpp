#ifndef SOLVER_HPP
# define SOLVER_HPP

#include "Board.hpp"
#include <vector>

#define PADDING 1
#define MAX_DEPTH 3

class Solver {

public:
	Solver(void);
	~Solver(void);

	bool isGameFinished(Board *board);
	Board *minMaxAlphaBeta(Board *board, int depth, int alpha, int beta);
	pair<int, int> solve(Board *board);
	vector<Board *> listAllMoves(Board *b);
	Board *AlpaBetaMaxMove(Board *board, short int depth, int alpha, int beta);
	Board *AlpaBetaMinMove(Board* board, short int depth, int alpha, int beta);
};

#endif
