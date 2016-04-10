#ifndef FUR_BLAST_BLOCK_H
#define FUR_BLAST_BLOCK_H

#include <SDL.h>
#include "sprite.h"

class Block {
public:
    Block(int x, int y, SDL_Renderer *renderer);
    virtual ~Block();
    Sprite *getSprite();
    Rectangle *getBoundaries();
private:
    Sprite *sprite;
    Rectangle *boundaries;
};

#endif //FUR_BLAST_BLOCK_H
