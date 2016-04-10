#include <game_exception.h>

#include "game.h"

Game::Game() {
    initialize();
}

void Game::initialize() {
    SDL_Init(SDL_INIT_VIDEO);
    this->window = SDL_CreateWindow("Fur Blast",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    906, 540,
                                    SDL_WINDOW_SHOWN);
    if (!(this->window)) {
        throw SDLException(SDL_GetError());
    }
    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    this->event = new SDL_Event;
}

void Game::finalize() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
}

Game::~Game() {
    finalize();
}

void Game::mainLoop() {

    while (this->event->type != SDL_QUIT) {
        Uint32 frameTime = SDL_GetTicks();

        SDL_PollEvent(this->event);
        SDL_RenderClear(this->renderer);

        // handle input
        // update game state
        // redraw all

        SDL_RenderPresent(this->renderer);

        if (SDL_GetTicks() - frameTime < MIN_FRAME_RATE) {
            SDL_Delay(MIN_FRAME_RATE - (SDL_GetTicks() - frameTime));
        }
    }

}
