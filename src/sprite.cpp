#include <SDL2/SDL_image.h>

#include "game_exception.h"
#include "sprite.h"

Sprite::Sprite(const char *resourceFile, SDL_Renderer *renderer, bool containsGameTiles)
        : resourceFile(resourceFile) {

    init(renderer, containsGameTiles);

}

void Sprite::init(SDL_Renderer *renderer, bool containsGameTiles) {

    this->texture = IMG_LoadTexture(renderer, resourceFile);
    if (!(this->texture)) {
        throw SDLException(SDL_GetError());
    }

    int width, height;
    SDL_QueryTexture(this->texture, nullptr, nullptr, &width, &height);

    this->sourceRectangle.x = 0;
    this->sourceRectangle.y = 0;
    this->sourceRectangle.w = containsGameTiles ? width / COLS_NUM : width;
    this->sourceRectangle.h = containsGameTiles ? height / ROWS_NUM : height;
}

Sprite::~Sprite() {
    SDL_DestroyTexture(this->texture);
}

void Sprite::changeFrameRow(int row) {
    this->sourceRectangle.y = sourceRectangle.h * row;
}

void Sprite::changeFrameCol(int col) {
    this->sourceRectangle.x = sourceRectangle.w * col;
}

Rectangle *Sprite::getBoundaries() {
    return new Rectangle(
            this->sourceRectangle.x, this->sourceRectangle.y,
            this->sourceRectangle.w, this->sourceRectangle.h
    );
}

SDL_Texture *Sprite::getTexture() {
    return this->texture;
}

SDL_Rect Sprite::getSourceRect() {
    return this->sourceRectangle;
}
