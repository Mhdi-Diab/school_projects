#include "Render.hpp"

Render::Render() {
	window.create(sf::VideoMode(WIN_X, WIN_Y, 32), "Gomoku");
	loadTextures();
}

Render::~Render(void) {
}

int Render::loadTextures() {


	if (!texture.loadFromFile("./img/board.png")) {
		cout << "Erreur durant le chargement de l'image" << endl;
		return EXIT_FAILURE;
	} else {
		board.setTexture(texture);
		board.setScale(0.7f, 0.7f);
	}
	return EXIT_SUCCESS;
}
