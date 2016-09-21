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
	int alphaBeta(Board *board, t_color color, int depth, int alpha, int beta);
	std::pair<int,int> solve(Board *board, t_color color);
	Board *AlpaBetaMaxMove(Board *board, t_color color, short int depth, int alpha, int beta);
	Board *AlpaBetaMinMove(Board* board, t_color color, short int depth, int alpha, int beta);
	Board *alphaBetaMinMax(Board *board, t_color color, int profondeur, int alpha, int beta);
	void  deleteAll(std::vector<Board*> moves);
	bool isDirectThreat(Board *board, t_color color);
	Board *getOneMove(Board *board, t_color color);
	Board *defendDirectThreat(Board *board, t_color color, int depth, int alpha, int beta);
};

#endif
