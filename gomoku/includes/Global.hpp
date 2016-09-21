#ifndef GLOBAL_HPP
# define GLOBAL_HPP

# include <chrono>

typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds milliseconds;

# define SIZE 19
# define NB_GRIDS 324
# define DEPTH_LIMIT 5

typedef enum 	e_color {
	BLACK = 'x',
	WHITE = 'o',
	EMPTY = '.'
}				t_color;

typedef enum 	e_threat {
	FIVE,
	FOUR,
	STRAIGHT_FOUR,
	BROKEN_FOUR,
	THREE,
	BROKEN_THREE,
	UNTHREATENED_TWO,
	THREATENED_TWO,
	TWO_TWO,
	CAPTURE
}				t_threat;

typedef enum 	s_orientation {
	N = 0,
	S = 1,
	E = 2,
	W = 3,
	NW = 4,
	NE = 5,
	SW = 6,
	SE = 7
}				t_orientation;

typedef enum	e_type {
	MAN,
	IA
}				t_type;

typedef struct	s_data {
	t_type				type;
	int					nbCaptures;
	Clock::time_point	lastStartTime;
	milliseconds		lastTurnTime, totalTime;
}				t_data;

typedef enum	e_mode{
	NOMOD,
	CHOSE_COLOR,
	MANVSMAN,
	MANVSIA,
	IAVSIA,
	END
}				t_mode;

typedef enum	e_option{
	DEBUG,
	EASY,
	INFINITE
}				t_option;

#endif
