#ifndef FUR_BLAST_GAME_STATE_H
#define FUR_BLAST_GAME_STATE_H

#include "window.h"
#include "sprite.h"

class GameState {
public:
    enum StateType {
        QUIT,
        IN_GAME
    };

    virtual ~GameState() { };

    virtual StateType update() = 0;

    virtual void init(SDL_Renderer *renderer, Rectangle *gameArea) = 0;

    virtual void draw(SDL_Renderer *renderer) = 0;

protected:
    virtual void drawSprite(SDL_Renderer *renderer, Sprite *sprite, Rectangle *destination) {
        const SDL_Rect sourceRect = sprite->getSourceRect();
        const SDL_Rect destinationRect = {
                (int) destination->x, (int) destination->y,
                (int) destination->width, (int) destination->height
        };
        SDL_RenderCopy(renderer, sprite->getTexture(), &sourceRect, &destinationRect);
    }


};


#endif //FUR_BLAST_GAME_STATE_H
