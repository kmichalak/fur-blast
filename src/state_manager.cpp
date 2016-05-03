#include <in_game_state.h>
#include "state_manager.h"

StateManager::StateManager(SDL_Renderer *renderer, Rectangle *boundaries) {
    this->gameBoundaries = boundaries;
    this->currentState = new InGameState();
    this->currentState->init(renderer, this->gameBoundaries);

}

StateManager::~StateManager() {
    delete this->currentState;
}

GameState::StateType StateManager::update() {
    return this->currentState->update();
}

void StateManager::draw(SDL_Renderer *renderer) {
    this->currentState->draw(renderer);
}
