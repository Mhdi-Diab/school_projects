#include "Render.hpp"

Render::Render() {
	window.create(sf::VideoMode(WIN_X, WIN_Y, 32), "Ma premiere fenetre SFML ! ");
}

Render::~Render(void) {
}
