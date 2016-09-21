#ifndef SOLVER_HPP
# define SOLVER_HPP

#include "Board.hpp"

class Board;
class Solver {

public:
	Solver(void);
	// Solver(Solver &rhs);
	~Solver(void);

	void solve(Board *board);
};

#endif
