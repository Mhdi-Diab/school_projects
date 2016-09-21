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
