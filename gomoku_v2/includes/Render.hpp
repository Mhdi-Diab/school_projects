#ifndef RENDER_HPP
# define RENDER_HPP

# define WIN_X 1120
# define WIN_Y 1120

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Render {

public:
	RenderWindow window;
	Texture 	texture;
	Sprite		board;
	Sprite		blackPiece;
	Sprite		whitePiece;

	Render(void);
	~Render(void);
	int loadTextures();
};

#endif
