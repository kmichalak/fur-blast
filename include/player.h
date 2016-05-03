#ifndef FUR_BLAST_PLAYER_H
#define FUR_BLAST_PLAYER_H

#include <list>
#include <SDL.h>

#include "sprite.h"
#include "window.h"
#include "falling_object.h"

#define RUN_LEFT_FRAMES 0
#define RUN_RIGHT_FRAMES 1
#define MOVE_SPEED 1.3

class Player : public FallingObject {
public:
    Player(SDL_Renderer *renderer);

    virtual ~Player();

    void update(std::list<CollidingObject *> collidingObjects);

    Sprite * getSprite();

private:
    Sprite *sprite;

    void updateFrames(int frameRow);
};

#endif //FUR_BLAST_PLAYER_H
