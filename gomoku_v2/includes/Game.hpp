#ifndef GAME_HPP
# define GAME_HPP

# include "Rectangle.hpp"
# include "Board.hpp"
# include "Player.hpp"
# include "Solver.hpp"

# define INV(X) (X) == (BLACK) ? (WHITE) : (BLACK)

class Game {

public:
	Board	*board;
	Solver	*solver;
	Player	*p1;
	Player	*p2;

	Game(void);
	// Game(Game &rhs);
	~Game(void);
	void loop(void);
};
#endif
