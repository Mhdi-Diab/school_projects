#ifndef UI_HPP
# define UI_HPP

# include "Window.hpp"
# include "Render.hpp"
# include "Global.hpp"
# include <map>
# include <list>

typedef struct	s_texture{
	SDL_Texture *tex;
	int			x;
	int			y;
}				t_texture;

class UI : public Render{

private:
	SDL_Texture *background_;
	SDL_Texture *grid_;
	SDL_Texture *black_cross_;
	SDL_Texture *userBoard_;
	SDL_Texture *player1_;
	SDL_Texture *player2_;
	SDL_Texture *ia_white_;
	SDL_Texture *ia_;
	SDL_Texture *restart_;
	SDL_Texture *restart_white_;
	SDL_Texture	*win_;
	SDL_Texture	*black_str_black_;
	SDL_Texture	*black_str_white_;
	SDL_Texture	*white_str_black_;
	SDL_Texture	*white_str_white_;
	SDL_Texture	*mania_;
	SDL_Texture	*manman_;
	SDL_Texture	*mania_white_;
	SDL_Texture	*manman_white_;
	SDL_Texture	*iaia_;
	SDL_Texture	*iaia_white_;
	std::list<t_texture *>dynamicTextures;
	void addDynamicTexture(std::string const &file, int x, int y, int fontSize, SDL_Color color);

public:
	UI(Window *win);
	~UI(void);
	SDL_Texture *black_;
	SDL_Texture *black_light_;
	SDL_Texture *white_;
	SDL_Texture *white_light_;
	void RenderTextures(std::map<t_color, t_data*>&data);
	void InitStaticTextures(void);
	void freeDynamicTexture(void);
	void RenderWinner(std::map<t_color, t_data*>&data, t_color winner);
	void RenderChoseColor(t_color color);
	void RenderTurn(std::string const &str);
	void renderBackground(void);
	void renderMenu(t_mode mode);
};

#endif
