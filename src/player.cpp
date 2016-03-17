#include <input.h>
#include "player.h"

Player::Player(GameWindow *window) {
  this->sprite = new Sprite("img/h1.png", window);
  this->setBoundaries(sprite->getBoundaries());
}

Player::~Player() {
  delete this->sprite;
}

void Player::update() {
  InputManager &manager = InputManager::getInstance();
  if (manager.isKeyPressed(SDL_SCANCODE_LEFT)) {
    this->updateFrames(RUN_LEFT_FRAMES);
    if (!this->hitLeftEnd()) {
      this->boundaries->x -= MOVE_SPEED;
    }
  }
  if (manager.isKeyPressed(SDL_SCANCODE_RIGHT)) {
    this->updateFrames(RUN_RIGHT_FRAMES);
    if (!this->hitRightEnd()) {
      this->boundaries->x += MOVE_SPEED;
    }
  }
  if (manager.isKeyPressed(SDL_SCANCODE_UP)) {
    if (!this->hitTopEnd()) {
      this->boundaries->y -= MOVE_SPEED;
    }
  }
  if (manager.isKeyPressed(SDL_SCANCODE_DOWN)) {
    if (!this->hitBottomEnd()) {
      this->boundaries->y += MOVE_SPEED;
    }
  }

  if ((manager.isKeyUp(SDL_SCANCODE_LEFT)
       || !manager.isKeyPressed(SDL_SCANCODE_LEFT))
      && (manager.isKeyUp(SDL_SCANCODE_RIGHT)
          || !manager.isKeyPressed(SDL_SCANCODE_RIGHT))
      && (manager.isKeyUp(SDL_SCANCODE_UP)
          || !manager.isKeyPressed(SDL_SCANCODE_UP))
      && (manager.isKeyUp(SDL_SCANCODE_DOWN)
          || !manager.isKeyPressed(SDL_SCANCODE_DOWN))) {
    this->sprite->changeFrameCol(3);
  }

  this->sprite->render(int(this->boundaries->x), int(this->boundaries->y));
}

void Player::updateFrames(int frameRow) {
  int frameCol = int((SDL_GetTicks() / 100) % 4);
  this->sprite->changeFrameCol(frameCol);
  this->sprite->changeFrameRow(frameRow);
}
