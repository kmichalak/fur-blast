#include <iostream>
#include "falling_object.h"

FallingObject::FallingObject(int x, int y, int w, int h)
        : CollidingObject(x, y, w, h) {
    this->isInAir = true;
}

FallingObject::~FallingObject() {

}

void FallingObject::update(float dt, std::list<CollidingObject *> collidingObjects) {
    float velocity = float(GRAVITY_ACCELERATION) * dt;
    float upVelocity = 0;
    this->isInAir = true;

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

    bool standsOnOtherObject = false;
    for (CollidingObject * object : collidingObjects) {
        if (this->collidesBottom(object)) {
            standsOnOtherObject = true;
            break;
        }
    }

    if (this->hitBottomEnd() || standsOnOtherObject) {
        this->isInAir = false;
    }

    if (this->isInAir) {
        this->moveUp(upVelocity);
        this->moveDown(velocity);
    }
}

void FallingObject::throwUp() {
    if (!isInAir) { // just cannot jump when there is no ground under the feet
        this->thrownUp = true;
        this->isInAir = true;
    }
}