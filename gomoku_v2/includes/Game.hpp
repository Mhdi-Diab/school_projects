#ifndef GAME_HPP
# define GAME_HPP

#include <iostream>
#include <string>
using namespace std;

# include "Board.hpp"
# include "Player.hpp"
# include "Solver.hpp"
# include "Render.hpp"

class Board;
class Solver;
class Game {

public:
	bool			isFinished;
	Board			*board;
	Render			*render;
	Solver			*solver;
	Player			*player[2];
	t_player_color	currentPlayer;

	Game(void);
	// Game(Game &rhs);
	~Game(void);

	bool 			playOneTurn(Event *event);
	void 			loop(void);
	bool 			getPlayerMove(Event *event);
	bool			getAIMove();
};

#endif
