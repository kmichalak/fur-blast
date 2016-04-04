#include <iostream>
#include "falling_object.h"

FallingObject::FallingObject() {
}

FallingObject::~FallingObject() {

}

void FallingObject::update(float dt) {
    float velocity = float(GRAVITY_ACCELERATION) * dt;
    float upVelocity = 0;

    if (thrownUp) {
        upVelocity = float(
                INITIAL_UP_VELOCITY - (GRAVITY_ACCELERATION * this->lastTimeDelta)
        );
        std::cout << "Up velocity: " << upVelocity << std::endl;
        std::cout << "Last time delta: " << dt << std::endl;
        this->lastTimeDelta += dt / 10;
    }

    if (upVelocity <= 0.01 && thrownUp) {
        thrownUp = false;
        this->lastTimeDelta = 0;
    }

    if (this->hitBottomEnd()) {
        this->isInAir = false;
    }
    this->moveUp(upVelocity);
    this->moveDown(velocity);
}

void FallingObject::throwUp() {
    if (!isInAir) { // just cannot jump when there is no ground under the feet
        this->thrownUp = true;
        this->isInAir = true;
    }
}