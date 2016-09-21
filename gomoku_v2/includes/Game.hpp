#ifndef GAME_HPP
# define GAME_HPP

# define PIECE(X) (X) == (P_BLACK) ? (BLACK) : (WHITE)

#include <iostream>
#include <string>
using namespace std;

# include "Rectangle.hpp"
# include "Board.hpp"
# include "Player.hpp"
# include "Solver.hpp"

# define INV(X) (X) == (BLACK) ? (WHITE) : (BLACK)

class Board;
class Solver;
class Game {

public:
	Board			*board;
	Solver			*solver;
	Player			*player[2];
	t_player_color	currentPlayer;

					Game(void);
					// Game(Game &rhs);
					~Game(void);
	void 			loop(void);
	void 			getPlayerMove();
	pair<int,int>	getPlayerInput();
};
#endif
