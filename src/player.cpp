#include <input.h>
#include <list>
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
    CollidingObject *collidingObject;

    if (manager.isKeyPressed(SDL_SCANCODE_LEFT)) {
        bool collidesLeft = false;

        for (CollidingObject *object : collidingObjects) {

            if (this->collidesLeft(object)) {
                collidingObject = object;
                collidesLeft = true;
                break;
            }
        }

        if (!collidesLeft) {
            this->moveLeft(MOVE_SPEED);
        }
        else {
            do {
                moveRight(1);
            } while (this->collidesLeft(collidingObject));
//            float d = this->getBoundaries()->x - collidingObject->getBoundaries()->x;
//            if (d > 0) {
//                this->moveRight(getBoundaries()->width - d);
//            }
        }
        this->updateFrames(RUN_LEFT_FRAMES);
    }
    if (manager.isKeyPressed(SDL_SCANCODE_RIGHT)) {
        bool collidesRight = false;
        for (CollidingObject *object : collidingObjects) {
            if (this->collidesRight(object)) {
                collidingObject = object;
                collidesRight = true;
                break;
            }
        }
        if (!collidesRight) {
            this->moveRight(MOVE_SPEED);
        } else {
            while(this->collidesRight(collidingObject)) {
                this->moveLeft(1);
            }
            float d = collidingObject->getBoundaries()->x - this->getBoundaries()->x;
            this->moveLeft(getBoundaries()->width - d);
        }
        this->updateFrames(RUN_RIGHT_FRAMES);
    }




//    if (manager.isKeyPressed(SDL_SCANCODE_UP)) {
//        if (!this->hitTopEnd()) {
////            this->throwUp();
//        }
//    }
//    if (manager.isKeyPressed(SDL_SCANCODE_DOWN)) {
//        if (!this->hitBottomEnd()) {
//            this->boundaries->y += MOVE_SPEED;
//        }
//    }

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
