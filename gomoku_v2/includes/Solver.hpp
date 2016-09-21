#ifndef SOLVER_HPP
# define SOLVER_HPP

#include "Board.hpp"
#include <vector>

# define MAX_VALUE 1000000

class Board;
class Solver {

public:
	Solver(void);
	// Solver(Solver &rhs);
	~Solver(void);

	bool isGameFinished(Board *board);
	Board *minMaxAlphaBeta(Board *board, int depth, int alpha, int beta);
	pair<int, int> solve(Board *board);
};

#endif
