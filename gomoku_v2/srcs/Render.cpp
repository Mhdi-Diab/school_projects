#include "Render.hpp"
#include "Game.hpp"

Render::Render() {
	window.create(VideoMode(WIN_X, WIN_Y, 32), "Gomoku", Style::Close);
	loadTextures();
}

Render::~Render(void) {
}

void Render::drawBoard(Board *board) {
	window.draw(this->board);
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board->getPiece(j, i) == WHITE_PIECE) {
				if (j == get<0>(board->lastMove) && i == get<1>(board->lastMove))
					whitePiece.setColor(Color(255, 200, 200));
				whitePiece.setPosition(i * POSA + POSB, j * POSA + POSB);
				window.draw(whitePiece);
				whitePiece.setColor(Color(255, 255, 255));
			} else if (board->getPiece(j, i) == BLACK_PIECE) {
				if (j == get<0>(board->lastMove) && i == get<1>(board->lastMove))
					blackPiece.setColor(Color(255, 200, 200));
				blackPiece.setPosition(i * POSA + POSB, j * POSA + POSB);
				window.draw(blackPiece);
				blackPiece.setColor(Color(255, 255, 255));
			}
		}
	}
}

void Render::drawPanel(t_player_color currentPlayer) {
	RectangleShape rectangle(Vector2f(WIN_X, 100));

	rectangle.setOutlineColor(Color(205, 133, 63));
	rectangle.setOutlineThickness(10);
	rectangle.setFillColor(Color(245,222,179));
	rectangle.setPosition(0, WIN_Y - 100);
	window.draw(rectangle);

	if (currentPlayer == P_BLACK) {
		blackPiece.setPosition(100, WIN_Y - 80);
		window.draw(blackPiece);
	} else {
		whitePiece.setPosition(100, WIN_Y - 80);
		window.draw(whitePiece);
	}
}

int Render::loadTextures() {
	whitePieceTexture.setSmooth(true);
	blackPieceTexture.setSmooth(true);
	if (!boardTexture.loadFromFile("./img/board.png")) {
		cerr << "Error while loading board image" << endl;
		return EXIT_FAILURE;
	} else {
		board.setTexture(boardTexture);
		board.setScale(0.7f, 0.7f);
	}
	if (!whitePieceTexture.loadFromFile("./img/white.png")) {
		cerr << "Error while loading white piece image" << endl;
		return EXIT_FAILURE;
	} else {
		whitePiece.setTexture(whitePieceTexture);
		whitePiece.setScale(0.9f, 0.9f);
	}
	if (!blackPieceTexture.loadFromFile("./img/black.png")) {
		cerr << "Error while loading black piece image" << endl;
		return EXIT_FAILURE;
	} else {
		blackPiece.setTexture(blackPieceTexture);
		blackPiece.setScale(0.9f, 0.9f);
	}
	if (!font.loadFromFile("./img/arial.ttf")) {
		cerr << "Error loading font" << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
