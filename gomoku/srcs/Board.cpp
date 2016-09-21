#include "Board.hpp"
#include <math.h>
/************************************************************************/
/************************      CONSTRUCTORS		*************************/
/************************************************************************/

const t_color Board::colorWB[2] = {WHITE, BLACK};
const t_orientation Board::orientation[8] = {NW, N, NE, E, SE, S, SW, W};

std::map<t_orientation, std::pair<int, int> >Board::orientationInc = init_orientationInc();
std::map<std::pair<t_color, t_threat>, int>Board::threatNameAndValues = init_threatNameAndValues();
std::map<t_option, bool>Board::options = init_options();

Board::Board(Window *win) : Render(win) {
	this->turn_ = 1;
	this->winner_ = EMPTY;
	this->curPieceMouseY_ = -1;
	this->curPieceMouseX_ = -1;
	this->curTurn = BLACK;
	this->data_[WHITE] = new t_data();
	this->data_[WHITE]->nbCaptures = 0;
	this->data_[WHITE]->totalTime = milliseconds(0);
	this->data_[BLACK] = new t_data();
	this->data_[BLACK]->nbCaptures = 0;
	this->data_[BLACK]->lastStartTime = Clock::now();
	this->data_[BLACK]->totalTime = milliseconds(0);
	this->mode = NOMOD;
	this->temp_mode_ = NOMOD;
	this->ClearBoard();
}

Board::Board(Board &rhs) : Render(rhs.getWindow()) {
	int x, y;

	memcpy(this->board, rhs.board, sizeof(char[SIZE][SIZE]));
	for (std::vector<Rectangle *>::iterator iter = rhs.rectangles.begin(); iter != rhs.rectangles.end(); iter++) {
		this->rectangles.push_back(new Rectangle(**iter));
	}
	for (std::map<std::pair<int, int>, t_color>::iterator iter = rhs.pieces.begin(); iter != rhs.pieces.end(); iter++) {
		x = std::get<0>(iter->first);
		y = std::get<1>(iter->first);
		this->pieces[std::make_pair(x,y)] = iter->second;
	}
	this->lastMove = rhs.lastMove;
	this->curTurn = rhs.curTurn;
	for (int i = 0; i < 2; i++) {
		this->data_[Board::colorWB[i]] = new t_data();
		this->data_[Board::colorWB[i]]->nbCaptures = rhs.data_[Board::colorWB[i]]->nbCaptures;
		this->data_[Board::colorWB[i]]->lastStartTime = rhs.data_[Board::colorWB[i]]->lastStartTime;
		this->data_[Board::colorWB[i]]->totalTime = rhs.data_[Board::colorWB[i]]->totalTime;
	}
}

Board::~Board(void) {
}

/************************************************************************/
/************************      GAMEPLAY			*************************/
/************************************************************************/

void Board::placePiece(int mouseX, int mouseY) {
	int x, y;

	y = (mouseY - PADDING_Y + 35) / 70;
	x = (mouseX - PADDING_X + 35) / 70;
	if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && this->board[y][x] == EMPTY)
	{
		if (!this->placePieceWithoutRender(x, y, this->curTurn))
			return ;
		this->data_[this->curTurn]->lastTurnTime = std::chrono::duration_cast<milliseconds>(Clock::now() - this->data_[this->curTurn]->lastStartTime);
		this->data_[this->curTurn]->totalTime += this->data_[this->curTurn]->lastTurnTime;
		if (this->isGameFinished(x, y) == true) {
			if (this->options[INFINITE] == true)
			{
				this->AutoRestartGame();
				return;
			}
			this->mode = END;
			this->winner_ = this->curTurn;
			return ;
		}
		if (this->curTurn == BLACK)
			this->turn_++;
		this->curTurn = INV(this->curTurn);
		this->data_[this->curTurn]->lastStartTime = Clock::now();
	}
	#ifdef SHOW_DEBUG
	this->printBoard();
	this->printThreats();
	#endif
}

bool Board::placePieceWithoutRender(int x, int y, t_color color) {
	int prevThree, prevBrokenThree;

	prevThree = this->threats[std::make_pair(color, THREE)];
	prevBrokenThree = this->threats[std::make_pair(color, BROKEN_THREE)];
	this->lastMove = std::make_pair(x,y);
	this->board[y][x] = color;
	this->pieces[std::make_pair(x,y)] = color;
	this->setThreats();
	if (this->threats[std::make_pair(color, THREE)] - prevThree + this->threats[std::make_pair(color, BROKEN_THREE)] - prevBrokenThree >= 2) {
		this->removePiece(x, y);
		this->threats[std::make_pair(color, THREE)]  = prevThree;
		this->threats[std::make_pair(color, BROKEN_THREE)]  = prevBrokenThree;
		return false;
	}
	if ((this->lastMoveIsCapture = this->removePieceIfSurrounded(x, y)))
		this->data_[color]->nbCaptures += 1;
	this->computeRectangles(x, y);
	return true;
}

void Board::removePiece(int x, int y) {
	std::map<std::pair<int,int>, t_color>::iterator it;

	this->board[y][x] = EMPTY;
	this->pieces[std::make_pair(x,y)] = EMPTY;
	it = this->pieces.find(std::make_pair(x,y));
	this->pieces.erase(it);
}

bool Board::removePieceIfSurrounded(int x, int y) {
	std::pair<int, int> inc;
	t_color color = this->getPiece(x, y);
	bool flag = false;

	for (int i = 0; i < 8; i ++) {
		inc = Board::orientationInc[Board::orientation[i]];
		if (countConnectedPieces(x + std::get<0>(inc), y + std::get<1>(inc), INV(color), Board::orientation[i]) == 2
			&& x + std::get<0>(inc) * 3 >= 0 && y + std::get<1>(inc) * 3 >= 0
			&& x + std::get<0>(inc) * 3 < SIZE && y + std::get<1>(inc) * 3 < SIZE
			&& this->board[y + std::get<1>(inc) * 3][x + std::get<0>(inc) * 3] == color) {
				this->removePiece(x + std::get<0>(inc), y + std::get<1>(inc));
				this->removePiece(x + std::get<0>(inc) * 2, y + std::get<1>(inc) * 2);
				flag = true;
			}
	}
	return flag;
}

bool sortBoardsByScore (Board *a, Board *b) {
	return a->score > b->score;
}

std::vector <Board *> Board::listAllMoves(t_color color) {
	std::vector <Board *> vec;
	std::map<std::pair<int,int>, bool> piece;
	int TLY, TLX, BRX, BRY;

	for (std::vector<Rectangle *>::iterator iter = this->rectangles.begin(); iter != this->rectangles.end(); iter++) {
		if (!(*iter)->hasMoreThanOnePiece && vec.size() != 0)
			continue ;
		TLX = (*iter)->getTopLeftX();
		TLY = (*iter)->getTopLeftY();
		BRX = (*iter)->getBottomRightX();
		BRY = (*iter)->getBottomRightY();
		for (int y = TLY; y <= BRY; y++) {
			for (int x = TLX; x <= BRX; x++) {
				if (this->board[y][x] == EMPTY && !piece.count(std::make_pair(x,y)) && !this->hasAllEmptyAround(x, y)) {
					Board *board = new Board(*this);
					if (board->placePieceWithoutRender(x, y, color)) {
						piece[std::make_pair(x,y)] = true;
						board->score = board->evaluateBoard(color) - board->evaluateBoard(INV(color));
						vec.push_back(board);
						board->curTurn = INV(color);
					}
					else
						delete board;
				}
			}
		}
	}
	std::sort (vec.begin(), vec.end(), sortBoardsByScore);
	return vec;
}

t_color Board::getPiece(int x, int y) {
	return (t_color)this->board[y][x];
}

/************************************************************************/
/************************      HEURISTICS		*************************/
/************************************************************************/

void Board::setThreats() {
	t_color enemyColor;
	t_orientation orientation[4][2] = {{NW, SE}, {NE, SW}, {N, S}, {W, E}};
	int nbThreats[4];
	bool emptyEnding;
	bool emptyEnding2;
	int x, y;
	t_color currentColor;

	this->clearThreats();
	for (std::map<std::pair<int, int>, t_color>::iterator iter = this->pieces.begin(); iter != this->pieces.end(); iter++) {
		currentColor = iter->second;
		if (currentColor == EMPTY) {
			continue ;
		}
		x = std::get<0>(iter->first);
		y = std::get<1>(iter->first);
		enemyColor = INV(currentColor);
		for (int i = 0; i < 4; i++) {
			nbThreats[i] = this->countConnectedPieces(x, y, currentColor, orientation[i][0]) + this->countConnectedPieces(x, y, currentColor, orientation[i][1]) - 1;
			emptyEnding = this->isRowEndingWithType(x, y, orientation[i][0], currentColor, EMPTY);
			emptyEnding2 = this->isRowEndingWithType(x, y, orientation[i][1], currentColor, EMPTY);

			this->threats[std::make_pair(currentColor, CAPTURE)] = this->lastMoveIsCapture ? 1 : 0;
			switch (nbThreats[i]) {
				case 9:
				case 8:
				case 7:
				case 6:
				case 5:
					this->threats[std::make_pair(currentColor, FIVE)]++;
					break ;
				case 4:
					if (emptyEnding && emptyEnding2)
						this->threats[std::make_pair(currentColor, STRAIGHT_FOUR)]++;
					else if (emptyEnding || emptyEnding2)
						this->threats[std::make_pair(currentColor, FOUR)]++;
					break ;
				case 3:
					if (this->isBrokenRow(x, y, currentColor, orientation[i][0]) || this->isBrokenRow(x, y, currentColor, orientation[i][1])) {
						this->threats[std::make_pair(currentColor, BROKEN_FOUR)]++;
					}
					else if (emptyEnding && emptyEnding2)
						this->threats[std::make_pair(currentColor, THREE)]++;
					break ;
				case 2:
					if (this->isTwoTwo(x, y, currentColor, orientation[i][0]) || this->isTwoTwo(x, y, currentColor, orientation[i][1]))
					{
						this->threats[std::make_pair(currentColor, TWO_TWO)]++;
					}
					else if (this->isRowEndingWithType(x, y, orientation[i][0], currentColor, enemyColor)
						|| this->isRowEndingWithType(x, y, orientation[i][1], currentColor, enemyColor))
						this->threats[std::make_pair(currentColor, THREATENED_TWO)]++;
					else {
						if ((this->isBrokenRow(x, y, currentColor, orientation[i][0]) || this->isBrokenRow(x, y, currentColor, orientation[i][1]))
							&& emptyEnding && emptyEnding)
							this->threats[std::make_pair(currentColor, BROKEN_THREE)]++;
						else
							this->threats[std::make_pair(currentColor, UNTHREATENED_TWO)]++;
						}
					break ;
			}
		}
	}
	this->divideThreats();
}

void Board::divideThreats() {
	t_color color[2] = {WHITE, BLACK};

	for (int i = 0; i < 2; i++) {
		this->threats[std::make_pair(color[i], FIVE)] /= 5;
		this->threats[std::make_pair(color[i], FOUR)] /= 4;
		this->threats[std::make_pair(color[i], STRAIGHT_FOUR)] /= 4;
		this->threats[std::make_pair(color[i], BROKEN_FOUR)] /= 3;
		this->threats[std::make_pair(color[i], THREE)] /= 3;
		this->threats[std::make_pair(color[i], BROKEN_THREE)] /= 2;
		this->threats[std::make_pair(color[i], TWO_TWO)] /= 2;
		this->threats[std::make_pair(color[i], UNTHREATENED_TWO)] /= 2;
		this->threats[std::make_pair(color[i], THREATENED_TWO)] /= 2;
	}
}

bool Board::isTwoTwo(int x, int y, t_color color, t_orientation ori) {
	if (x < 0 || y < 0|| x >= SIZE || y >= SIZE)
			return (false);
	std::pair<int, int> inc = orientationInc[ori];

	if (this->getPiece(x, y) == EMPTY) {
		x += std::get<0>(inc);
		y += std::get<1>(inc);
		if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
			return (false);
		if (this->getPiece(x, y) == color)
		{
			x += std::get<0>(inc);
			y += std::get<1>(inc);
			if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
				return (false);
			return (this->getPiece(x, y) == color);
		}
		else
			return false;
	}
	else if (this->getPiece(x, y) == color) {
		return (this->isTwoTwo(x + std::get<0>(inc), y + std::get<1>(inc), color, ori));
	}
	return (false);
}

bool Board::isBrokenRow(int x, int y, t_color color, t_orientation ori) {
	if (x < 0 || y < 0|| x >= SIZE || y >= SIZE)
			return (false);
	std::pair<int, int> inc = orientationInc[ori];

	if (this->getPiece(x, y) == EMPTY) {
		x += std::get<0>(inc);
		y += std::get<1>(inc);
		if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
			return (false);
		if (this->getPiece(x, y) == color)
		{
			x += std::get<0>(inc);
			y += std::get<1>(inc);
			if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
				return (false);
			return (this->getPiece(x, y) == EMPTY);
		}
		else
			return false;
	}
	else if (this->getPiece(x, y) == color) {
		return (this->isBrokenRow(x + std::get<0>(inc), y + std::get<1>(inc), color, ori));
	}
	return (false);
}

bool Board::isRowEndingWithType(int x, int y, t_orientation ori, t_color color, t_color typeEnd) {
	std::pair<int, int> inc = orientationInc[ori];

	if (x < 0 || y < 0|| x >= SIZE || y >= SIZE)
			return (false);
	if (this->getPiece(x, y) == typeEnd)
		return (true);
	if (this->getPiece(x, y) != color)
		return (false);
	return (this->isRowEndingWithType(x + std::get<0>(inc), y + std::get<1>(inc), ori, color, typeEnd));
}

int 	Board::evaluateBoard(t_color color) {
	int score = 0;

	if (this->data_[INV(color)]->nbCaptures == 5 || this->data_[INV(color)]->nbCaptures == 6) {
		this->threats[std::make_pair(color, THREATENED_TWO)] -= 400;
		this->threats[std::make_pair(INV(color), THREATENED_TWO)] -= 400;
	}
	for (std::map<std::pair<t_color, t_threat>, int>::iterator iter = this->threatNameAndValues.begin(); iter != this->threatNameAndValues.end(); iter++) {
		if (std::get<0>(iter->first) == color) {
			if (this->threats[std::make_pair(color, std::get<1>(iter->first))] != 0) {
				if (std::get<1>(iter->first) == CAPTURE)
					score += iter->second * (1 + (float)this->data_[color]->nbCaptures / 10);
				else
					score += iter->second;
			}
		}
	}
	if (score == 0) {
		score = SIZE - sqrt(pow(std::get<0>(this->lastMove) - SIZE / 2, 2) + pow(std::get<1>(this->lastMove) - SIZE / 2, 2));;
	}
	return (score);
}


void Board::clearThreats() {
	t_color color[2] = {WHITE, BLACK};

	this->threats.clear();
	for (int i = 0; i < 2; i++) {
		for (std::map<std::pair<t_color, t_threat>, int>::iterator iter = this->threatNameAndValues.begin(); iter != this->threatNameAndValues.end(); iter++) {
			this->threats[std::make_pair(color[i], std::get<1>(iter->first))] = 0;
		}
	}
}

int	 Board::countConnectedPieces(int x, int y, t_color color, t_orientation ori) {
	std::pair<int, int> inc = orientationInc[ori];

	if (x < 0 || y < 0 || x >= SIZE || y >= SIZE || this->getPiece(x, y) != color)
		return (0);
	return (1 + this->countConnectedPieces(x + std::get<0>(inc), y + std::get<1>(inc), color, ori));
}

bool Board::hasXPiecesInRow(int x, int y, int nb) {
	t_color color = this->getPiece(x, y);

	return	(this->countConnectedPieces(x, y, color, SW) + this->countConnectedPieces(x, y, color, NE) - 1 == nb ||
			this->countConnectedPieces(x, y, color, W) + this->countConnectedPieces(x, y, color, E) - 1 == nb ||
			this->countConnectedPieces(x, y, color, N) + this->countConnectedPieces(x, y, color, S) - 1 == nb ||
			this->countConnectedPieces(x, y, color, NW) + this->countConnectedPieces(x, y, color, SE) - 1 == nb);
}

bool Board::isGameFinished(int x, int y) {
	t_color color = this->getPiece(x, y);
	if (this->data_[color]->nbCaptures == 10)
		return true;
	return	(this->countConnectedPieces(x, y, color, SW) + this->countConnectedPieces(x, y, color, NE) - 1 >= 5 ||
			this->countConnectedPieces(x, y, color, W) + this->countConnectedPieces(x, y, color, E) - 1 >= 5 ||
			this->countConnectedPieces(x, y, color, N) + this->countConnectedPieces(x, y, color, S) - 1 >= 5 ||
			this->countConnectedPieces(x, y, color, NW) + this->countConnectedPieces(x, y, color, SE) - 1 >= 5);
}

bool Board::hasAllEmptyAround(int x, int y) {
	for (int yy = -3; yy < 3; yy ++) {
		for (int xx = -3; xx < 3; xx++) {
			if (yy == 0 && xx == 0)
				continue ;
			if (y + yy >= 0 && y + yy < SIZE &&
				x + xx >= 0 && x + xx < SIZE &&
				this->board[y + yy][x + xx] != EMPTY)
				return false;
		}
	}
	return true;
}

/************************************************************************/
/************************      PRINTS		*************************/
/************************************************************************/

void Board::printBoard() {
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			std::cout << this->board[y][x];
		}
		std::cout << std::endl;
	}
}

void Board::printThreats() {
	std::cout << std::endl;
	t_color color;
	std::map<t_threat, std::string> allThreats;
	t_threat threatType;

	int nb;
	allThreats[FIVE] = "FIVE";
	allThreats[THREATENED_TWO] = "THREATENED_TWO";
	allThreats[CAPTURE] = "CAPTURE";
	allThreats[STRAIGHT_FOUR] = "STRAIGHT_FOUR";
	allThreats[BROKEN_FOUR] = "BROKEN_FOUR";
	allThreats[FOUR] = "FOUR";
	allThreats[THREE] = "THREE";
	allThreats[BROKEN_THREE] = "BROKEN_THREE";
	allThreats[UNTHREATENED_TWO] = "UNTHREATENED_TWO";

	for (std::map<std::pair<t_color, t_threat>, int>::iterator iter = this->threats.begin(); iter != this->threats.end(); iter++) {
		color = std::get<0>(iter->first);
		if (color == WHITE) {
			threatType = std::get<1>(iter->first);
			nb = iter->second;
			std::cout <<  "WHITE: "  << allThreats[threatType] << ": " << nb << std::endl;
		}
	}
	std::cout << std::endl;
	for (std::map<std::pair<t_color, t_threat>, int>::iterator iter = this->threats.begin(); iter != this->threats.end(); iter++) {
		color = std::get<0>(iter->first);
		if (color == BLACK) {
			threatType = std::get<1>(iter->first);
			nb = iter->second;
			std::cout <<  "BLACK: "  << allThreats[threatType] << ": " << nb << std::endl;
		}
	}
	std::cout << std::endl;
}

/************************************************************************/
/************************      RECTANGLES		*************************/
/************************************************************************/

void 		Board::computeRectangles(int x, int y) {
	std::vector<Rectangle *>	vec;
	Rectangle					*rect;

	if (this->rectangles.size() == 0) {
		this->rectangles.push_back(new Rectangle(this->win_, x, y));
	} else {
		vec = getConnectedRectangles(x, y);
		if (vec.size() == 0) {
			this->rectangles.push_back(new Rectangle(this->win_, x, y));
		} else if (vec.size() == 1) {
			rect = vec.front();
			rect->resize(x, y, this->getPiece(x, y));
		} else if (vec.size() > 1) {
			this->rectangles.push_back(new Rectangle(this->win_, x, y));
			this->mergeRectangles(vec, x, y);
		}
	}
}

std::vector<Rectangle *> Board::getConnectedRectangles(int x, int y) {
	std::vector<Rectangle *> vec;
	for (std::vector<Rectangle *>::iterator iter = this->rectangles.begin(); iter != this->rectangles.end(); iter++) {
		if ((*iter)->isInsideRectangle(x, y)) {
			vec.push_back(*iter);
		}
	}
	return (vec);
}

void	Board::mergeRectangles(std::vector<Rectangle *> vec, int x, int y) {
	Rectangle *rect;
	int minX, minY, maxX, maxY;

	minX = SIZE;
	minY = SIZE;
	maxX = -1;
	maxY = -1;
	for (std::vector<Rectangle *>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
		if ((*iter)->getTopLeftX() < minX)
			minX = (*iter)->getTopLeftX();
		if ((*iter)->getTopLeftY() < minY)
			minY = (*iter)->getTopLeftY();
		if ((*iter)->getBottomRightY() > maxY)
			maxY = (*iter)->getBottomRightY();
		if ((*iter)->getBottomRightX() > maxX)
			maxX = (*iter)->getBottomRightX();
		this->removeRectangle(*iter);
	}
	rect = new Rectangle(this->win_, x, y);
	rect->bigResize(minX, minY, maxX, maxY);
	this->rectangles.push_back(rect);
	this->mergeRectanglesInside(rect);
}

void 	Board::mergeRectanglesInside(Rectangle *rect) {
	int TLrectX, TLrectY, BRrectX, BRrectY, TLiterX, TLiterY, BRiterX, BRiterY;

	TLrectX = rect->getTopLeftX();
	TLrectY = rect->getTopLeftY();
	BRrectX = rect->getBottomRightX();
	BRrectY = rect->getBottomRightY();
	for (std::vector<Rectangle *>::iterator iter = this->rectangles.begin(); iter != this->rectangles.end(); iter++) {
		if (*iter != rect && (*iter)->hasPieceInside(rect, this->pieces)) {
			TLiterX = (*iter)->getTopLeftX();
			TLiterY = (*iter)->getTopLeftY();
			BRiterX = (*iter)->getBottomRightX();
			BRiterY = (*iter)->getBottomRightY();
			if (TLrectX > TLiterX)
				rect->setTopLeftX(TLiterX);
			if (TLrectY > TLiterY)
				rect->setTopLeftY(TLiterY);
			if (BRrectX < BRiterX)
				rect->setBottomRightX(BRiterX);
			if (BRrectY < BRiterY)
				rect->setBottomRightY(BRiterY);
			removeRectangle(*iter);
			this->mergeRectanglesInside(rect);
			break ;
		}
	}
}

void 	Board::removeRectangle(Rectangle *r1) {
	for (std::vector<Rectangle *>::iterator iter = this->rectangles.begin(); iter != this->rectangles.end(); iter++) {
		if (*iter == r1) {
			this->rectangles.erase(iter);
			break;
		}
	}
}

/************************************************************************/
/************************      INIT 			*************************/
/************************************************************************/

void Board::ClearBoard(void){
	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			board[y][x] = EMPTY;
		}
	}
}

void Board::InitTurn()
{
	std::pair<int,int> ret;
	int x, y;

	if (this->data_[this->curTurn]->type == IA) {
		this->curPieceMouseY_ = -1;
		this->curPieceMouseX_ = -1;
		ret = this->solver_.solve(this, this->curTurn);
		x = std::get<0>(ret) * 70 + PADDING_X - 35;
		y = std::get<1>(ret) * 70 + PADDING_Y - 35;
		this->placePiece(x,y);
	}
}

/************************************************************************/
/************************      MOUSE EVENTS			*************************/
/************************************************************************/

void Board::HandleInput(SDL_Event e)
{
	std::pair<int,int> ret;
	int x, y;

	if (e.key.keysym.scancode == SDL_SCANCODE_P)
	{
		if (this->data_[this->curTurn]->type == MAN)
		{
			this->curPieceMouseY_ = -1;
			this->curPieceMouseX_ = -1;
			ret = this->solver_.solve(this, this->curTurn);
			x = std::get<0>(ret) * 70 + PADDING_X - 35;
			y = std::get<1>(ret) * 70 + PADDING_Y - 35;
			this->placePiece(x,y);
		}
	}
}

void Board::ChoseMode(void){
	this->mode = this->temp_mode_;
	if (this->temp_mode_ == MANVSMAN){
		this->data_[BLACK]->type = MAN;
		this->data_[WHITE]->type = MAN;
	}
	else if (this->mode == MANVSIA){
		this->mode = CHOSE_COLOR;
	}
	else{
		this->data_[WHITE]->type = IA;
		this->data_[BLACK]->type = IA;
	}
}

void Board::ChoseColor(void){
	if (this->temp_color_ == BLACK){
		this->data_[BLACK]->type = MAN;
		this->data_[WHITE]->type = IA;
	}
	else{
		this->data_[BLACK]->type = IA;
		this->data_[WHITE]->type = MAN;
	}
	this->mode = MANVSIA;
}

void Board::RestartGame(void){
	this->curPieceMouseY_ = -1;
	this->curPieceMouseX_ = -1;
	this->curTurn = BLACK;
	Board::threatNameAndValues = init_threatNameAndValues();
	this->data_[WHITE]->nbCaptures = 0;
	this->data_[WHITE]->totalTime = milliseconds(0);
	this->data_[WHITE]->lastTurnTime = milliseconds(0);
	this->data_[BLACK]->nbCaptures = 0;
	this->data_[BLACK]->lastStartTime = Clock::now();
	this->data_[BLACK]->totalTime = milliseconds(0);
	this->data_[BLACK]->lastTurnTime = milliseconds(0);
	this->mode = NOMOD;
	this->temp_mode_ = NOMOD;
	this->ClearBoard();
	this->rectangles.clear();
	this->turn_ = 0;
}

void Board::AutoRestartGame(void){
	t_mode temp;

	temp = this->mode;
	this->RestartGame();
	this->mode = temp;
}

void Board::HandleClick(int x, int y){
	if(this->mode == END)
	{
		if (x > 1800 && y > 1200){
			this->RestartGame();
		}
	}
	else if (this->mode == NOMOD){
		this->ChoseMode();
	}
	else if (this->mode == CHOSE_COLOR){
		this->ChoseColor();
	}
	else {
		if (x > 1800 && y > 1200){
			this->RestartGame();
		}
		else {
			this->placePiece(x, y);
		}
	}
}

void Board::setCurPiecePosition(int mouseX, int mouseY)
{
	int x, y, i, j;

	i = ((mouseX  - PADDING_X + 35) / 70);
	j = ((mouseY  - PADDING_Y + 35) / 70) ;
	x = i * 70 + PADDING_X - 30;
	y = j * 70  + PADDING_Y - 30;
	if (this->data_[this->curTurn]->type != IA && i >= 0 && i < 19 && j >= 0 && j < 19 && this->board[j][i] == EMPTY)
	{
		this->curPieceMouseY_ = y;
		this->curPieceMouseX_ = x;
	}
	else{
		this->curPieceMouseY_ = -1;
		this->curPieceMouseX_ = -1;
	}
}

void Board::lightChosenMode(int x, int y)
{
	if (x < WINDOW_X / 2 && y < 700)
		this->temp_mode_ = MANVSIA;
	else if (x >= WINDOW_X / 2 && y < 700)
		this->temp_mode_ = MANVSMAN;
	else
		this->temp_mode_ = IAVSIA;
}

void Board::lightChosenColor(int x, int y)
{
	if (x < WINDOW_X / 2)
		this->temp_color_ = BLACK;
	else
		this->temp_color_ = WHITE;
}

void Board::HandleMove(int x, int y){

	if (this->mode == NOMOD){
		this->lightChosenMode(x, y);
	}
	else if (this->mode == CHOSE_COLOR){
		this->lightChosenColor(x, y);
	}
	else if (this->mode != END){
		this->setCurPiecePosition(x, y);
	}
}

/************************************************************************/
/************************      GRAPHICS			*************************/
/************************************************************************/

void Board::InitBoard(Window *win) {
	this->ui_ = new UI(this->win_);
	this->ui_->InitStaticTextures();
}

void Board::renderCurPiece()
{
	if (this->curPieceMouseX_ >= PADDING_X - 35 && this->curPieceMouseX_ <= WINDOW_X - PADDING_X + 35)
	{
		if (this->curTurn == BLACK)
			this->renderTextureWithPointer(this->ui_->black_light_, this->curPieceMouseX_, this->curPieceMouseY_);
		else
			this->renderTextureWithPointer(this->ui_->white_light_, this->curPieceMouseX_, this->curPieceMouseY_);
	}
}

void Board::renderPieces(void){
	int i = 0, j = 0;
	int x, y;

	while (i < SIZE)
	{
		j = 0;
		y = i * 70 - 30 + PADDING_Y;
		while (j < SIZE)
		{
			x = j * 70 - 30 + PADDING_X;
			if (this->board[i][j] == BLACK)
				this->renderTextureWithPointer(this->ui_->black_, x, y);
			else if (this->board[i][j] == WHITE)
				this->renderTextureWithPointer(this->ui_->white_, x, y);
			j++;
		}
		i++;
	}
	this->renderCurPiece();
}

void Board::renderRectangles(void){
	for (std::vector<Rectangle *>::iterator iter = this->rectangles.begin(); iter != this->rectangles.end(); iter++) {
		(*iter)->RenderRectangle();
	}
}


void Board::renderGame(void)
{
	this->ui_->renderBackground();
	if (this->mode == END){
		this->ui_->RenderTurn(std::to_string(this->turn_));
		this->renderPieces();
		this->ui_->RenderTextures(this->data_);
		this->ui_->RenderWinner(this->data_, this->winner_);
	}
	else if (this->mode == NOMOD){
		this->ui_->renderMenu(this->temp_mode_);
	}
	else if (this->mode == CHOSE_COLOR)
	{
		this->ui_->RenderChoseColor(this->temp_color_);
	}
	else{
		if (Board::options[DEBUG] == true)
		{
			this->renderRectangles();
		}
		this->renderPieces();
		this->ui_->RenderTurn(std::to_string(this->turn_));
		this->ui_->RenderTextures(this->data_);
	}
}

void Board::freeDynamicTexture()
{
	this->ui_->freeDynamicTexture();
}
