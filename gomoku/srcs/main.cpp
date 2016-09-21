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

static void 	handleArguments(char **av) {
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

int main(int ac, char **av) {
	(void)ac;
	(void)av;
	int	programShouldQuit = false;
	std::string temp;

	Board *board = new Board();
	Solver *solver = new Solver();
	srand(time(NULL));
	// if (ac > 1){
	// 	handleArguments(av);
	// }
	board->InitBoard();
	while (1) {
		if (board->data_[board->curTurn]->type == IA) {
			board->placeIAPiece();
			solver->solve(board);
		}
	}
	return (0);
}
