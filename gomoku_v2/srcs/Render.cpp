#include "Render.hpp"

Render::Render() {
	window.create(sf::VideoMode(WIN_X, WIN_Y, 32), "Gomoku");
	loadTextures();
}

Render::~Render(void) {
}

void Render::drawBoard(Board *board) {
	window.draw(this->board);
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board->getPiece(j, i) == WHITE) {
				whitePiece.setPosition(i * POSA + POSB, j * POSA + POSB);
				window.draw(whitePiece);
			} else if (board->getPiece(j, i) == BLACK) {
				blackPiece.setPosition(i * POSA + POSB, j * POSA + POSB);
				window.draw(blackPiece);
			}
		}
	}
	if (true) {
		drawRectangles(board);
	}
}

void Render::drawRectangles(Board *board) {
	int sizeX, sizeY;
	RectangleShape rectangle;

	for (vector<Rectangle *>::iterator iter = board->rectangles->begin(); iter != board->rectangles->end(); iter++) {
		sizeX = (*iter)->getBottomRightX() - (*iter)->getTopLeftX();
		sizeY = (*iter)->getBottomRightY() - (*iter)->getTopLeftY();
		rectangle.setSize(sf::Vector2f(sizeY * POSA, sizeX * POSA));
		rectangle.setPosition((*iter)->getTopLeftY() * POSA + 4 * POSB, (*iter)->getTopLeftX() * POSA + 4 * POSB);
		rectangle.setFillColor(Color((*iter)->color[0], (*iter)->color[1], (*iter)->color[2], 100));
		window.draw(rectangle);
	}
}

int Render::loadTextures() {
	whitePieceTexture.setSmooth(true);
	blackPieceTexture.setSmooth(true);
	if (!boardTexture.loadFromFile("./img/board.png")) {
		cout << "Erreur durant le chargement de l'image board" << endl;
		return EXIT_FAILURE;
	} else {
		board.setTexture(boardTexture);
		board.setScale(0.7f, 0.7f);
	}
	if (!whitePieceTexture.loadFromFile("./img/white.png")) {
		cout << "Erreur durant le chargement de l'image pion blanc" << endl;
		return EXIT_FAILURE;
	} else {
		whitePiece.setTexture(whitePieceTexture);
		whitePiece.setScale(0.9f, 0.9f);
	}
	if (!blackPieceTexture.loadFromFile("./img/black.png")) {
		cout << "Erreur durant le chargement de l'image pion noir" << endl;
		return EXIT_FAILURE;
	} else {
		blackPiece.setTexture(blackPieceTexture);
		blackPiece.setScale(0.9f, 0.9f);
	}
	return EXIT_SUCCESS;
}
