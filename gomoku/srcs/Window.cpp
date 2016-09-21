#include "Window.hpp"
#include "Board.hpp"

Window::Window() {
}

int Window::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		Window::logSDLError(std::cout, "SDL_Init Error:");
		return 1;
	}
	this->win_ = SDL_CreateWindow("Gomoku!", 100, 100, WINDOW_X, WINDOW_Y, SDL_WINDOW_SHOWN);
	if (this->win_ == nullptr){
		Window::logSDLError(std::cout, "SDL_CreateWindow");
		SDL_Quit();
		return 1;
	}

	this->ren_ = SDL_CreateRenderer(this->win_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (this->ren_ == nullptr){
		SDL_DestroyWindow(this->win_);
		Window::logSDLError(std::cout, "SDL_CreateRenderer");
		SDL_Quit();
		return 1;
	}

	if (TTF_Init() != 0){
		Window::logSDLError(std::cout, "TTF_Init");
		SDL_Quit();
		return 1;
	}

	if (SDL_SetRenderDrawBlendMode(this->ren_, SDL_BLENDMODE_BLEND) < 0){
		Window::logSDLError(std::cout, "Blend Mode");
		SDL_Quit();
		return 1;
	}
	return (0);
}


std::string Window::getResourcePath(const std::string &subDir = "") {
	static std::string baseRes;
	if (baseRes.empty()){
		char *basePath = SDL_GetBasePath();
		if (basePath){
			baseRes = basePath;
			SDL_free(basePath);
		}
		else {
			std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
			return "";
		}
	}
	return subDir.empty() ? baseRes : baseRes + subDir + "/";
}

bool Window::handleEvents(Board *board) {
	while (SDL_PollEvent(&this->e_)) {
		switch (this->e_.type)
        {
			case  SDL_QUIT:
				return true;
				break;
			case SDL_MOUSEBUTTONUP:
				board->HandleClick(this->e_.button.x, this->e_.button.y);
				break;
			case SDL_MOUSEMOTION:
				board->HandleMove(this->e_.button.x, this->e_.button.y);
				break;
			case SDL_KEYUP:
				if (this->e_.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					return true;
				else
					board->HandleInput(this->e_);
				break;
		}
	}
	return false;
}

void Window::Clean() {
	SDL_DestroyRenderer(this->ren_);
	SDL_DestroyWindow(this->win_);
	SDL_Quit();
}

void Window::logSDLError(std::ostream &os, const std::string &msg) {
	os << msg << " error: " << SDL_GetError() << std::endl;
}

SDL_Renderer *Window::getRenderer() const {
	return this->ren_;
}
