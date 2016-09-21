#ifndef PLAYER_HPP
# define PLAYER_HPP

typedef enum 	e_player_color {
	P_BLACK = 0,
	P_WHITE
}				t_player_color;

class Player {

public:
	t_player_color color;

	Player(t_player_color color);
	// Player(Player &rhs);
	~Player(void);
};
#endif
