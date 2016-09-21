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
	pair<int, int> xy;

	while(1) {
		board->print();
		if (player[currentPlayer]->type == P_AI) {
			xy = solver->solve(board);
			cout << "MOVED -> x: " << get<0>(xy) << " y: " << get<1>(xy) << endl;
			board->placePiece(get<0>(xy), get<1>(xy), PIECE(currentPlayer));
		}
		else {
			getPlayerMove();
		}
		currentPlayer = OPPONENT(currentPlayer);
	}
}

void 	Game::getPlayerMove() {
	pair<int,int>	ret;

	ret = getPlayerInput();
	if (!board->placePiece(get<0>(ret), get<1>(ret), PIECE(currentPlayer))) {
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
