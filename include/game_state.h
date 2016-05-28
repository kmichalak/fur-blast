#ifndef FUR_BLAST_GAME_STATE_H
#define FUR_BLAST_GAME_STATE_H

#include <iostream>
#include "window.h"
#include "sprite.h"

class GameState {
public:
    enum StateType {
        INITIAL,
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
                destination->x, destination->y,
                destination->width, destination->height
        };
        SDL_RenderCopy(renderer, sprite->getTexture(), &sourceRect, &destinationRect);

        if (sprite->shouldDrawBorders()) {
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

            SDL_SetRenderDrawColor(renderer, 128, 0, 0, 0);
            SDL_RenderDrawLine(
                    renderer,
                    destination->x,
                    destination->y,
                    destination->x + destination->width,
                    destination->y
            );
            SDL_RenderDrawLine(
                    renderer,
                    destination->x + destination->width,
                    destination->y,
                    destination->x + destination->width,
                    destination->y + destination->height
            );
            SDL_RenderDrawLine(
                    renderer,
                    destination->x,
                    destination->y + destination->height,
                    destination->x + destination->width,
                    destination->y + destination->height
            );
            SDL_RenderDrawLine(
                    renderer,
                    destination->x,
                    destination->y,
                    destination->x,
                    destination->y + destination->height
            );
            SDL_SetRenderDrawColor(renderer, r, g, b, a);
        }

    }


};


#endif //FUR_BLAST_GAME_STATE_H
