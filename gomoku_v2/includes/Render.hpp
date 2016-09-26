#ifndef RENDER_HPP
# define RENDER_HPP

# define WIN_X 1120
# define WIN_Y 1220
# define POSA 58
# define POSB 9

#include <iostream>
#include "Board.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Board;
class Render {

public:
	RenderWindow window;
	Texture 	boardTexture;
	Texture 	whitePieceTexture;
	Texture 	blackPieceTexture;

	Font		font;

	Sprite		board;
	Sprite		blackPiece;
	Sprite		whitePiece;

	Render(void);
	~Render(void);
	int loadTextures();
	void mouseMove(Board *board);
	void drawBoard(Board *board);
	void drawPanel(t_player_color currentPlayer);
};

#endif
