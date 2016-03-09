#include <SDL2/SDL.h>
#include <SDL_image.h>

#include "window.h"

#include "game_exception.h"


GameWindow::GameWindow(unsigned int width, unsigned int height, std::string title) {

  this->resize(width, height, title);

}

void GameWindow::resize(unsigned int width,
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

  SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
}

GameWindow::~GameWindow() {
  destroy();
}

void GameWindow::destroy() {
  if (this->renderer) {
    SDL_DestroyRenderer(this->renderer);
  }

  if (this->window) {
    SDL_DestroyWindow(this->window);
  }

}

void GameWindow::update() {
  SDL_RenderClear(this->renderer);

  // do drawing here
  // ....uhmmm, not really. Drawing should be performed in other place.
  // I need to think about how to create better structure for the game stuff.
  SDL_RenderPresent(this->renderer);
}

void GameWindow::renderImage(SDL_Texture *texture,
                             SDL_Rect *source,
                             SDL_Rect *destination)const {

  SDL_RenderCopy(this->renderer, texture, source, destination);
}

SDL_Texture *GameWindow::loadImage(const char *resourceFile) const {
  return IMG_LoadTexture(this->renderer, resourceFile);
}
