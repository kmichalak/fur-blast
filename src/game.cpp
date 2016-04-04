#include "game.h"

Game::Game() {
    initialize();
}

void Game::initialize() {
    SDL_Init(SDL_INIT_VIDEO);
    this->window =
}

Game::~Game() {

}

void Game::mainLoop() {
//    int status = SDL_Init(SDL_INIT_VIDEO);
//    if (status == 0) {
//        GameWindow *window = new GameWindow(960, 540, "Fur Blast");
//        StateManager stateManager(window);
//        stateManager.run();
//    }
//    SDL_Quit();
}
