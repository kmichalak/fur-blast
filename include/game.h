#ifndef FUR_BLAST_GAME_H
#define FUR_BLAST_GAME_H

#include <SDL.h>
#include "state_manager.h"

class Game {

public:
    Game();
    virtual ~Game();
    void mainLoop();
private:
    static const int MIN_FRAME_RATE = 20;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event *event;
    StateManager *stateManager;

    void initialize();
    void finalize();

    Rectangle *boundaries;
};

#endif //FUR_BLAST_GAME_H
