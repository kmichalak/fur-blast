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

  // Handle following keys
  // ESC
  // KEY UP
  // KEY DOWN
  // KEY LEFT
  // KEY RIGHT

  InputManager &manager = InputManager::getInstance();
  if (manager.isKeyPressed(SDL_SCANCODE_LEFT)) {
    this->x--;
  }
  if (manager.isKeyPressed(SDL_SCANCODE_RIGHT)) {
    this->x++;
  }

  this->sprite->render(x, y);

}