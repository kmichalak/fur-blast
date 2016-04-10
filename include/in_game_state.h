#ifndef FUR_BLAST_IN_GAME_STATE_H
#define FUR_BLAST_IN_GAME_STATE_H

#include "player.h"
#include "game_state.h"
#include "window.h"
#include "block.h"

#include <list>

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
    std::list<Block*> blocks;
    Rectangle *gameArea;
};

#endif //FUR_BLAST_IN_GAME_STATE_H
