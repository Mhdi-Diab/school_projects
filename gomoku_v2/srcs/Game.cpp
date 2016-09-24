#include "Game.hpp"

Game::Game(void) {
	isFinished = false;
	board = new Board();
	solver = new Solver();
	render = new Render();
	currentPlayer = P_BLACK;
	player[P_BLACK] = new Player(P_BLACK, P_PLAYER);
	player[P_WHITE] = new Player(P_WHITE, P_PLAYER);
}

Game::~Game(void) {
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
		board->removeCaptures();
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
		if (!isFinished)
			hasPlayed = playOneTurn(&event);
		while (render->window.pollEvent(event)) {
			if (event.type == Event::Closed)
				render->window.close();
		}
		if (hasPlayed || firstTurn) {
			render->window.clear();
			render->drawBoard(board);
			render->window.display();
		}
		firstTurn = false;
	}
}

bool	Game::getAIMove() {
	pair<int,int>	ret;
	clock_t start, end;

	start = clock();
	ret = solver->solve(board, currentPlayer);
	board->placePiece(get<0>(ret), get<1>(ret), PIECE(currentPlayer));
	end = clock();
	cout << "Time required for execution: " << (double)(end-start)/CLOCKS_PER_SEC << " seconds." << endl;
	return true;
}

bool 	Game::getPlayerMove(Event *event) {
	int 			x;
	int 			y;

	x = -1;
	y = -1;
	if (event->type == sf::Event::MouseButtonPressed) {
		if (event->mouseButton.button == sf::Mouse::Left) {
			x = (event->mouseButton.x - POSB) / POSA;
			y = (event->mouseButton.y - POSB) / POSA;
			if (board->placePiece(y , x, PIECE(currentPlayer))) {
				return true;
			}
		}
	}
	return false;
}
