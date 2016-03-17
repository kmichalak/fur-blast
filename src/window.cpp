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
                                  width, height,
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

void GameWindow::renderImage(SDL_Texture *texture,
                             SDL_Rect *source,
                             SDL_Rect *destination) {
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, source, destination);
  SDL_RenderPresent(renderer);
}

SDL_Texture *GameWindow::loadImage(const char *resourceFile) {
  return IMG_LoadTexture(renderer, resourceFile);
}

void GameWindow::toggleFullscreen() {
  if (this->isInFullScreen) {
    SDL_SetWindowFullscreen(this->window, 0);
  } else {
    SDL_SetWindowFullscreen(this->window, SDL_WINDOW_FULLSCREEN);
  }
  this->isInFullScreen = !(this->isInFullScreen);
}

Rectangle *GameWindow::getBoundaries() {
  Rectangle *windowBoundaries = new Rectangle(0, 0, 0, 0);
  int width, height;
  SDL_GetWindowSize(this->window, &width, &height);
  windowBoundaries->width = width;
  windowBoundaries->height = height;
  return windowBoundaries;
}
