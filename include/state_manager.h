#ifndef FUR_BLAST_STATE_MANAGER_H
#define FUR_BLAST_STATE_MANAGER_H

#include "window.h"
#include "game_state.h"

class StateManager {
public:
    StateManager(SDL_Renderer *renderer, Rectangle *boundaries);

    virtual ~StateManager();

    void draw(SDL_Renderer *pRenderer);

    GameState::StateType update();
private:
    GameState *currentState;

    Rectangle *gameBoundaries;
};

#endif //FUR_BLAST_STATE_MANAGER_H
