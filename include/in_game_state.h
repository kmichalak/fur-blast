#ifndef FUR_BLAST_IN_GAME_STATE_H
#define FUR_BLAST_IN_GAME_STATE_H

#include "player.h"
#include "game_state.h"
#include "window.h"

class InGameState : public GameState {
public:
    InGameState();

    virtual ~InGameState();

    void init(SDL_Renderer *renderer, Rectangle *gameArea);

    virtual StateType update();

    virtual void draw(SDL_Renderer *renderer);

private:
    bool shouldQuit;

    void handleInput();

    Player *player;
    Rectangle *gameArea;
};

#endif //FUR_BLAST_IN_GAME_STATE_H
