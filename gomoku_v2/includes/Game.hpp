#ifndef GAME_HPP
# define GAME_HPP

#include <iostream>
#include <string>
using namespace std;

# define PIECE(X) ((X) == (P_BLACK) ? (BLACK_PIECE) : (WHITE_PIECE))

# include "Board.hpp"
# include "Player.hpp"
# include "Solver.hpp"
# include "Render.hpp"
# include <time.h>

class Board;
class Solver;
class Game {

public:
	bool			isFinished;
	Board			*board;
	Render			*render;
	Solver			*solver;
	Player			*player[2];
	static t_player_color	currentPlayer;

	Game(void);
	~Game(void);
	void 			loop(void);
	bool			getAIMove(void);
	bool 			playOneTurn(Event *event);
	bool 			getPlayerMove(Event *event);
};

#endif
