#include <SDL2/SDL.h>

#include "window.h"
#include "game_exception.h"

using namespace furblast;

Window::Window(unsigned int width, unsigned int height, std::string title) {

  this->resize(width, height, title);

}

void Window::resize(unsigned int width,
                    unsigned int height,
                    std::string title) {
  this->window = SDL_CreateWindow(title.c_str(),
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  width,
                                  height,
                                  SDL_WINDOW_SHOWN);
  if (!(this->window)) {
    throw SDLException(SDL_GetError());
  }


  this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
  if (!(this->renderer)) {
    throw SDLException(SDL_GetError());
  }

  SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);

}

Window::~Window() {
  destroy();
}

void Window::destroy() {
  if (this->renderer) {
    SDL_DestroyRenderer(this->renderer);
  }

  if (this->window) {
    SDL_DestroyWindow(this->window);
  }
}

void Window::update() {
  SDL_RenderClear(this->renderer);

  // do drawing here

  SDL_RenderPresent(this->renderer);
}
