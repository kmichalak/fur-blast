#include <input.h>
#include <list>
#include <ostream>
#include <iostream>
#include "player.h"

Player::Player(SDL_Renderer *renderer)
        : FallingObject(200, 0, 0, 0) {
    this->sprite = new Sprite("img/h1.png", renderer, true);
    this->setBoundaries(sprite->getBoundaries());
}

Player::~Player() {
    delete this->sprite;
}

void Player::update(std::list<CollidingObject *> collidingObjects) {
    InputManager &manager = InputManager::getInstance();

    if (manager.isKeyPressed(SDL_SCANCODE_LEFT)) {
        bool collidesLeft = false;

        float moveAdjustment = 0;
        for (CollidingObject *object : collidingObjects) {

            Rectangle *moveProjectionBoundaries = new Rectangle(
                    int(this->boundaries->x - MOVE_SPEED),
                    this->boundaries->y,
                    this->boundaries->width,
                    this->boundaries->height
            );

            if (object->collidesRight(moveProjectionBoundaries)) {
                moveAdjustment = object->getRight() - this->getLeft();
                std::cout << "Left collision detected" << std::endl;
            }

            if (this->collidesLeft(object->getBoundaries())) {
                collidesLeft = true;
                break;
            }
        }

        if (!collidesLeft) {
            this->moveLeft(float(MOVE_SPEED - moveAdjustment));
        }
        this->updateFrames(RUN_LEFT_FRAMES);
    }
    if (manager.isKeyPressed(SDL_SCANCODE_RIGHT)) {
        bool collidesRight = false;
        float moveAdjustment = 0;

        for (CollidingObject *object : collidingObjects) {
            Rectangle *moveProjectionBoundaries = new Rectangle(
                    int(this->boundaries->x + MOVE_SPEED),
                    this->boundaries->y,
                    this->boundaries->width,
                    this->boundaries->height
            );
            if (object->collidesLeft(moveProjectionBoundaries)) {
                moveAdjustment = this->getRight() - object->getLeft();
                std::cout << "Right collision detected" << std::endl;
            }

            if (this->collidesRight(object->getBoundaries())) {
                collidesRight = true;
                break;
            }
        }
        if (!collidesRight) {
            this->moveRight(float(MOVE_SPEED - moveAdjustment));
        }
        this->updateFrames(RUN_RIGHT_FRAMES);
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

    FallingObject::update(10, collidingObjects);

}

void Player::updateFrames(int frameRow) {
    int frameCol = int((SDL_GetTicks() / 100) % 4);
    this->sprite->changeFrameCol(frameCol);
    this->sprite->changeFrameRow(frameRow);
}

Sprite *Player::getSprite() {
    return this->sprite;
}

void Player::moveRight(float moveSpeed) {
    if (!this->hitRightEnd()) {
        this->boundaries->x += moveSpeed;
    }
}

void Player::moveLeft(float moveSpeed) {
    if (!this->hitLeftEnd()) {
        this->boundaries->x -= moveSpeed;
    }
}
