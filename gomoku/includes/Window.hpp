#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <SDL.h>
# include <iostream>

#define PADDING_Y 30
#define PADDING_X 400
#define WINDOW_X (1260 + 2 * PADDING_X)
#define WINDOW_Y (1260 + 2 * PADDING_Y)
class Board;
class Window {

private:
	SDL_Window *win_;
	SDL_Renderer *ren_;
	SDL_Event 	e_;

public:
	Window();
	~Window();
	int Init();
	void Clean();
	bool handleEvents(Board *board);
	SDL_Renderer *getRenderer() const;
	static std::string getResourcePath(const std::string &subDir);
	static void logSDLError(std::ostream &os, const std::string &msg);
};

#endif
