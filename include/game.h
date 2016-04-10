#ifndef FUR_BLAST_GAME_H
#define FUR_BLAST_GAME_H

#include <SDL.h>

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

    void initialize();
    void finalize();

};

#endif //FUR_BLAST_GAME_H
