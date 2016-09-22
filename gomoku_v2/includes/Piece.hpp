#ifndef PIECE_HPP
# define PIECE_HPP

typedef enum 	e_piece {
	BLACK = 'x',
	WHITE = 'o',
	EMPTY = '.'
}				t_piece;

class Piece {
public:
	int 	x;
	int 	y;
	t_piece piece;

	Piece(int x, int y, t_piece piece);
	~Piece(void);
};
#endif
