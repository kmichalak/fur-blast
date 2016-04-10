#include "in_game_state.h"
#include "input.h"

InGameState::InGameState() {

}

InGameState::~InGameState() {
    delete this->player;
    delete this->gameArea;
}

void InGameState::init(SDL_Renderer *renderer, Rectangle *gameArea) {
    this->player = new Player(renderer);
    this->gameArea = gameArea;
    this->player->setGameAreaBoundaries(this->gameArea);
}

GameState::StateType InGameState::update() {
    handleInput();

    if (this->shouldQuit) {
        return GameState::StateType::QUIT;
    }
    return GameState::StateType::IN_GAME;
}


void InGameState::draw(SDL_Renderer *renderer) {
    Sprite *playerSprite = this->player->getSprite();
    Rectangle *destinationRect = this->player->getBoundaries();
    drawSprite(renderer, playerSprite, destinationRect);
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
//        this->window->toggleFullscreen();
    }

    this->player->update();

}