#ifndef FUR_BLAST_BLOCK_H
#define FUR_BLAST_BLOCK_H

#include <SDL.h>
#include "sprite.h"
#include "colliding_object.h"

class Block : public CollidingObject {
public:
    Block(int x, int y, SDL_Renderer *renderer);
    virtual ~Block();
    Sprite *getSprite();

    void mark();

private:
    Sprite *sprite;
};

#endif //FUR_BLAST_BLOCK_H
