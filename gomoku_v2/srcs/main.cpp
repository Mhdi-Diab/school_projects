#include "Game.hpp"

int main() {

	Game *game = new Game();
	game->board->print();
	game->loop();
	return (0);
}
