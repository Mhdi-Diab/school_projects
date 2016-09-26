#include "Game.hpp"

int main() {
	bool replay = true;
	Game *game;

	while (replay) {
		game = new Game();
		replay = game->loop();
		delete game;
	}
	return (EXIT_SUCCESS);
}
