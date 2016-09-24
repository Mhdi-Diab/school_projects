#ifndef SOLVER_HPP
# define SOLVER_HPP

#include "Board.hpp"
#include <vector>

#define PADDING 1

class Solver {

public:
	Solver(void);
	~Solver(void);

	bool isGameFinished(Board *board);
	Board *minMaxAlphaBeta(Board *board, t_player_color c, int depth, int alpha, int beta);
	pair<int, int> solve(Board *board, t_player_color color);
	vector<Board *> listAllMoves(Board *b, t_player_color color);
	Board *AlpaBetaMaxMove(Board *board, t_player_color color, short int depth, int alpha, int beta);
	Board *AlpaBetaMinMove(Board* board, t_player_color color, short int depth, int alpha, int beta);
};

#endif
