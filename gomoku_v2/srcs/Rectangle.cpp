#include "Rectangle.hpp"

Rectangle::Rectangle(int x, int y) {
	topLeftX = (x - RECT_PADDING >= 0 ? x - RECT_PADDING : (x - 1 >= 0 ? x - 1 : x));
	topLeftY = (y - RECT_PADDING >= 0 ? y - RECT_PADDING : (y - 1 >= 0 ? y - 1 : y));
	bottomRightX = (x + RECT_PADDING < BOARD_SIZE ? x + RECT_PADDING : (x + 1 < BOARD_SIZE ? x + 1 : x));
	bottomRightY = (y + RECT_PADDING < BOARD_SIZE ? y + RECT_PADDING : (y + 1 < BOARD_SIZE ? y + 1 : y));
	width = bottomRightX - topLeftX;
	height = bottomRightY - topLeftY;
	hasMoreThanOnePiece = false;
	color[0] = rand() % 256;
	color[1] = rand() % 256;
	color[2] = rand() % 256;
}

Rectangle::Rectangle(Rectangle &rhs) {
	topLeftX = rhs.getTopLeftX();
	topLeftY = rhs.getTopLeftY();
	bottomRightX = rhs.getBottomRightX();
	bottomRightY = rhs.getBottomRightY();
	width = bottomRightX - topLeftX;
	height = bottomRightY - topLeftY;
	hasMoreThanOnePiece = true;
}

Rectangle::~Rectangle(void) {
}

bool Rectangle::isInsideRectangle(int x, int y) {
	return (topLeftX <= x && topLeftY <= y &&
			bottomRightX >= x && bottomRightY >= y);
}

void Rectangle::bigResize(int minX, int minY, int maxX, int maxY) {
	topLeftY = minY;
	topLeftX = minX;
	bottomRightY = maxY;
	bottomRightX = maxX;
	width = maxX - minX;
	height = maxY - minY;
	hasMoreThanOnePiece = true;
}

void Rectangle::resize(int x, int y) {
	if (shouldDecreaseTopX(x))
		topLeftX = x - 2 >= 0 ? x - 2 : (x - 1 >= 0 ? x - 1 : x);
	if (shouldDecreaseTopY(y))
		topLeftY = y - 2 >= 0 ? y - 2 : (y - 1 >= 0 ? y - 1 : y);
	if (shouldIncreaseBottomX(x))
		bottomRightX = x + 2 < BOARD_SIZE ? x + 2 : (x + 1 < BOARD_SIZE ? x + 1 : x);
	if (shouldIncreaseBottomY(y))
		bottomRightY = y + 2 < BOARD_SIZE ? y + 2 : (y + 1 < BOARD_SIZE ? y + 1 : y);
	width = bottomRightX - topLeftX;
	height = bottomRightY - topLeftY;
	hasMoreThanOnePiece = true;
}

vector<Rectangle *> Rectangle::getConnectedRectangles(vector<Rectangle *> *rectangles, int x, int y) {
	vector<Rectangle *> vec;

	for (vector<Rectangle *>::iterator iter = rectangles->begin(); iter != rectangles->end(); iter++) {
		if ((*iter)->isInsideRectangle(x, y)) {
			vec.push_back(*iter);
		}
	}
	return (vec);
}

void	Rectangle::mergeRectangles(vector<Rectangle *> *rectangles, vector<Rectangle *> vec, int x, int y) {
	Rectangle *rect;
	int minX, minY, maxX, maxY;

	minX = BOARD_SIZE;
	minY = BOARD_SIZE;
	maxX = -1;
	maxY = -1;
	for (vector<Rectangle *>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
		if ((*iter)->getTopLeftX() < minX)
			minX = (*iter)->getTopLeftX();
		if ((*iter)->getTopLeftY() < minY)
			minY = (*iter)->getTopLeftY();
		if ((*iter)->getBottomRightY() > maxY)
			maxY = (*iter)->getBottomRightY();
		if ((*iter)->getBottomRightX() > maxX)
			maxX = (*iter)->getBottomRightX();
		removeRectangle(rectangles, *iter);
	}
	rect = new Rectangle(x, y);
	rect->bigResize(minX, minY, maxX, maxY);
	rectangles->push_back(rect);
	mergeRectanglesInside(rectangles, rect);
}

void 	Rectangle::mergeRectanglesInside(vector<Rectangle *> *rectangles, Rectangle *rect) {
	int TLrectX, TLrectY, BRrectX, BRrectY, TLiterX, TLiterY, BRiterX, BRiterY;

	TLrectX = rect->getTopLeftX();
	TLrectY = rect->getTopLeftY();
	BRrectX = rect->getBottomRightX();
	BRrectY = rect->getBottomRightY();
	for (vector<Rectangle *>::iterator iter = rectangles->begin(); iter != rectangles->end(); iter++) {
		if (*iter != rect) {
			TLiterX = (*iter)->getTopLeftX();
			TLiterY = (*iter)->getTopLeftY();
			BRiterX = (*iter)->getBottomRightX();
			BRiterY = (*iter)->getBottomRightY();
			if (TLrectX > TLiterX)
				rect->setTopLeftX(TLiterX);
			if (TLrectY > TLiterY)
				rect->setTopLeftY(TLiterY);
			if (BRrectX < BRiterX)
				rect->setBottomRightX(BRiterX);
			if (BRrectY < BRiterY)
				rect->setBottomRightY(BRiterY);
			removeRectangle(rectangles, *iter);
			mergeRectanglesInside(rectangles, rect);
			break ;
		}
	}
}

void 	Rectangle::removeRectangle(vector<Rectangle *> *rectangles, Rectangle *r1) {
	for (vector<Rectangle *>::iterator iter = rectangles->begin(); iter != rectangles->end(); iter++) {
		if (*iter == r1) {
			rectangles->erase(iter);
			break;
		}
	}
}

bool Rectangle::shouldIncreaseBottomX(int x) {
	return (x > bottomRightX - 2 && bottomRightX < BOARD_SIZE);
}

bool Rectangle::shouldIncreaseBottomY(int y) {
	return (y > bottomRightY - 2 && bottomRightY < BOARD_SIZE);
}

bool Rectangle::shouldDecreaseTopX(int x) {
	return (x < topLeftX + 2 && topLeftX != 0);
}

bool Rectangle::shouldDecreaseTopY(int y) {
	return (y < topLeftY + 2 && topLeftY != 0);
}

int Rectangle::getBottomRightX() const {
	return bottomRightX;
}

int Rectangle::getBottomRightY() const {
	return bottomRightY;
}

void Rectangle::setBottomRightY(int y) {
	bottomRightY = y;
	height = bottomRightY - topLeftY;
}

void Rectangle::setBottomRightX(int x) {
	bottomRightX = x;
	width = bottomRightX - topLeftX;
}

void Rectangle::setTopLeftX(int x) {
	topLeftX = x;
	width = bottomRightX - topLeftX;
}

void Rectangle::setTopLeftY(int y) {
	topLeftY = y;
	height = bottomRightY - topLeftY;
}

int Rectangle::getTopLeftX() const {
	return topLeftX;
}

int Rectangle::getTopLeftY() const {
	return topLeftY;
}

int Rectangle::getWidth() const {
	return width;
}

int Rectangle::getHeight() const {
	return height;
}
