#include "UI.hpp"

UI::UI(Window *win): Render(win){
	this->player1_ = nullptr;
	this->player2_ = nullptr;
}

void UI::InitStaticTextures(void)
{
	static const SDL_Color black = { 0, 0, 0, 255 };
	static const SDL_Color white = { 255, 255, 255, 255 };
	this->player1_ = this->loadText("Player 1", "golong.ttf", black, 50);
	this->player2_ = this->loadText("Player 2", "golong.ttf", white, 50);
	this->ia_ = this->loadText("IA", "golong.ttf", black, 50);
	this->ia_white_ = this->loadText("IA", "golong.ttf", white, 50);
	this->restart_ = this->loadText("Restart", "golong.ttf", black, 50);
	this->restart_white_ = this->loadText("Restart", "golong.ttf", white, 50);
	this->win_ = this->loadText("Wins", "golong.ttf", black, 50);
	this->black_str_black_ = this->loadText("Black", "golong.ttf", black, 50);
	this->black_str_white_ = this->loadText("Black", "golong.ttf", white, 50);
	this->white_str_black_ = this->loadText("White", "golong.ttf", black, 50);
	this->white_str_white_ = this->loadText("White", "golong.ttf", white, 50);
	this->grid_ = this->loadTextureWithPointer(this->grid_, "grid.png");
	this->background_ = this->loadTextureWithPointer(this->background_, "wood.jpg");
	this->black_cross_ = this->loadTextureWithPointer(this->black_cross_, "black_cross.png");
	this->mania_ = this->loadTextureWithPointer(this->mania_, "mania.png");
	this->manman_ = this->loadTextureWithPointer(this->manman_, "manman.png");
	this->mania_white_ = this->loadTextureWithPointer(this->mania_white_, "mania_white.png");
	this->manman_white_ = this->loadTextureWithPointer(this->manman_white_, "manman_white.png");
	this->iaia_ = this->loadTextureWithPointer(this->iaia_, "iaia.png");
	this->iaia_white_ = this->loadTextureWithPointer(this->iaia_white_, "iaia_white.png");
	this->black_light_ = this->loadTextureWithPointer(this->black_light_, "black_light.png");
	this->black_ = this->loadTextureWithPointer(this->black_, "black.png");
	this->white_light_ = this->loadTextureWithPointer(this->white_light_, "white_light.png");
	this->white_ = this->loadTextureWithPointer(this->white_, "white.png");
}

void UI::addDynamicTexture(std::string const &file, int x, int y, int fontSize, SDL_Color color)
{
	t_texture *texStruc = new t_texture();
	SDL_Texture *tex  = this->loadText(file, "golong.ttf", color, fontSize);
	texStruc->tex = tex;
	texStruc->x = x;
	texStruc->y = y;
	this->dynamicTextures.push_front(texStruc);
}

void UI::RenderTurn(std::string const &str){
	static const SDL_Color black = { 0, 0, 0, 255 };
	this->addDynamicTexture("Turn " + str, 50, 1200, 50, black);
}

void UI::RenderWinner(std::map<t_color, t_data*>&data, t_color winner){
	if (data[winner]->type == IA){
		this->renderTextureWithPointer(this->ia_, 900, 800);
	}
	else{
		if (winner == BLACK){
			this->renderTextureWithPointer(this->player1_, 800, 800);
		}
		else{
			this->renderTextureWithPointer(this->player2_, 800, 800);
		}
	}
	this->renderTextureWithPointer(this->win_, 1000, 800);
}

void UI::RenderChoseColor(t_color color){
	this->renderTextureWithPointer(this->black_, 700, 400);
	this->renderTextureWithPointer(this->white_, 1200, 400);
	if (color == BLACK)
	{
		this->renderTextureWithPointer(this->black_str_white_, 678, 500);
		this->renderTextureWithPointer(this->white_str_black_, 1170, 500);
	}
	else if (color == WHITE)
	{
		this->renderTextureWithPointer(this->black_str_black_, 678, 500);
		this->renderTextureWithPointer(this->white_str_white_, 1170, 500);
	}
}

void UI::renderMenu(t_mode mode){
	if (mode == MANVSMAN)
	{
		this->renderTextureWithPointer(this->mania_, 508, 300);
		this->renderTextureWithPointer(this->manman_white_, 1040, 300);
		this->renderTextureWithPointer(this->iaia_, 750, 700);
	}
	else if (mode == MANVSIA)
	{
		this->renderTextureWithPointer(this->mania_white_, 508, 300);
		this->renderTextureWithPointer(this->manman_, 1040, 300);
		this->renderTextureWithPointer(this->iaia_, 750, 700);
	}
	else if (mode == IAVSIA)
	{
		this->renderTextureWithPointer(this->mania_, 508, 300);
		this->renderTextureWithPointer(this->manman_, 1040, 300);
		this->renderTextureWithPointer(this->iaia_white_, 750, 700);
	}
}

void UI::renderBackground(void) {
	int w, h, i = 0, j;
	int k = 0;
	SDL_QueryTexture(this->background_, NULL, NULL, &w, &h);
	while (i < WINDOW_X)
	{
		j = 0;
		while (j < WINDOW_Y)
		{
			this->renderTextureWithPointer(this->background_, i, j);
			j += h;
		}
		i += w;
	}
	while (k < NB_GRIDS)
	{
		i = k % 18 * 70 + PADDING_X;
		j = k / 18 * 70 + PADDING_Y;
		this->renderTextureWithPointer(this->grid_, i, j);
		k++;
	}
	this->renderTextureWithPointer(this->black_cross_, 1018, 649);
}

void UI::RenderTextures(std::map<t_color, t_data*>&data){
	SDL_Color color = { 0, 0, 0, 255 };
	if (data[BLACK]->type == IA){
		this->renderTextureWithPointer(this->ia_, 100, 20);
	}
	else{
		this->renderTextureWithPointer(this->player1_, 100, 20);
	}
	if (data[WHITE]->type == IA){
		this->renderTextureWithPointer(this->ia_white_, WINDOW_X - 220, 20);
	}
	else{
		this->renderTextureWithPointer(this->player2_, WINDOW_X - 300, 20);
	}
	this->renderTextureWithPointer(this->restart_, 1800, 1200);
	this->addDynamicTexture("Captures : " + std::to_string(data[BLACK]->nbCaptures), 20, 100, 30, color);
	this->addDynamicTexture("Captures : " + std::to_string(data[WHITE]->nbCaptures), WINDOW_X - PADDING_X + 20, 100, 30, color);
	this->addDynamicTexture("Total Time : " + std::to_string(data[BLACK]->totalTime.count()) + "ms", 20, 200, 30, color);
	this->addDynamicTexture("Total Time : " + std::to_string(data[WHITE]->totalTime.count()) + "ms", WINDOW_X - PADDING_X + 20, 200, 30, color);
	this->addDynamicTexture("Last Turn Time : " + std::to_string(data[BLACK]->lastTurnTime.count()) + "ms", 20, 240, 30, color);
	this->addDynamicTexture("Last Turn Time : " + std::to_string(data[WHITE]->lastTurnTime.count()) + "ms", WINDOW_X - PADDING_X + 20, 240, 30, color);
	for (std::list<t_texture*>::iterator it=this->dynamicTextures.begin(); it != this->dynamicTextures.end(); ++it)
		this->renderTextureWithPointer((*it)->tex, (*it)->x, (*it)->y);
}

void UI::freeDynamicTexture()
{
	for (std::list<t_texture*>::iterator it=this->dynamicTextures.begin(); it != this->dynamicTextures.end(); ++it)
		SDL_DestroyTexture((*it)->tex);
	this->dynamicTextures.clear();
}
