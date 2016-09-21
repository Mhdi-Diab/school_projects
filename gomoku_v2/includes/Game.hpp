#ifndef GAME_HPP
# define GAME_HPP

#include <iostream>
using namespace std;

# include "Rectangle.hpp"
# include "Board.hpp"
# include "Player.hpp"
# include "Solver.hpp"

# define INV(X) (X) == (BLACK) ? (WHITE) : (BLACK)

class Board;
class Game {

public:
	Board			*board;
	Solver			*solver;
	Player			*player[2];
	t_player_color	currentPlayer;

	Game(void);
	// Game(Game &rhs);
	~Game(void);
	void loop(void);
};
#endif
