#include "Global.hpp"
#include "Board.hpp"
#include "Window.hpp"

/* BONUS
* Affichage des rectangles
* IA VS IA
* Aide de l'IA
* Restart
* Debug print
*/

int main(int ac, char **av) {
	(void)ac;
	(void)av;
	int	programShouldQuit = false;
	std::string temp;

	Window *win = new Window();
	Board *board = new Board(win);
	if (win->Init() == 0)
	{
		srand (time(NULL));
		if (ac > 1){
			for(int i = 0; i < ac; i++){
				temp = av[i];
				if (temp == "-l"){
					Board::options[DEBUG] = true;
				}
				else if (temp == "-e"){
					Board::options[EASY] = true;
				}
				else if (temp == "-a"){
					Board::options[INFINITE] = true;
				}
			}
		}
		board->InitBoard(win);
		while (!programShouldQuit){
			SDL_RenderClear(win->getRenderer());
			if (board->mode == MANVSIA || board->mode == IAVSIA)
				board->InitTurn();
			board->renderGame();
			SDL_RenderPresent(win->getRenderer());
			board->freeDynamicTexture();
			programShouldQuit = win->handleEvents(board);
		}
		win->Clean();
	}
	return 0;
}
