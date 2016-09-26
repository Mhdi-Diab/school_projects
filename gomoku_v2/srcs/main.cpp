#include "Game.hpp"

int main() {
	Game *game = new Game();
	game->loop();
	delete game;
	return (EXIT_SUCCESS);
}
