#include "Game.hpp"

Game::Game(void) {
	this->board = new Board();
	this->solver = new Solver();
	this->p1 = new Player();
	this->p2 = new Player();
}

Game::~Game(void) {
}

void	Game::loop(void) {
	while(1) {

	}
}
