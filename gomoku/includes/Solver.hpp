#ifndef SOLVER_HPP
# define SOLVER_HPP

# include <vector>
# include <cmath>

# define MAX_VALUE 1000000

class Board;
class Solver {

private:
	t_color currentPlayerColor;

public:
	Solver();
	~Solver(void);

	bool isWinner(int x, int y, Board *board);
	std::pair<int,int> solve(Board *board);
	void  deleteAll(std::vector<Board*> moves);
	Board *alphaBetaMinMax(Board *board, t_color color, int depth, int alpha, int beta);
};

#endif
