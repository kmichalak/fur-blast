#include "in_game_state.h"
#include "input.h"

InGameState::InGameState() {

}

InGameState::~InGameState() {
    delete this->player;
    delete this->window;
    delete this->gameArea;
}

void InGameState::init(GameWindow *window) {
    this->window = window;
    this->player = new Player(window);
    this->gameArea = window->getBoundaries();
    this->player->setGameAreaBoundaries(this->gameArea);
}

GameState::StateType InGameState::update() {
    handleInput();

    if (this->shouldQuit) {
        return GameState::StateType::QUIT;
    }
    return GameState::StateType::IN_GAME;
}

void InGameState::handleInput() {
    InputManager &input = InputManager::getInstance();
    input.update();

    this->shouldQuit = input.quitRequested();

    if (input.isKeyDown(SDL_SCANCODE_ESCAPE)
        || input.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
        this->shouldQuit = true;
    }
    if (input.isKeyDown(SDL_SCANCODE_F)
        || input.isKeyPressed(SDL_SCANCODE_F)) {
        this->window->toggleFullscreen();
    }

    if (this->player) {
        this->player->update();
    }

}