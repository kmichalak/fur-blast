#include "block.h"

Block::Block(int x, int y, SDL_Renderer *renderer) {
    this->boundaries = new Rectangle(x, y, 21, 21);
    this->sprite = new Sprite("img/ground.png", renderer, false);
}

Block::~Block() {
    delete this->sprite;
}

Sprite *Block::getSprite() {
    return this->sprite;
}

Rectangle *Block::getBoundaries() {
    return this->boundaries;
}