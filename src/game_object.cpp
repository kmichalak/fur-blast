#include "game_object.h"

GameObject::GameObject() { }

GameObject::~GameObject() { }

void GameObject::setBoundaries(Rectangle *boundaries) {
  this->boundaries = boundaries;
}

void GameObject::setGameAreaBoundaries(Rectangle *boundaries) {
  this->gameArea = boundaries;
}

bool GameObject::hitRightEnd() {
  return this->gameArea->width <= this->boundaries->x + this->boundaries->width;
}

bool GameObject::hitLeftEnd() {
  return this->gameArea->x >= this->boundaries->x;
}

bool GameObject::hitTopEnd() {
  return this->gameArea->y >= this->boundaries->y;
}

bool GameObject::hitBottomEnd() {
  return this->gameArea->height <= this->boundaries->y + this->boundaries->height;
}

void GameObject::moveRight(float moveSpeed) {
  if (!this->hitRightEnd()) {
    this->boundaries->x += moveSpeed;
  }
}

void GameObject::moveLeft(float moveSpeed) {
  if (!this->hitLeftEnd()) {
    this->boundaries->x -= moveSpeed;
  }
}

void GameObject::moveDown(float moveSpeed) {
  if (!this->hitBottomEnd()) {
    this->boundaries->y += moveSpeed;
  }
}

void GameObject::moveUp(float moveSpeed) {
  if (!this->hitTopEnd()) {
    this->boundaries->y -= moveSpeed;
  }
}