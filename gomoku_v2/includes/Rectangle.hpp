#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

# include "Board.hpp"
# include <vector>
# include <map>
# include <iostream>

class Rectangle {

private:
	int topLeftX;
	int topLeftY;
	int bottomRightX;
	int bottomRightY;
	int width;
	int height;

public:
	bool hasMoreThanOnePiece;

	Rectangle(int x, int y);
	Rectangle(Rectangle &rhs);
	~Rectangle(void);

	bool isInsideRectangle(int x, int y);
	void resize(int x, int y);
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
	void setBottomRightY(int y);
	void setBottomRightX(int x);
	void setTopLeftX(int x);
	void setTopLeftY(int y);
};

#endif
