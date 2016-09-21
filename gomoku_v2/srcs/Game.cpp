#include "Game.hpp"

Game::Game(void) {
	board = new Board();
	solver = new Solver();
	currentPlayer = P_BLACK;
	player[P_BLACK] = new Player(P_BLACK, P_PLAYER);
	player[P_WHITE] = new Player(P_WHITE, P_AI);
}

Game::~Game(void) {
}

void	Game::loop(void) {
	while(1) {
		board->print();
		if (player[currentPlayer]->type == P_AI) {
			solver->solve(board);
		}
		else {
			getPlayerMove();
		}
		this->currentPlayer = OPPONENT(this->currentPlayer);
	}
}

void 	Game::getPlayerMove() {
	pair<int,int>	ret;
	t_piece			piece;

	piece = currentPlayer == P_BLACK ? BLACK : WHITE;
	ret = getPlayerInput();
	if (!board->placePiece(get<0>(ret), get<1>(ret), piece)) {
		getPlayerMove();
	}
}

pair<int,int> Game::getPlayerInput() {
	string 			x;
	string 			y;

	getline(cin, x);
	getline(cin, y);
	return make_pair(atoi(x.c_str()), atoi(y.c_str()));
}
