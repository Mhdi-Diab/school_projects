#include "Game.hpp"

t_player_color Game::currentPlayer = P_BLACK;

Game::Game(void) {
	isFinished = false;
	board = new Board();
	solver = new Solver();
	render = new Render();
	player[P_BLACK] = new Player(P_BLACK, P_PLAYER);
	player[P_WHITE] = new Player(P_WHITE, P_PLAYER);
	Game::currentPlayer = P_BLACK;
}

Game::~Game(void) {
	delete board;
	delete solver;
	delete render;
	delete player[P_BLACK];
	delete player[P_WHITE];
}

void Game::setNext(void) {
	currentPlayer = OPPONENT(currentPlayer);
	if (solver->isGameFinished(*board)) {
		isFinished = true;
	}
}

bool	Game::loop(void) {
	bool			hasPlayed;
	pair<int, int>	xy;

	renderGame();
	while (render->window.isOpen()) {
		hasPlayed = false;
		if (!isFinished && player[currentPlayer]->type == P_AI) {
			hasPlayed = getAIMove();
		}
		if (render->window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				render->window.close();
			} else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
				render->window.close();
			} else if (clickedReplay(&event)) {
				return true;
			}
			else if (!isFinished && player[currentPlayer]->type == P_PLAYER) {
				hasPlayed = getPlayerMove(&event);
			}
		}
		if (hasPlayed) {
			setNext();
			renderGame();
		}
	}
	return false;
}

void 	Game::renderGame(void) {
	render->window.clear();
	render->drawBoard(board);
	render->drawPanel(this);
	if (isFinished)
		render->displayFinish(this);
	render->window.display();
}

bool	Game::getAIMove(void) {
	pair<int,int> ret;
	clock_t start, end;

	start = clock();
	ret = solver->solve(*board);
	if (!board->placePiece(get<0>(ret), get<1>(ret), PIECE(currentPlayer)))
		getAIMove();
	end = clock();
	cout << "Time required for execution: " << (double)(end - start)/CLOCKS_PER_SEC << " seconds." << endl;
	return true;
}

bool	Game::clickedReplay(Event *event) {
	if (event->type == sf::Event::MouseButtonPressed) {
		if (event->mouseButton.button == sf::Mouse::Left) {
			if (event->mouseButton.x >= render->replay.getPosition().x &&
				event->mouseButton.x <= render->replay.getPosition().x +
				render->replay.getGlobalBounds().width &&
				event->mouseButton.y >= render->replay.getPosition().y &&
				event->mouseButton.x <= render->replay.getPosition().y +
				render->replay.getGlobalBounds().height) {
					return true;
				}
		}
	}
	return false;
}

bool 	Game::getPlayerMove(Event *event) {
	int x = -1, y = -1;

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
