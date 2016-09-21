#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

# include <vector>
# include <map>
# include <iostream>
# include "Global.hpp"
# include "Window.hpp"
# include "Render.hpp"
# include <SDL2/SDL.h>

class Board;
class Rectangle : public Render {

private:
	int topLeftX;
	int topLeftY;
	int bottomRightX;
	int bottomRightY;
	int width;
	int height;

	SDL_Rect r;
	int col[4];

	void CreateTexture(void);
	int	 countConnectedPieces(int x, int y, t_color color, t_orientation ori);

public:
	bool hasMoreThanOnePiece;

	Rectangle(Window *win, int x, int y);
	Rectangle(Rectangle &rhs);
	~Rectangle(void);
	bool isInsideRectangle(int x, int y);
	void resize(int x, int y, t_color color);
	void bigResize(int minX, int minY, int width, int height);
	int getTopLeftX() const;
	int getTopLeftY() const;
	int getBottomRightX() const;
	int getBottomRightY() const;
	int getWidth() const;
	int getHeight() const;
	bool shouldIncreaseBottomX(int x);
	bool shouldIncreaseBottomY(int y);
	bool shouldDecreaseTopX(int x);
	bool shouldDecreaseTopY(int y);
	void RenderRectangle(void);
	bool hasPieceInside(Rectangle *rect, std::map<std::pair<int,int>, t_color> pieces);
	void setBottomRightY(int y);
	void setBottomRightX(int x);
	void setTopLeftX(int x);
	void setTopLeftY(int y);
};

#endif
