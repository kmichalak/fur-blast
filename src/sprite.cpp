#include <SDL2/SDL_image.h>

#include "game_exception.h"
#include "sprite.h"

Sprite::Sprite(const char *resourceFile, GameWindow *window)
    : resourceFile(resourceFile),
      window(window) {

  init();

}

void Sprite::init() {
  this->texture = this->window->loadImage(this->resourceFile);
  if (!(this->texture)) {
    throw SDLException(SDL_GetError());
  }

  int width, height;
  SDL_QueryTexture(this->texture, nullptr, nullptr, &width, &height);

  this->sourceRectangle.x = 0;
  this->sourceRectangle.y = 0;
  this->sourceRectangle.w = width / COLS_NUM;
  this->sourceRectangle.h = height / ROWS_NUM;
}

Sprite::~Sprite() {
  SDL_DestroyTexture(this->texture);
}

void Sprite::render(int x, int y) {
  this->sourceRectangle.x = 0;
  this->sourceRectangle.y = 0;

  SDL_Rect source = this->sourceRectangle;
  SDL_Rect destination = {
      x, y,
      this->sourceRectangle.h, this->sourceRectangle.w
  };
  window->renderImage(this->texture, &source, &destination);
}
