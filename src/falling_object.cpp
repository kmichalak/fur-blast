#include <iostream>
#include "falling_object.h"

FallingObject::FallingObject() {
}

FallingObject::~FallingObject() {

}

void FallingObject::update(float dt) {
  this->velocity = this->acceleration * dt ;// 100;

  this->upVelocity = 1 - this->velocity * dt ;// 100;
  if (this->upVelocity > 0) {
    this->upVelocity = 0;
  }

  float currentVelocity = this->velocity - this->upVelocity;

//  std::cout << currentVelocity << std::endl;
  this->moveDown(currentVelocity);
}

void FallingObject::throwUp(float dt) {
  // Current velocity depends on the current time delta and initial velocity
  // so v = v0 - a*dt
  // Initial velocity is always 1.
  this->upVelocity = -1;
}