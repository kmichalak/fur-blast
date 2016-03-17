#include <input.h>
#include "player.h"

Player::Player(GameWindow *window) {
  this->sprite = new Sprite("img/h1.png", window);
  this->x = 0;
  this->y = 0;
}

Player::~Player() {
  delete this->sprite;
}

void Player::update() {

  InputManager &manager = InputManager::getInstance();
  if (manager.isKeyPressed(SDL_SCANCODE_LEFT)) {
    this->updateFrames(RUN_LEFT_FRAMES, -MOVE_SPEED);
  } else
  if (manager.isKeyPressed(SDL_SCANCODE_RIGHT)) {
    this->updateFrames(RUN_RIGHT_FRAMES, MOVE_SPEED);
  } else
  {
    // reset animation
    this->sprite->changeFrameCol(3);
  }

  this->sprite->render(int(x), int(y));
}

void Player::updateFrames(int frameRow, double moveSpeed) {
  int frameCol = int((SDL_GetTicks() / 100 ) % 4);
  this->sprite->changeFrameCol(frameCol);
  this->sprite->changeFrameRow(frameRow);
  this->x += moveSpeed;
}
