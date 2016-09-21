#include "Render.hpp"

Render::Render(Window *win): win_(win) {
	this->texture_ = nullptr;
	this->surface_ = nullptr;
}

SDL_Texture* Render::loadTexture(const std::string &file) {
	this->texture_ = nullptr;
	this->surface_ = IMG_Load((Window::getResourcePath("images") + file).c_str() );

	if (this->surface_ != nullptr){
		this->texture_ = SDL_CreateTextureFromSurface(this->win_->getRenderer(), this->surface_);
		SDL_FreeSurface(this->surface_);
		if (this->texture_ == nullptr){
			Window::logSDLError(std::cout, "CreateTextureFromSurface");
		}
	}
	else {
		Window::logSDLError(std::cout, "Load Image");
	}
	return this->texture_;
}

SDL_Texture* Render::loadTextureWithPointer(SDL_Texture *tex, const std::string &file) {
	SDL_Surface *sur;
	tex = nullptr;
	sur = IMG_Load((Window::getResourcePath("images") + file).c_str() );
	if (sur != nullptr){
		tex = SDL_CreateTextureFromSurface(this->win_->getRenderer(), sur);
		SDL_FreeSurface(sur);
		if (tex == nullptr){
			Window::logSDLError(std::cout, "CreateTextureFromSurface");
		}
	}
	else {
		Window::logSDLError(std::cout, "Load Image");
	}
	return tex;
}

void Render::renderTexture(int x, int y) {
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use
	SDL_QueryTexture(this->texture_, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(this->win_->getRenderer(), this->texture_, NULL, &dst);
}

void Render::renderTextureWithPointer(SDL_Texture *tex, int x, int y) {
	//Setup the destination rectangle to be at the position we want
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	//Query the texture to get its width and height to use
	SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(this->win_->getRenderer(), tex, NULL, &dst);
}

SDL_Texture* Render::loadText(const std::string &message,
	const std::string &fontFile, SDL_Color color, int fontSize)
{
	//Open the font
	TTF_Font *font = TTF_OpenFont((Window::getResourcePath("fonts") + fontFile).c_str(), fontSize);
	if (font == nullptr){
		Window::logSDLError(std::cout, "TTF_OpenFont");
		return nullptr;
	}
	//We need to first render to a surface as that's what TTF_RenderText
	//returns, then load that surface into a texture
	SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
	if (surf == nullptr){
		TTF_CloseFont(font);
		Window::logSDLError(std::cout, "TTF_RenderText");
		return nullptr;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(this->win_->getRenderer(), surf);
	if (texture == nullptr){
		Window::logSDLError(std::cout, "CreateTexture");
	}
	//Clean up the surface and font
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return texture;
}

Window *Render::getWindow(void) const {
	return this->win_;
}
