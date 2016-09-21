#include "Rectangle.hpp"

Rectangle::Rectangle(int x, int y) {
	this->topLeftX = (x - 2 >= 0 ? x - 2 : (x - 1 >= 0 ? x - 1 : x));
	this->topLeftY = (y - 2 >= 0 ? y - 2 : (y - 1 >= 0 ? y - 1 : y));
	this->bottomRightX = (x + 2 < BOARD_SIZE ? x + 2 : (x + 1 < BOARD_SIZE ? x + 1 : x));
	this->bottomRightY = (y + 2 < BOARD_SIZE ? y + 2 : (y + 1 < BOARD_SIZE ? y + 1 : y));
	this->width = this->bottomRightX - this->topLeftX;
	this->height = this->bottomRightY - this->topLeftY;
	this->hasMoreThanOnePiece = false;
}

Rectangle::Rectangle(Rectangle &rhs) {
	this->topLeftX = rhs.getTopLeftX();
	this->topLeftY = rhs.getTopLeftY();
	this->bottomRightX = rhs.getBottomRightX();
	this->bottomRightY = rhs.getBottomRightY();
	this->width = this->bottomRightX - this->topLeftX;
	this->height = this->bottomRightY - this->topLeftY;
	this->hasMoreThanOnePiece = true;
}

Rectangle::~Rectangle(void) {
}

bool Rectangle::isInsideRectangle(int x, int y) {
	return (this->topLeftX <= x && this->topLeftY <= y &&
			this->bottomRightX >= x && this->bottomRightY >= y);
}

void Rectangle::bigResize(int minX, int minY, int maxX, int maxY) {
	this->topLeftY = minY;
	this->topLeftX = minX;
	this->bottomRightY = maxY;
	this->bottomRightX = maxX;
	this->width = maxX - minX;
	this->height = maxY - minY;
	this->hasMoreThanOnePiece = true;
}

void Rectangle::resize(int x, int y) {
	if (this->shouldDecreaseTopX(x))
		this->topLeftX = x - 2 >= 0 ? x - 2 : (x - 1 >= 0 ? x - 1 : x);
	if (this->shouldDecreaseTopY(y))
		this->topLeftY = y - 2 >= 0 ? y - 2 : (y - 1 >= 0 ? y - 1 : y);
	if (this->shouldIncreaseBottomX(x))
		this->bottomRightX = x + 2 < BOARD_SIZE ? x + 2 : (x + 1 < BOARD_SIZE ? x + 1 : x);
	if (this->shouldIncreaseBottomY(y))
		this->bottomRightY = y + 2 < BOARD_SIZE ? y + 2 : (y + 1 < BOARD_SIZE ? y + 1 : y);
	this->width = this->bottomRightX - this->topLeftX;
	this->height = this->bottomRightY - this->topLeftY;
	this->hasMoreThanOnePiece = true;
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
		if (*iter != rect && (*iter)->hasPieceInside(rect)) {
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

bool Rectangle::hasPieceInside(Rectangle *rect) {
	for (int y = this->topLeftY; y <= this->bottomRightY; y++) {
		for (int x = this->topLeftX; x <= this->bottomRightX; x++) {
			// if (pieces.count(std::make_pair(x,y)) && pieces[std::make_pair(x,y)] != EMPTY && rect->isInsideRectangle(x, y)) {
				// return true;
			// }
		}
	}
	return false;
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
	return (x > this->bottomRightX - 2 && this->bottomRightX < BOARD_SIZE);
}

bool Rectangle::shouldIncreaseBottomY(int y) {
	return (y > this->bottomRightY - 2 && this->bottomRightY < BOARD_SIZE);
}

bool Rectangle::shouldDecreaseTopX(int x) {
	return (x < this->topLeftX + 2 && this->topLeftX != 0);
}

bool Rectangle::shouldDecreaseTopY(int y) {
	return (y < this->topLeftY + 2 && this->topLeftY != 0);
}

int Rectangle::getBottomRightX() const {
	return this->bottomRightX;
}

int Rectangle::getBottomRightY() const {
	return this->bottomRightY;
}

void Rectangle::setBottomRightY(int y) {
	this->bottomRightY = y;
	this->height = this->bottomRightY - this->topLeftY;
}

void Rectangle::setBottomRightX(int x) {
	this->bottomRightX = x;
	this->width = this->bottomRightX - this->topLeftX;
}

void Rectangle::setTopLeftX(int x) {
	this->topLeftX = x;
	this->width = this->bottomRightX - this->topLeftX;
}

void Rectangle::setTopLeftY(int y) {
	this->topLeftY = y;
	this->height = this->bottomRightY - this->topLeftY;
}

int Rectangle::getTopLeftX() const {
	return this->topLeftX;
}

int Rectangle::getTopLeftY() const {
	return this->topLeftY;
}

int Rectangle::getWidth() const {
	return this->width;
}

int Rectangle::getHeight() const {
	return this->height;
}
