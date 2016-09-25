#include "Game.hpp"

t_player_color Game::currentPlayer = P_BLACK;

Game::Game(void) {
	isFinished = false;
	board = new Board();
	solver = new Solver();
	render = new Render();
	player[P_BLACK] = new Player(P_BLACK, P_AI);
	player[P_WHITE] = new Player(P_WHITE, P_PLAYER);
}

Game::~Game(void) {
	delete board;
	delete solver;
	delete render;
	delete player[P_BLACK];
	delete player[P_WHITE];
}

bool Game::playOneTurn(Event *event) {
	bool hasPlayed = false;

	if (player[currentPlayer]->type == P_AI) {
		hasPlayed = getAIMove();
	}
	else {
		hasPlayed = getPlayerMove(event);
	}
	if (hasPlayed) {
		currentPlayer = OPPONENT(currentPlayer);
		if (solver->isGameFinished(board)) {
			isFinished = true;
		}
	}
	return hasPlayed;
}

void	Game::loop(void) {
	bool			firstTurn;
	bool			hasPlayed;
	pair<int, int>	xy;
	Event			event;

	firstTurn = true;
	while (render->window.isOpen()) {
		if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
			render->window.close();
		}
		while (render->window.pollEvent(event)) {
			if (!isFinished) {
				hasPlayed = playOneTurn(&event);
			}
			if (event.type == Event::Closed)
				render->window.close();
		}
		if (hasPlayed) {
			render->window.clear();
			render->drawBoard(board);
			render->window.display();
			board->print();
			firstTurn = false;
		}
	}
}

bool	Game::getAIMove() {
	pair<int,int>	ret;
	clock_t start, end;

	start = clock();
	ret = solver->solve(board);
	board->placePiece(get<0>(ret), get<1>(ret), PIECE(currentPlayer));
	end = clock();
	cout << "Time required for execution: " << (double)(end - start)/CLOCKS_PER_SEC << " seconds." << endl;
	return true;
}

bool 	Game::getPlayerMove(Event *event) {
	int 			x;
	int 			y;
	static int count = 0;

	x = -1;
	y = -1;
	if (event->type == sf::Event::MouseButtonPressed) {
		if (event->mouseButton.button == sf::Mouse::Left) {
			x = (event->mouseButton.x - POSB) / POSA;
			y = (event->mouseButton.y - POSB) / POSA;
			cout << "IN" << ++count << endl;
			if (board->placePiece(y , x, PIECE(currentPlayer))) {
				return true;
			}
		}
	}
	return false;
}
