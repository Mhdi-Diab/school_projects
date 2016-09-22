#ifndef RENDER_HPP
# define RENDER_HPP

# define WIN_X 900
# define WIN_Y 900

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Render {

public:
	RenderWindow window;

	Render(void);
	~Render(void);
	void close();
};

#endif
