#ifndef SOLVER_HPP
# define SOLVER_HPP

#include "Board.hpp"
#include <vector>

class Solver {

public:
	Solver(void);
	~Solver(void);

	bool isGameFinished(Board *board);
	Board *minMaxAlphaBeta(Board *board, t_player_color c, int depth, int alpha, int beta);
	pair<int, int> solve(Board *board, t_player_color color);
	vector<Board *> listAllMoves(Board *b, t_player_color color);
	bool isX(Board *board, int x, int y, int nb);
	bool isXStraight(Board *board, int x, int y, int nb);
	void findThreats(Board *b, int x, int y, unordered_map<string, int> *threats);
	void computeScore(Board *b, t_player_color color);
	void computeThreats(Board *b, t_player_color color);
	void printThreats(Board *b);
	Board *AlpaBetaMaxMove(Board *board, t_player_color color, short int depth, int alpha, int beta);
	Board *AlpaBetaMinMove(Board* board, t_player_color color, short int depth, int alpha, int beta);
};

#endif
