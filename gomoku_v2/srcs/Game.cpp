#include "Game.hpp"

Game::Game(void) {
	board = new Board();
	solver = new Solver();
	render = new Render();
	currentPlayer = P_BLACK;
	player[P_BLACK] = new Player(P_BLACK, P_PLAYER);
	player[P_WHITE] = new Player(P_WHITE, P_AI);

}

Game::~Game(void) {
}

void Game::playOneTurn() {
	if (player[currentPlayer]->type == P_AI) {
		getAIMove();
	}
	else {
		getPlayerMove();
	}
	board->print();
	if (solver->isGameFinished(board)) {
		cout << "GAME FINISHED" << endl;
	}
	currentPlayer = OPPONENT(currentPlayer);
}

void	Game::loop(void) {
	pair<int, int> xy;

	while (render->window.isOpen())
	{
		Event event;
		while (render->window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				render->window.close();
		}
		// playOneTurn();
		render->window.clear();
		render->window.draw(render->board);
		render->window.display();
	}
}

void	Game::getAIMove() {
	pair<int,int>	ret;

	ret = solver->solve(board);
	cout << "MOVED -> x: " << get<0>(ret) << " y: " << get<1>(ret) << endl;
	board->placePiece(get<0>(ret), get<1>(ret), PIECE(currentPlayer));
}

void 	Game::getPlayerMove() {
	string 			x;
	string 			y;

	getline(cin, x);
	getline(cin, y);
	if (!board->placePiece(atoi(x.c_str()), atoi(y.c_str()), PIECE(currentPlayer))) {
		getPlayerMove();
	}
}
