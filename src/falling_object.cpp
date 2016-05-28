#include <iostream>
#include "falling_object.h"

FallingObject::FallingObject(int x, int y, int w, int h)
        : CollidingObject(x, y, w, h) {
    this->isInAir = true;
}

FallingObject::~FallingObject() {

}

void FallingObject::update(float dt, std::list<CollidingObject *> collidingObjects) {
    // TODO: It's not used as velocity but the distance that will be passed by the object
    // during falling. This should be renamed/reimplemented.
    float velocity = float(GRAVITY_ACCELERATION) * dt;
    // TODO: This is not velocity too.
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
    float moveAdjustment = 0;

    for (CollidingObject *object : collidingObjects) {
        // If object will collide with some other object after position change
        // we should adjust the distance to make sure that object will not "stick"
        // in the other object.
        Rectangle *moveBoundariesProjection = new Rectangle(
                this->boundaries->x,
                int(this->boundaries->y + velocity),
                this->boundaries->width,
                this->boundaries->height
        );
        if (object->collidesTop(moveBoundariesProjection)) {
            moveAdjustment = moveBoundariesProjection->y + moveBoundariesProjection->height - object->getBoundaries()->y;
//            if (moveAdjustment > 0) {
//                std::cout << "Adjusting down movement by " << moveAdjustment << std::endl;
//            }
        }

        if (this->collidesBottom(object->getBoundaries())) {
            standsOnOtherObject = true;
            break;
        }
    }

    if (this->hitBottomEnd() || standsOnOtherObject) {
        this->isInAir = false;
    }

    if (this->isInAir) {
        this->moveUp(upVelocity);
        this->moveDown(velocity - moveAdjustment);

//        for (CollidingObject *object : collidingObjects) {
//            if (this->collidesBottom(object->getBoundaries())) {
//                float bottomEndPosition = this->boundaries->y + this->boundaries->height;
//                float verticalPositionAdjustment = bottomEndPosition - object->getBoundaries()->y;
//                this->boundaries->y = this->boundaries->y - verticalPositionAdjustment;
//                break;
//            }
//        }


    } else {
        if (this->hitBottomEnd()) {
            this->boundaries->y = 0;
        }
    }
}

void FallingObject::moveDown(float moveSpeed) {
    if (!this->hitBottomEnd()) {
        this->boundaries->y += moveSpeed;
    }
}

void FallingObject::moveUp(float moveSpeed) {
    if (!this->hitTopEnd()) {
        this->boundaries->y -= moveSpeed;
    }
}


void FallingObject::throwUp() {
    if (!isInAir) { // just cannot jump when there is no ground under the feet
        this->thrownUp = true;
        this->isInAir = true;
    }
}