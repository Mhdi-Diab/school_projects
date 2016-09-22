#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

# include "Board.hpp"
# include <vector>
# include <map>
# include <iostream>
using namespace std;

#define RECT_PADDING 2

class Rectangle {

private:
	int topLeftX;
	int topLeftY;
	int bottomRightX;
	int bottomRightY;
	int width;
	int height;

public:
	int color[3];
	bool hasMoreThanOnePiece;

	Rectangle(int x, int y);
	Rectangle(Rectangle &rhs);
	~Rectangle(void);

	vector<Rectangle *> getConnectedRectangles(vector<Rectangle *> *rectangles, int x, int y);
	void mergeRectangles(vector<Rectangle *> *rectangles, vector<Rectangle *> vec, int x, int y);
	void mergeRectanglesInside(vector<Rectangle *> *rectangles, Rectangle *rect);
	void removeRectangle(vector<Rectangle *> *rectangles, Rectangle *r1);
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
