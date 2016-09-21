#include "Game.hpp"

Game::Game(void) {
	this->board = new Board();
	this->solver = new Solver();
	this->currentPlayer = P_BLACK;
	this->player[P_BLACK] = new Player(P_BLACK);
	this->player[P_WHITE] = new Player(P_WHITE);
}

Game::~Game(void) {
}

void	Game::loop(void) {
	while(1) {
	}
}
