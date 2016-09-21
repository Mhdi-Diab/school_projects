#ifndef RENDER_HPP
# define RENDER_HPP

# include <iostream>
# include "Window.hpp"
# include "SDL_image.h"
# include "SDL_ttf.h"

class Render {


protected:
	SDL_Texture *texture_;
	SDL_Surface *surface_;
	Window *win_;

public:
	Render(Window *win);
	~Render(void){};
	Window *getWindow(void) const;
	SDL_Texture* loadTexture(const std::string &file);
	SDL_Texture* loadTextureWithPointer(SDL_Texture *tex, const std::string &file);
	void renderTexture(int x, int y);
	void renderTextureWithPointer(SDL_Texture *tex, int x, int y);
	SDL_Texture* loadText(const std::string &message,
		const std::string &fontFile, SDL_Color color, int fontSize);

};

#endif
