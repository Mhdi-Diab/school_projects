#ifndef BOARD_HPP
# define BOARD_HPP

# include "Rectangle.hpp"
# include "Board.hpp"
# include "Player.hpp"
# include "Solver.hpp"

# define INV(X) (X) == (BLACK) ? (WHITE) : (BLACK)

class Board {

public:
	Board(void);
	// Board(Board &rhs);
	~Board(void);
};
#endif
