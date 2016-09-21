#ifndef BOARD_HPP
# define BOARD_HPP

# include <list>
# include <map>
# include <fstream>
# include <iostream>
# include <climits>
# include <string>
# include <vector>
# include <stdlib.h>
# include <regex>
# include <chrono>
# include "Render.hpp"
# include "Rectangle.hpp"
# include "UI.hpp"
# include "Global.hpp"
# include "Solver.hpp"
# include <pthread.h>

# define INV(X) (X) == (BLACK) ? (WHITE) : (BLACK)
// # define SHOW_DEBUG 1 

class Board : public Render {

public:
	/** ALGORITHME **/
	bool										lastMoveIsCapture;
	char										board[SIZE][SIZE];
	t_color										curTurn;
	int											score;
	const static t_orientation					orientation[8];
	const static t_color 						colorWB[2];
	std::pair<int,int>							lastMove;
	std::map<std::pair<t_color, t_threat>, int> threats;
	std::map<std::pair<int,int>, t_color> 		pieces;
	std::vector<Rectangle *>					rectangles;
	static std::map<std::pair<t_color, t_threat>, int>		threatNameAndValues;
	static std::map<t_orientation, std::pair<int, int> >	orientationInc;

	Board(Window *win);
	Board(Board &rhs);
	~Board(void);
	void setThreats();
	t_color getPiece(int x, int y);
	void placePiece(int x, int y);
	bool placePieceWithoutRender(int x, int y, t_color color);
	void removePiece(int x, int y);
	bool removePieceIfSurrounded(int x, int y);
	int	 countConnectedPieces(int x, int y, t_color color, t_orientation ori);
	bool hasXPiecesInRow(int x, int y, int nb);
	bool isGameFinished(int x, int y);
	std::vector <Board *> listAllMoves(t_color color);
	void createRectangles();
	bool hasAllEmptyAround(int x, int y);
	void removePieceInRectangles(int x, int y);
	int evaluateBoard(t_color color);
	void 	printBoard();
	void 	printThreats();
	/** RENDER **/
	static std::map<t_option, bool>	options;
	t_mode mode;
	std::map<t_color, t_data*>	data_;

	void InitBoard(Window *win);
	void setCurPiecePosition(int mouseX, int mouseY);
	void renderGame(void);
	void freeDynamicTexture(void);
	void lightChosenMode(int x, int y);
	void ChoseMode(void);
	void HandleClick(int x, int y);
	void HandleMove(int x, int y);
	void HandleInput(SDL_Event 	e);
	void InitTurn();

private:
	/** ALGORITHME **/
	void  	clearThreats();
	bool	isBrokenRow(int x, int y, t_color color, t_orientation ori);
	bool 	isRowEndingWithType(int x, int y, t_orientation ori, t_color color, t_color typeEnd);

	void 	divideThreats();
	void 	computeRectangles(int x, int y);
	std::vector<Rectangle *> getConnectedRectangles(int x, int y);
	void	mergeTwoRectangles(Rectangle *r1, Rectangle *r2);
	void	removeRectangle(Rectangle *r1);
	void	mergeRectangles(std::vector<Rectangle *> vec, int x, int y);
	void	renderRectangles(void);
	void 	mergeRectanglesInside(Rectangle *rect);
	bool 	isTwoTwo(int x, int y, t_color color, t_orientation ori);

	/** RENDER **/
	t_mode						temp_mode_;
	UI							*ui_;
	int 						curPieceMouseX_;
	int 						curPieceMouseY_;
	t_color						winner_;
	t_color						temp_color_;
	unsigned int				turn_;
	Solver						solver_;
	void 	loadPieceTextures(void);
	void 	renderCurPiece();
	void 	renderPieces();
	void 	RestartGame(void);
	void 	ClearBoard(void);
	void	ChoseColor(void);
	void	lightChosenColor(int x, int y);
	void	AutoRestartGame(void);

	static std::map<t_option, bool> init_options() {
		 std::map<t_option, bool> some_map;
		 some_map[DEBUG] = false;
		 some_map[EASY] = false;
		 return some_map;
	 }

	 static std::map<t_orientation, std::pair<int, int > > init_orientationInc() {
		 std::map<t_orientation, std::pair<int, int > > myMap;
		 myMap[NW] = std::make_pair(-1, -1);
		 myMap[N] = std::make_pair(0, -1);
		 myMap[NE] = std::make_pair(1, -1);
		 myMap[E] = std::make_pair(1, 0);
		 myMap[SE] = std::make_pair(1, 1);
		 myMap[S] = std::make_pair(0, 1);
		 myMap[SW] = std::make_pair(-1, 1);
		 myMap[W] = std::make_pair(-1, 0);
		 return myMap;
	 }

	 static std::map<std::pair<t_color, t_threat>, int> init_threatNameAndValues() {
		std::string line;
		std::ifstream whiteFile ("heuristics/WHITE_heuristics.txt");
		std::ifstream blackFile ("heuristics/BLACK_heuristics.txt");
		std::regex re("(\\w+): (-*\\d+|MAX_VALUE)");
		std::smatch match;
		std::map<std::string, t_threat> allThreats;
		std::map<std::pair<t_color, t_threat>, int> myMap;
		int nb;

		allThreats["FIVE"] = FIVE;
		allThreats["THREATENED_TWO"] = THREATENED_TWO;
		allThreats["CAPTURE"] = CAPTURE;
		allThreats["STRAIGHT_FOUR"] = STRAIGHT_FOUR;
		allThreats["BROKEN_FOUR"] = BROKEN_FOUR;
		allThreats["FOUR"] = FOUR;
		allThreats["THREE"] = THREE;
		allThreats["BROKEN_THREE"] = BROKEN_THREE;
		allThreats["UNTHREATENED_TWO"] = UNTHREATENED_TWO;
		allThreats["TWO_TWO"] = TWO_TWO;
		if (whiteFile.is_open()) {
			while (std::getline(whiteFile, line) ){
				  if (std::regex_search(line, match, re) && match.size() > 1) {
					  nb = std::string(match.str(2)) == "MAX_VALUE" ? MAX_VALUE : stoi(match.str(2));
					  myMap[std::make_pair(WHITE, allThreats[match.str(1)])] = nb;
				  }
			}
			whiteFile.close();
		}
		if (blackFile.is_open()) {
			while (std::getline(blackFile, line) ) {
				  if (std::regex_search(line, match, re) && match.size() > 1) {
					  nb = std::string(match.str(2)) == "MAX_VALUE" ? MAX_VALUE : stoi(match.str(2));
					  myMap[std::make_pair(BLACK, allThreats[match.str(1)])] = nb;
				  }
			}
			blackFile.close();
		}
 		return myMap;
 	 }
};
#endif
