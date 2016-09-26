#include "Render.hpp"
#include "Game.hpp"

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
			if (board->getPiece(j, i) == WHITE_PIECE) {
				if (j == get<0>(board->lastMove) && i == get<1>(board->lastMove))
					whitePiece.setColor(sf::Color(255, 200, 200));
				whitePiece.setPosition(i * POSA + POSB, j * POSA + POSB);
				window.draw(whitePiece);
				whitePiece.setColor(sf::Color(255, 255, 255));
			} else if (board->getPiece(j, i) == BLACK_PIECE) {
				if (j == get<0>(board->lastMove) && i == get<1>(board->lastMove))
					blackPiece.setColor(sf::Color(255, 200, 200));
				blackPiece.setPosition(i * POSA + POSB, j * POSA + POSB);
				window.draw(blackPiece);
				blackPiece.setColor(sf::Color(255, 255, 255));
			}
		}
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
